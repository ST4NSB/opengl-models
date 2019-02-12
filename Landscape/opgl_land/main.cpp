#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glaux.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "legacy_stdio_definitions.lib")
#pragma warning(disable:4996) // pt erori la fopen(unsafe function)

#include "glos.h"
#include "glee.h"
#include "math3d.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#pragma pack(1)
typedef struct
{
	GLbyte	identsize;              // Size of ID field that follows header (0)
	GLbyte	colorMapType;           // 0 = None, 1 = paletted
	GLbyte	imageType;              // 0 = none, 1 = indexed, 2 = rgb, 3 = grey, +8=rle
	unsigned short	colorMapStart;          // First colour map entry
	unsigned short	colorMapLength;         // Number of colors
	unsigned char 	colorMapBits;   // bits per palette entry
	unsigned short	xstart;                 // image x origin
	unsigned short	ystart;                 // image y origin
	unsigned short	width;                  // width in pixels
	unsigned short	height;                 // height in pixels
	GLbyte	bits;                   // bits per pixel (8 16, 24, 32)
	GLbyte	descriptor;             // image descriptor
} TGAHEADER;
#pragma pack(8)

#define GROUND_TEXTURE	0
#define WATER_TEXTURE	1	
#define NUM_TEXTURES	2
GLuint  textureObjects[NUM_TEXTURES];

// Light and material Data
GLfloat fLightPos[4] = { -100.0f, 100.0f, 50.0f, 1.0f };  // Point source
GLfloat fNoLight[] = { 0.0f, 0.0f, 0.0f, 0.0f };
GLfloat fLowLight[] = { 0.21f, 0.55f, 0.88f, 1.0f };
GLfloat fBrightLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };

const char *szTextureFiles[] = { "grass.tga", "water.tga" };
const int X_TREE_AXIS_SIZE = 29, NOT_USABLE = -1000, NUMBER_OF_TREES = 7;
GLfloat zoom = 0.0, zoomProcent = 4.0f, waterAlpha = 0.7f;
int zoomState = 0; // 0 - primu cadru, 1 - al doilea cadru
const char *treeListOfNames[NUMBER_OF_TREES];
int xTreeCoord[NUMBER_OF_TREES], xTestArray[X_TREE_AXIS_SIZE];
int yTreeCoord[NUMBER_OF_TREES], yTestArray[2] = { 8, 10 };
bool randomTreeProcedureGeneratorIsDone = false;

void myinit(void);
void CALLBACK myReshape(GLsizei w, GLsizei h);
void CALLBACK display(void);

void CALLBACK zoomIn(void)
{
	if (zoomState == 1)
	{
		zoomState = 0;
		zoom = zoomProcent;
	}
	else zoom = 0.0f;
}

void CALLBACK zoomOut(void)
{
	if (zoomState == 0)
	{
		zoomState = 1;
		zoom = -zoomProcent;
	}
	else zoom = 0.0f;
}

void CALLBACK waterAlphaPlus(void)
{
	const float maxValue = 1.0f;
	waterAlpha += 0.1f;
	if (waterAlpha >= maxValue)
		waterAlpha = maxValue;
	zoom = 0.0f;
}
void CALLBACK waterAlphaMinus(void)
{
	const float minValue = 0.5f;
	waterAlpha -= 0.1f;
	if (waterAlpha <= minValue)
		waterAlpha = minValue;
	zoom = 0.0f;
}

GLbyte *gltLoadTGA(const char *szFileName, GLint *iWidth, GLint *iHeight, GLint *iComponents, GLenum *eFormat)
{
	FILE *pFile;			// File pointer
	TGAHEADER tgaHeader;		// TGA file header
	unsigned long lImageSize;		// Size in bytes of image
	short sDepth;			// Pixel depth;
	GLbyte	*pBits = NULL;          // Pointer to bits

									// Default/Failed values
	*iWidth = 0;
	*iHeight = 0;
	*eFormat = GL_BGR_EXT;
	*iComponents = GL_RGB8;

	// Attempt to open the file
	pFile = fopen(szFileName, "rb");
	if (pFile == NULL)
		return NULL;

	// Read in header (binary)
	fread(&tgaHeader, sizeof(TGAHEADER), 1, pFile);

	// Get width, height, and depth of texture
	*iWidth = tgaHeader.width;
	*iHeight = tgaHeader.height;
	sDepth = tgaHeader.bits / 8;
	printf("a citit fisierul %d\n", tgaHeader.height);
	// Put some validity checks here. Very simply, I only understand
	// or care about 8, 24, or 32 bit targa's.
	if (tgaHeader.bits != 8 && tgaHeader.bits != 24 && tgaHeader.bits != 32)
		return NULL;

	// Calculate size of image buffer
	lImageSize = tgaHeader.width * tgaHeader.height * sDepth;
	printf("a citit fisierul %d\n", lImageSize);
	// Allocate memory and check for success
	pBits = (GLbyte*)malloc(lImageSize * sizeof(GLbyte));
	if (pBits == NULL)
		return NULL;

	// Read in the bits
	// Check for read error. This should catch RLE or other 
	// weird formats that I don't want to recognize
	if (fread(pBits, lImageSize, 1, pFile) != 1)
	{
		free(pBits);
		return NULL;
	}

	printf("sDepth: %u\n", sDepth);
	// Set OpenGL format expected
	switch (sDepth)
	{
	case 3:     // Most likely case
		*eFormat = GL_BGR_EXT;
		*iComponents = GL_RGB8;
		break;
	case 4:
		*eFormat = GL_BGRA_EXT;
		*iComponents = GL_RGBA8;
		break;
	case 1:
		*eFormat = GL_LUMINANCE;
		*iComponents = GL_LUMINANCE8;
		break;
	};

	// Done with File
	fclose(pFile);

	// Return pointer to image data
	return pBits;
}

void myinit()
{
	glClearColor(fLowLight[0], fLowLight[1], fLowLight[2], fLowLight[3]);

	// punem valorile de la -10 pana la 18
	int val = -10;
	for (int i = 0; i < X_TREE_AXIS_SIZE; i++)
	{
		xTestArray[i] = val;
		val++;
	}

	// Setup light parameters
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, fNoLight);
	glLightfv(GL_LIGHT0, GL_AMBIENT, fLowLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, fBrightLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, fBrightLight);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL, GL_SEPARATE_SPECULAR_COLOR);

	// Mostly use material tracking
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glMaterialfv(GL_FRONT, GL_SPECULAR, fBrightLight);
	glMateriali(GL_FRONT, GL_SHININESS, 128);

	// Set up texture maps
	glEnable(GL_TEXTURE_2D);
	glGenTextures(NUM_TEXTURES, textureObjects);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);


	for (int i = 0; i < NUM_TEXTURES; i++)
	{
		GLbyte *pBytes;
		GLint iWidth, iHeight, iComponents;
		GLenum eFormat;

		glBindTexture(GL_TEXTURE_2D, textureObjects[i]);

		// Load this texture map
		pBytes = gltLoadTGA(szTextureFiles[i], &iWidth, &iHeight, &iComponents, &eFormat);
		gluBuild2DMipmaps(GL_TEXTURE_2D, iComponents, iWidth, iHeight, eFormat, GL_UNSIGNED_BYTE, pBytes);
		free(pBytes);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	}

	glClearStencil(0x0);
}

void treeSettings(const char *treeName, int reflectionType, GLint iHeight, GLint iWidth, int rx, int ry)
{
	GLfloat xScalingFactor, yScalingFactor, xRaster, yRaster;
	GLfloat xReflection = 12.0f, yReflection = 2.0f;

	if (zoomState == 0)
	{
		xScalingFactor = yScalingFactor = 0.7f;
		xRaster = 0.0f;
		yRaster = 0.0f;
	}
	else if (zoomState == 1)
	{
		xScalingFactor = yScalingFactor = 0.6f;
		if (rx < 2.0f)
			xRaster = 1.0f;
		else xRaster = 0.0f;
		yRaster = 1.0f;
	}
	if (treeName == "tree2.tga")
	{
		yScalingFactor -= 0.1f;
	}
	if (reflectionType == 1)
	{
		yScalingFactor -= 0.1f;
		glPixelZoom(-xScalingFactor, -yScalingFactor);
		glRasterPos2i(iWidth, iHeight);
		if (ry > 8)
			yRaster = 1.0f;
		else yRaster = 0.0f;
		glRasterPos2i(rx + xReflection + xRaster, ry + yReflection - yRaster);
	}
	else if (reflectionType == 0)
	{
		glPixelZoom(xScalingFactor, yScalingFactor);
		glRasterPos2i(iWidth, iHeight);
		glRasterPos2i(rx + xRaster, ry + yRaster);
	}
}
void computeTree(int reflectionType, const char *treeName, int rx, int ry)
{
	GLbyte *pImage = NULL;
	GLint iWidth, iHeight, iComponents;
	GLenum eFormat;
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	// Targa's are 1 byte aligned
	pImage = gltLoadTGA(treeName, &iWidth, &iHeight, &iComponents, &eFormat);
	treeSettings(treeName, reflectionType, iWidth, iHeight, rx, ry);
	// Draw the pixmap
	if (pImage != NULL)
		glDrawPixels(iWidth, iHeight, eFormat, GL_UNSIGNED_BYTE, pImage);
	// Don't need the image data anymore
	free(pImage);
}
bool isValueUniqueInArray(int xRandom)
{
	if (xTestArray[xRandom] == NOT_USABLE)
		return false;
	else return true;
}

void setTreePosition(int reflectionType)
{
	int xRandom, yRandom, treeRandom;
	const char *triName;
	int k = 0;
	if (!randomTreeProcedureGeneratorIsDone)
	{
		for (int i = 0; i < NUMBER_OF_TREES; i++)
		{
			yRandom = rand() % 6 + 1;
			if (yRandom <= 3)
				yRandom = 0;
			else yRandom = 1;
			treeRandom = rand() % 6 + 1;
			if (treeRandom <= 2 || yRandom == 0)
				triName = "tree.tga";
			else triName = "tree2.tga";
			do {
				xRandom = rand() % X_TREE_AXIS_SIZE;
			} while (!isValueUniqueInArray(xRandom));
			xTreeCoord[k] = xTestArray[xRandom];
			yTreeCoord[k] = yTestArray[yRandom];
			treeListOfNames[k] = triName;
			k++;
			xTestArray[xRandom] = NOT_USABLE;
		}
		randomTreeProcedureGeneratorIsDone = true;
	}
	for (int i = 0; i < NUMBER_OF_TREES; i++)
	{
		if (yTreeCoord[i] == yTestArray[1]) // pune copacii din spate mai intai
			computeTree(reflectionType, treeListOfNames[i], xTreeCoord[i], yTreeCoord[i]);
	}
	for (int i = 0; i < NUMBER_OF_TREES; i++)
	{
		if (yTreeCoord[i] == yTestArray[0])
			computeTree(reflectionType, treeListOfNames[i], xTreeCoord[i], yTreeCoord[i]);
	}

}

void drawTree(int reflectionType)
{
	glPushMatrix();
	glTranslatef(-10, -10, -40);
	setTreePosition(reflectionType);
	glPopMatrix();
}

void drawEllipse(void)
{
	GLfloat radiusX = 3.5, radiusY = 2.5;
	GLfloat PIRAD = 3.14159 / 180.0;

	GLfloat texStep = 1.0f / (PIRAD * .075f);

	glBindTexture(GL_TEXTURE_2D, textureObjects[WATER_TEXTURE]);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i<360; i++)
	{
		float rad = i*PIRAD;

		glTexCoord2f(cos(rad)*radiusX, sin(rad)*radiusY);
		glNormal3f(0.0f, 1.0f, 0.0f);
		glVertex3f(cos(rad)*radiusX, sin(rad)*radiusY, 0.5);
	}
	glEnd();
}

void drawLake(void)
{
	glPushMatrix();
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glRotatef(9.0, 1.0, 0.0, 0.0);
	glColor4f(0.3f, 0.8f, 0.4f, waterAlpha); // 0.4 - 1.0
	drawEllipse();
	glPopMatrix();
}

void drawGround(void)
{
	GLfloat fExtent = 20.0f;
	GLfloat fStep = 0.6f; 
	GLfloat y = -0.5f;
	GLfloat iStrip, iRun;
	GLfloat s = 0.0f;
	GLfloat t = 0.0f;
	GLfloat texStep = 1.0f / (fExtent * .075f);

	glBindTexture(GL_TEXTURE_2D, textureObjects[GROUND_TEXTURE]);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glPushMatrix();
	glRotatef(9.0, 1.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	for (iStrip = -fExtent; iStrip <= fExtent; iStrip += fStep)
	{
		t = 0.0f;
		glBegin(GL_TRIANGLE_STRIP);
		for (iRun = fExtent; iRun >= -fExtent; iRun -= fStep)
		{
			//glColor4f(0.0f, 0.7f, 0.0f, 1.0f);
			glColor3f(0.0f, 0.95f, 0.0f);

			glTexCoord2f(s, t);
			glNormal3f(0.0f, 1.0f, 0.0f);
			glVertex3f(iStrip, y, iRun);

			glTexCoord2f(s + texStep, t);
			glNormal3f(0.0f, 1.0f, 0.0f);   
			glVertex3f(iStrip + fStep, y, iRun);
			t += texStep;
		}
		glEnd();
		s += texStep;
	}
	glShadeModel(GL_SMOOTH);
	glPopMatrix();
}


void CALLBACK display(void)
{
	// Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	glTranslatef(0, 0, zoom);
	//glTranslatef(0, 0, -40);
	//glRotatef(90, 1, 0, 0);

	glEnable(GL_STENCIL_TEST);
	glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);//inactivarea desenarii in buffer-ul de culoare

	glStencilFunc(GL_ALWAYS, 0x01, 0x01);
	glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE);
	drawGround();

	glStencilFunc(GL_ALWAYS, 0x00, 0x01);
	glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE);
	drawLake();

	glLightfv(GL_LIGHT0, GL_POSITION, fLightPos);
	glStencilFunc(GL_EQUAL, 0x01, 0x03);
	glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
	glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
	glEnable(GL_TEXTURE_2D);
		drawGround();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);

	glPushMatrix();
		glPushMatrix();
			glScalef(1.0f, 5.0f, 1.0f);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glStencilFunc(GL_NOTEQUAL, 0x01, 0x01);
			glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
				drawTree(1);
			glDisable(GL_BLEND);
		glPopMatrix();
		glDisable(GL_STENCIL_TEST);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_TEXTURE_2D);
			drawLake();
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_BLEND);

		glEnable(GL_LIGHTING);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			drawTree(0);
		glDisable(GL_BLEND);
		glDisable(GL_LIGHTING);
	glPopMatrix();
	
	// Do the buffer Swap
	auxSwapBuffers();
}


void CALLBACK myReshape(GLsizei w, GLsizei h)
{
	GLfloat fAspect;
	if (h == 0)
		h = 1;

	glViewport(0, 0, w, h);

	fAspect = (GLfloat)w / (GLfloat)h;

	// se reseteaza matricea de proiectie la inceput
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// volumul de vizualizare
	gluPerspective(35.0f, fAspect, 1.0f, 50.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void ShutdownRC(void)
{
	// Delete the textures
	glDeleteTextures(NUM_TEXTURES, textureObjects);
}

int main(int argc, char* argv[])
{
	srand(time(NULL));

	auxInitDisplayMode(AUX_DOUBLE | AUX_RGB | AUX_DEPTH | AUX_STENCIL);
	auxInitPosition(50, 50, 1300, 800);
	auxInitWindow("OpenGL Landscape");

	myinit();
	auxKeyFunc(AUX_LEFT, waterAlphaMinus);
	auxKeyFunc(AUX_RIGHT, waterAlphaPlus);
	auxKeyFunc(AUX_UP, zoomIn);
	auxKeyFunc(AUX_DOWN, zoomOut);
	auxReshapeFunc(myReshape);
	auxMainLoop(display);
	ShutdownRC();

	return(0);
}

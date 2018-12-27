#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glaux.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glut32.lib")
#pragma warning(disable:4996)

#include "glos.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>

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

void myinit(void);

void CALLBACK myReshape(GLsizei w, GLsizei h);
void CALLBACK display(void);
////////////////////////////////////////////////////////////////////
// Allocate memory and load targa bits. Returns pointer to new buffer,
// height, and width of texture, and the OpenGL format of data.
// Call free() on buffer when finished!
// This only works on pretty vanilla targas... 8, 24, or 32 bit color
// only, no palettes, no RLE encoding.


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
	printf("sDepth: %u\n", sDepth);
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
	// Black background
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}


void drawTree(int rx, int ry, int rz)
{
	GLbyte *pImage = NULL;
	GLbyte *pImage1 = NULL;
	GLint iWidth, iHeight, iComponents;
	GLenum eFormat;
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	// Targa's are 1 byte aligned
	pImage = gltLoadTGA("tree.tga", &iWidth, &iHeight, &iComponents, &eFormat);
	glRasterPos3i(rx, ry, rz);
	// Draw the pixmap
	if (pImage != NULL)
		glDrawPixels(iWidth, iHeight, eFormat, GL_UNSIGNED_BYTE, pImage);
	// Don't need the image data anymore
	free(pImage);
}

///////////////////////////////////////////////////////////////////////        
// Called to draw scene
void CALLBACK display(void)
{
	

	// Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
		// aici desenam copacii
		drawTree(0, 0, 0);
		drawTree(500, 0, 0);
	glDisable(GL_BLEND);


	


	// Do the buffer Swap
	auxSwapBuffers();
}


//////////////////////////////////////////////////////////////
// For this example, it really doesn't matter what the 
// projection is since we are using glWindowPos
void CALLBACK myReshape(GLsizei w, GLsizei h)
{
	
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;

	glViewport(0, 0, w, h);

	// Reset the coordinate system before modifying
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Set the clipping volume
	gluOrtho2D(0.0f, (GLfloat)w, 0.0, (GLfloat)h);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	/*	if (!h) return;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity(); */
}

/////////////////////////////////////////////////////////////
// Main program entrypoint
int main(int argc, char* argv[])
{
	auxInitDisplayMode(AUX_DOUBLE | AUX_RGB | AUX_DEPTH);
	auxInitPosition(50, 50, 1150, 750);
	auxInitWindow("OpenGL Landscape");
	myinit();
	auxReshapeFunc(myReshape);
	auxMainLoop(display);
	return(0);
}

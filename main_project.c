#include "glos.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>

void myinit(void);
void CALLBACK display(void);
void CALLBACK myReshape(GLsizei w, GLsizei h);

static int moveSpeed = 10, umbra = 0;
static GLfloat xAng = 0, yAng = 90, zAng = -8.0, yAnim = 0.1;
GLfloat position[] = { -1.5, 12.8, -8.0, 1.0 };
GLfloat position_umbra[] = { -1.5, 12.8, -8.0, 1.0 };

GLfloat ctrlpoints[4][4][3] = {
	{ { -2.4, -0.5, 0.5 },{ -2.0, -3.0, 0.5 },{ 2.0, -3.0, 0.5 },{ 2.4, -0.5, 0.5 } },
	{ { -2.5, -1.0, 0.5 },{ -2.2, -3.0, 5.0 },{ 2.2, -3.0, 5.0 },{ 2.5, -1.0, 0.5 } },
	{ { -2.5, 1.0, 0.5 },{ -2.2, 3.0, 5.0 },{ 2.2, 3.0, 5.0 },{ 2.5, 1.0, 0.5 } },
	{ { -2.4, 0.5, 0.5 },{ -2.0, 3.0, 0.5 },{ 2.0, 3.0, 0.5 },{ 2.4, 0.5, 0.5 } }
};
GLfloat ctrlpoints2[4][3] = {
	{ -4.1, 0.7, 0.0 },{ -2.5, -2.0, 0.0 },{ -1.0, -2.0 , 0.0 },{ 0.7, 0.7, 0.0 }
};

// functii de invartire
void CALLBACK MutaStanga(void) {
	xAng -= moveSpeed;
}
void CALLBACK MutaDreapta(void) {
	xAng += moveSpeed;
}
void CALLBACK MutaSus(void)
{
	yAng += moveSpeed;
}
void CALLBACK MutaJos(void)
{
	yAng -= moveSpeed;
}
void CALLBACK InvarteStanga(void)
{
	//zAng += 1.5;
	position[1] = position[1] - 4;
	position_umbra[1] = position_umbra[1] - 4;
}
void CALLBACK Invartedreapta(void)
{
	//zAng -= 1.5;
	position[1] = position[1] + 4;
	position_umbra[1] = position_umbra[1] + 4;
}
void CALLBACK Animation(void)
{
	GLfloat animSpeed = 0.1, waitTime = 20;
	yAnim = -5.0;
	while (yAnim < 0.1)
	{
		yAnim += animSpeed;
		display();
		Sleep(waitTime);
	}
	yAnim = 0.1;
}

// functii principale
void RotireModel(void)
{
	glTranslatef(1.4, 0, 0);
	// Rotiri principale
	glRotatef(yAng, 1.0, 0.0, 0.0);
	glRotatef(xAng, 0.0, 0.0, 1.0);
}

void DesenareCos(void)
{
	// desenare "cos"
	glPushMatrix();
	if (umbra == 1) glColor3f(0, 0, 0);
	else glColor3f(1.0, 0.6, 0.2);
	glTranslatef(-1.7, 0, 0);
	glEvalMesh2(GL_FILL, 0, 20, 0, 20);
	glPopMatrix();
}

void DesenareManer(void)
{
	// desenare "maner"
	if (umbra == 1) glColor3f(0, 0, 0);
	else glColor3f(1.0, 0.6, 0.2);
	glLineWidth(20);
	glRotatef(90, 1.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i <= 30; i++)
		glEvalCoord1f((GLfloat)i / 30.0);
	glEnd();
}

void DesenareSoare()
{
	glPushMatrix();
	glTranslatef(position[0], position[1], position[2]);
	glDisable(GL_LIGHTING);
	glColor3f(1.0, 1.0, 0.0);
	auxSolidSphere(1.5);
	glEnable(GL_LIGHTING);
	glPopMatrix();
}

void Desenareplan(void)
{
	glPushMatrix();
	glColor3f(0.133, 0.545, 0.133);
	glTranslatef(0, 0, 2);
	glRotatef(90, 1, 0, 0);
	glBegin(GL_QUADS);
	glVertex3f(500.0f, 3.0f, -500.0f);
	glVertex3f(-500.0f, 3.0f, -500.0f);
	glVertex3f(-500.0f, 3.0f, 500.0f);
	glVertex3f(500.0f, 3.0f, 500.0f);
	glEnd();
	glPopMatrix();
}

void DesenareMere(void)
{
	GLdouble appleSize = 0.6;
	// desenare mere
	if (umbra == 1) glColor3f(0.1, 0, 0);
	else glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(0, 1.0, -0.5);
	auxSolidSphere(appleSize);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-3.0, 1.0, -0.2);
	auxSolidSphere(appleSize);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-2.0, 0.5, 0);
	auxSolidSphere(appleSize);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-1.0, 0.8, 0);
	auxSolidSphere(appleSize);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-0.8, 0.6, 1.2);
	auxSolidSphere(appleSize);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-2.0, 0.8, 1.6);
	auxSolidSphere(appleSize);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-2.0, 1.0, 0.5);
	auxSolidSphere(appleSize);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-2.9, 0.5, 0.8);
	auxSolidSphere(appleSize);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-0.0, 0.6, 0.4);
	auxSolidSphere(appleSize);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-1.0, 0.9, -1.0);
	auxSolidSphere(appleSize);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-2.1, 1.1, -0.9);
	auxSolidSphere(appleSize);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-2.9, 0.7, -1.2);
	auxSolidSphere(appleSize);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-1.6, 0.4, -1.6);
	auxSolidSphere(appleSize);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-0.2, 0.4, -1.0);
	auxSolidSphere(appleSize);
	glPopMatrix();

	// animatie
	glPushMatrix();
	glTranslatef(-1.7, yAnim, 0.8); // -1.7, 0.1, 0.8
	auxSolidSphere(appleSize);
	glPopMatrix();

	// "coaja"
	glPushMatrix();
	glLineWidth(2.5);
	if (umbra == 1) glColor3f(0, 0.1, 0);
	else glColor3f(0.4, 0.8, 0.6);
	glBegin(GL_LINES);
	glVertex3f(-0.2, 0.3, -1.0);
	glVertex3f(-0.2, -0.25, -1.0);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(-1.0, 0.9, -1.0);
	glVertex3f(-1.0, 0.2, -1.0);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(-2.0, 0.5, 0);
	glVertex3f(-2.0, -0.2, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(-2.9, 0.5, 0.8);
	glVertex3f(-2.9, -0.2, 0.8);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(-3.0, 1.0, -0.2);
	glVertex3f(-3.0, 0.3, -0.2);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.6, 0.4);
	glVertex3f(-0.0, -0.1, 0.4);
	glEnd();
	glPopMatrix();
	
}

void calcCoeficinetiPlan(float P[3][3], float coef[4])
{
	float v1[3], v2[3];
	float length;
	static const int x = 0;
	static const int y = 1;
	static const int z = 2;
	//calculeaza doi vectori din 3 puncte
	v1[x] = P[0][x] - P[1][x];
	v1[y] = P[0][y] - P[1][y];
	v1[z] = P[0][z] - P[1][z];
	v2[x] = P[1][x] - P[2][x];
	v2[y] = P[1][y] - P[2][y];
	v2[z] = P[1][z] - P[2][z];
	// se calculeaza produsul vectorial al celor 2 vectori
	//care reprezinta un al treilea vector perpendicular pe plan
	//ale carui componente sunt chiar coeficientii A,B,C din ecuatiea planului

	coef[x] = v1[y] * v2[z] - v1[z] * v2[y];
	coef[y] = v1[z] * v2[x] - v1[x] * v2[z];
	coef[z] = v1[x] * v2[y] - v1[y] * v2[x];
	//normalizarea vectorului

	length = (float)sqrt((coef[x] * coef[x]) + (coef[y] * coef[y]) + (coef[z] * coef[z]));
	coef[x] /= length;
	coef[y] /= length;
	coef[z] /= length;
}


void MatriceUmbra(GLfloat puncte[3][3], GLfloat pozSursa[4], GLfloat mat[4][4])
{
	GLfloat coefPlan[4];
	GLfloat temp;
	//determina coeficientii planului
	calcCoeficinetiPlan(puncte, coefPlan);
	//determina si pe D
	coefPlan[3] = -((coefPlan[0] * puncte[2][0]) + (coefPlan[1] * puncte[2][1]) + (coefPlan[2] * puncte[2][2]));
	//temp=A*xL+B*yL+C*zL+D*w
	temp = coefPlan[0] * pozSursa[0] + coefPlan[1] * pozSursa[1] + coefPlan[2] * pozSursa[2] + coefPlan[3] * pozSursa[3];
	//prima coloana
	mat[0][0] = temp - pozSursa[0] * coefPlan[0];
	mat[1][0] = 0.0f - pozSursa[0] * coefPlan[1];
	mat[2][0] = 0.0f - pozSursa[0] * coefPlan[2];
	mat[3][0] = 0.0f - pozSursa[0] * coefPlan[3];
	//a doua coloana
	mat[0][1] = 0.0f - pozSursa[1] * coefPlan[0];
	mat[1][1] = temp - pozSursa[1] * coefPlan[1];
	mat[2][1] = 0.0f - pozSursa[1] * coefPlan[2];
	mat[3][1] = 0.0f - pozSursa[1] * coefPlan[3];
	//a treia coloana
	mat[0][2] = 0.0f - pozSursa[2] * coefPlan[0];
	mat[1][2] = 0.0f - pozSursa[2] * coefPlan[1];
	mat[2][2] = temp - pozSursa[2] * coefPlan[2];
	mat[3][2] = 0.0f - pozSursa[2] * coefPlan[3];
	//a patra coloana
	mat[0][3] = 0.0f - pozSursa[3] * coefPlan[0];
	mat[1][3] = 0.0f - pozSursa[3] * coefPlan[1];
	mat[2][3] = 0.0f - pozSursa[3] * coefPlan[2];
	mat[3][3] = temp - pozSursa[3] * coefPlan[3];

}


void CALLBACK display(void)
{
	GLfloat matUmbra[4][4];
	
	GLfloat puncte[3][3] = { 
		{ 10.0f, -10.0f, 16.0f },
		{ 8.0f,-16.0f,60.0f },
		{ 20.0f,-10.0f,16.0f } };
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	MatriceUmbra(puncte, position_umbra, matUmbra);
	glLoadIdentity();

	RotireModel();

	glPushMatrix();
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	umbra = 0;
	DesenareCos();
	DesenareManer();
	DesenareMere();
	glPopMatrix();

	glPushAttrib(GL_LIGHTING_BIT);
	glDisable(GL_LIGHTING);
	glPushMatrix();
	glMultMatrixf((GLfloat*)matUmbra);
	umbra = 1;
	DesenareCos();
	DesenareManer();
	DesenareMere();
	glPopMatrix();
	DesenareSoare();

	Desenareplan();
	glPopAttrib();


	glFlush();
	auxSwapBuffers();
}

void myinit(void)
{
	glClearColor(0.2, 0.7, 1.0, 1.0);
	glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4, 0, 1, 12, 4, &ctrlpoints[0][0][0]);
	glEnable(GL_MAP2_VERTEX_3);
	glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoints2[0][0]);
	glEnable(GL_MAP1_VERTEX_3);
	glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);

	GLfloat ambient[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	GLfloat diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };

	GLfloat mat_specular[] = { 0.3f, 0.1f, 0.4f, 1.0f };
	GLfloat mat_shininess[] = { 60.0f };
	GLfloat global_ambient[] = { 0.1, 0.1, 0.1, 1.0 };
	glEnable(GL_LIGHTING); // activare iluminare
	glEnable(GL_LIGHT0);	// activare sursa 0	
	glEnable(GL_NORMALIZE);
	//permite urmarirea culorilor
	glEnable(GL_COLOR_MATERIAL);
	//seteaza proprietatile de material pentru a urma glColor
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	// seteaza sursa
	
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	glFrontFace(GL_CW);
	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_COLOR_MATERIAL);

	glShadeModel(GL_FLAT);
}


void CALLBACK myReshape(GLsizei w, GLsizei h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-7.0, 7.0, -7.0*(GLfloat)h / (GLfloat)w, 7.0*(GLfloat)h / (GLfloat)w, -15.0, 15.0);
	else
		glOrtho(-7.0*(GLfloat)w / (GLfloat)h, 7.0 * (GLfloat)w / (GLfloat)h, -7.0, 7.0, -15.0, 15.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/*
void CALLBACK myReshape(GLsizei w, GLsizei h)
{
	if (!h) return;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-100.0, 100.0, -100.0*(GLfloat)h / (GLfloat)w,
			100.0*(GLfloat)h / (GLfloat)w, -100.0, 100.0);
	else
		glOrtho(-100.0*(GLfloat)w / (GLfloat)h,
			100.0*(GLfloat)w / (GLfloat)h, -100.0, 100.0, -100.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}*/

int main(int argc, char** argv)
{
	auxInitDisplayMode(AUX_SINGLE | AUX_DEPTH16 | AUX_RGB);
	auxInitPosition(100, 100, 1000, 700);
	auxInitWindow("Cos cu mere");
	myinit();

	// functii mouse/butoane
	auxKeyFunc(AUX_LEFT, MutaStanga);
	auxKeyFunc(AUX_RIGHT, MutaDreapta);
	auxKeyFunc(AUX_DOWN, MutaJos);
	auxKeyFunc(AUX_UP, MutaSus);
	auxMouseFunc(AUX_LEFTBUTTON, AUX_MOUSEDOWN, InvarteStanga);
	auxMouseFunc(AUX_RIGHTBUTTON, AUX_MOUSEDOWN, Invartedreapta);
	auxKeyFunc(AUX_SPACE, Animation);

	auxReshapeFunc(myReshape);
	auxMainLoop(display);
	return(0);
}

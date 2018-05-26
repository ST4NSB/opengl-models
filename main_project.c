#include "glos.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>

void myinit(void);
void CALLBACK display(void);
void CALLBACK myReshape(GLsizei w, GLsizei h);

static int moveSpeed = 10;
static GLfloat xAng = 0, yAng = 90, zAng = -8.0, yAnim = 0.1;

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
	zAng += 1.5;
}
void CALLBACK Invartedreapta(void)
{
	zAng -= 1.5;
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
	glColor3f(1.0, 0.6, 0.2);
	glTranslatef(-1.7, 0, 0);
	glEvalMesh2(GL_FILL, 0, 20, 0, 20);
	glPopMatrix();
}

void DesenareManer(void)
{
	// desenare "maner"
	glColor3f(1.0, 0.6, 0.2);
	glLineWidth(20);
	glRotatef(90, 1.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i <= 30; i++)
		glEvalCoord1f((GLfloat)i / 30.0);
	glEnd();
}

void DesenareSoare()
{
	GLfloat position[] = { -1.5, -4.8, -8.0, 1.0 };
	GLfloat global_ambient[] = { 0.1, 0.1, 0.1, 1.0 };

	glPushMatrix();
	glTranslatef(position[0], position[1], zAng);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);
	glDisable(GL_LIGHTING);
	glColor3f(1.0, 1.0, 0.0);
	auxSolidSphere(0.3);
	glEnable(GL_LIGHTING);
	glPopMatrix();
}

void Desenareplan(void)
{
	glPushMatrix();
	glColor3f(0, 1, 0);
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
	glColor3f(1.0, 0.0, 0.0);
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
	glColor3f(0.4, 0.8, 0.6);
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


void CALLBACK display(void)
{
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	RotireModel();
	DesenareCos();
	DesenareManer();
	DesenareMere();

	DesenareSoare();
	Desenareplan();


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

	
	glFrontFace(GL_CW);
	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_COLOR_MATERIAL);
	
	glShadeModel(GL_FLAT);
	glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);
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

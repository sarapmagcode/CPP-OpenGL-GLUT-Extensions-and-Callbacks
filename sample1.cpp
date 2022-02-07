#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include <iostream>

using namespace std;

void display1();
void displayTriangle();

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0); // top-left most
	glutCreateWindow("OpenGL Setup Test 1");
//	glutFullScreen();
	glutDisplayFunc(display1);
	
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(320, 240);
	glutCreateWindow("OpenGL Setup Test 2");
//	glutFullScreen();
	glutDisplayFunc(displayTriangle);
	
	
	glutMainLoop();
	return 0;
}

void display1() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	const unsigned char str[100] = {"FEU-TECH"};
	glColor3f(0.0f, 0.0f, 1.0f);
	glRasterPos2f(-0.50f, 0.0f);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, str);

	glFlush();
}

void displayTriangle() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBegin(GL_TRIANGLES);
	
	glVertex2f(-.5f,-.5f);
	glVertex2f(.5f,-.5f);
	glVertex2f(0.0f,.5f);

	glEnd();	
	glFlush();
}
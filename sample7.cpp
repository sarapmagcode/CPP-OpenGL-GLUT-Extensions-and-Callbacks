#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

void display1();
void textAdjustPosition();
void doSomething(int value);
void doSomethingWhenIdle();

float xpos = 0.0f;
float ypos = 0.0f;

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0); // top-left most
	glutCreateWindow("OpenGL Setup Test");
	glutDisplayFunc(display1);
	glutIdleFunc(doSomethingWhenIdle);
	glutMainLoop();
	return 0;
}

void doSomething(int value) {
	cout << "Program is idle, I wanted to work on something..." << endl;
}

void doSomethingWhenIdle() { // like a thread running in a background
	Sleep(1000);
	doSomething(1);
}

void textAdjustPosition(int value) {
	xpos -= 0.02f;
	glutPostRedisplay();
}

void display1() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	const unsigned char str[100] = {"FEU-TECH"};
	glColor3f(0.0f, 0.0f, 1.0f);
	glRasterPos2f(xpos, ypos);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, str);
	
	glFlush();
	
	glutTimerFunc(1000, textAdjustPosition, 1);
}

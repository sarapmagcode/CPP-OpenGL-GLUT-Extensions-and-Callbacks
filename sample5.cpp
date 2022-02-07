#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include <iostream>

using namespace std;

void display1();
void mousePosition(int x, int y);

float xpos = 0.0f;
float ypos = 0.0f;

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0); // top-left most
	glutCreateWindow("OpenGL Setup Test");
	glutDisplayFunc(display1);
//	glutMotionFunc(mousePosition); // while mouse being pressed
	glutPassiveMotionFunc(mousePosition); // mouse not needed to be pressed
	glutMainLoop();
	return 0;
}

void mousePosition(int x, int y) {
	cout << "Mouse Location : " << x << " " << y << endl;
}

void display1() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	const unsigned char str[100] = {"FEU-TECH"};
	glColor3f(0.0f, 0.0f, 1.0f);
	glRasterPos2f(xpos, ypos);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, str);
	
	glFlush();
}

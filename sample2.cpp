#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include <iostream>

using namespace std;

void display1();
void keyboardMonitor(unsigned char key, int x, int y);

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0); // top-left most
	glutCreateWindow("OpenGL Setup Test");
	glutDisplayFunc(display1);
	glutKeyboardFunc(keyboardMonitor);
	glutMainLoop();
	return 0;
}

void keyboardMonitor(unsigned char key, int x, int y) {
	// key = character pressed in the keyboard
	// (x, y) = last clicked position of the mouse cursor
	cout << key << " " << x << " " << y << endl;
	if (key == 'z' || key == 'Z') {
		cout << "Fire!!!!!" << endl;
	}
}

void display1() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	const unsigned char str[100] = {"FEU-TECH"};
	glColor3f(0.0f, 0.0f, 1.0f);
	glRasterPos2f(-0.50f, 0.0f);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, str);

	glFlush();
}
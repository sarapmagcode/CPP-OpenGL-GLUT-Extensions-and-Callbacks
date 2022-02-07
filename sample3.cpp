#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include <iostream>

using namespace std;

void display1();
void keyboardMonitor(unsigned char key, int x, int y);

float xpos = 0.0f;
float ypos = 0.0f;

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
	switch (key) {
		case 'a': case 'A': // move left
			xpos -= 0.05f;
			break;
		case 'd': case 'D': // move right
			xpos += 0.05f;
			break;
		case 'w': case 'W': // move up
			ypos += 0.05f;
			break;
		case 's': case 'S': // move right
			ypos -= 0.05f;
			break;
	}
	glutPostRedisplay();
}

void display1() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	const unsigned char str[100] = {"FEU-TECH"};
	glColor3f(0.0f, 0.0f, 1.0f);
	glRasterPos2f(xpos, ypos);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, str);
	
	glFlush();
}

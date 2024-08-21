#include <iostream>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>

// https://www.youtube.com/watch?v=NT-0Q2Psp2Y&list=PLWzp0Bbyy_3jy34HlDrEWlcG3rF99gkvk&index=3

// 2nd lession


void display();
void reshape(int w, int h);




void init()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
}

int main(int argc, char**argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowPosition(200,100);
	glutInitWindowSize(500,500);
	glutCreateWindow("Window - 1");

	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	init();



	glutMainLoop();
}



void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glPointSize(10.0);
	//draw
	glBegin(GL_POINTS);
		glVertex2f(-5, 5);
		glVertex2f(-1, 1);
	glEnd();

	glBegin(GL_TRIANGLES);
		glVertex2f(5,5);
		glVertex2f(5,-5);
		glVertex2f(-5,-5);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(-5, 4);
		glVertex2f(-4, 5);
		glVertex2f(-3, 5);
		glVertex2f(-5, 3);
	glEnd();

	glFlush();

}

void reshape(int w, int h)
{
	glViewport(0,0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);
	glMatrixMode(GL_MODELVIEW);
}
#include "platform.h"

#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <iostream>

void Platform::init()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glShadeModel (GL_FLAT);
}


void Platform::KeyboardCallback (unsigned char key, int x, int y) {

	switch (key)
	{
		case 27: 	// ESCAPE key
			exit(0);
			break;
	}
}

void Platform::displayCallback()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	//glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glColor3f(0.7f, 0.7f, 0.7f);



	 glMatrixMode(GL_MODELVIEW);
	 glPushMatrix();
	 glTranslatef(0, 0, 1);
	 glRotatef(45, 1, 1, 0);

	 glScalef(1,0.1,1);
	 glutWireCube(1);
	 //glutSolidCone(0.5f, 1, 10, 10);
		//glBegin(GL_QUADS);

//			glNormal3f(0, 1, 0);
//			glVertex3f(-1, 0, 1);
//			glVertex3f(1, 0, 1);
//			glVertex3f(1, 0, -1);
//			glVertex3f(-1, 0, -1);
//		glEnd();
	 glPopMatrix();

	glutSwapBuffers();
}

/**
 * Initiate the GLUT library and sets up the opengl
 */
Platform::Platform(int argc, char** argv)
{
	   title = "Lonely Arm Beta";

	   glutInit(&argc,argv);
	   glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

	   glutInitWindowPosition(0,0);
	   glutCreateWindow(title.c_str());
	   glutFullScreen();

	   init();

	   glutDisplayFunc(Platform::displayCallback);

	   glutKeyboardFunc(Platform::KeyboardCallback);

	   glutMainLoop();
}


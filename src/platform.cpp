#include "platform.h"
#include <GL/glut.h>

void Platform::draw()
{
	glColor3f(0.7f, 0.7f, 0.7f);

	 glPushMatrix();
         glScalef(1,0.1,1);
         glTranslatef(0, -3, 1);
         glRotatef(60, 1, 0, 0);
         glRotatef(-15, 0, 1, 0);
         glutWireCube(1);
	 glPopMatrix();
}

Platform::Platform()
{
    test = 0;
}

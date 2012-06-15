#include "platform.h"
#include <GL/glut.h>

void Platform::draw()
{
	glColor3f(0.7f, 0.7f, 0.7f);

	 glPushMatrix();
         glScalef(1,0.1,1);
         glTranslatef(0, 0, 1);
         glutWireCube(1);
         glScalef(1,1,1); 
     glPopMatrix();
}

Platform::Platform()
{
}

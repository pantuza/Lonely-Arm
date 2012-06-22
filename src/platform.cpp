#include "platform.h"
#include <GL/glut.h>

/**
 * Draw the platform using GL scale function
 */
void Platform::draw()
{
	glColor3f(0, 1, 1);

	 glPushMatrix();
         glScalef(2,0.1,2);
         glTranslatef(0, 0, 0);
         glutSolidCube(1);
     glPopMatrix();
}

Platform::Platform()
{
}

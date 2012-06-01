#include "parts.h"
#include <GL/glut.h>

Parts::Parts(int numParts)
{
    partHeight = 0.15;
    jointRadius = 0.02;
    handHeight = 0.05;
    this->numParts = numParts;
}
void Parts::pushParts()
{
    if( numParts > 0 )
    {
        glPushMatrix();
            drawPart();
            drawJoint();
            numParts--;
            pushParts(); 
        glPopMatrix();
    }
}

void Parts::drawPart()
{
     glColor3f(1,1,0);
     gluCylinder(gluNewQuadric(), 0.01, 0.01, partHeight, 500, 500);
}

void Parts::drawJoint()
{
    glColor3f(0,0,1);
    glTranslatef(0, 0, partHeight + jointRadius/2);
    glutSolidSphere(jointRadius, 500, 500);
}

void Parts::drawHand()
{

}

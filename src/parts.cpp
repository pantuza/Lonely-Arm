#include "parts.h"
#include <GL/glut.h>

Parts::Parts(int numParts)
{
    partHeight = 0.15;
    jointRadius = 0.02;
    handHeight = 0.05;
    this->numParts = numParts;

    basePartRadius, topPartRadius = 0.1;
    slices, stacks = 500;
}

void Parts::pushParts()
{
    if( numParts > 0 )
    {
        glPushMatrix();
            drawPart();
            drawJoint();
            numParts--;
            /** Recursive call */
            pushParts();
        glPopMatrix();
    }
}

void Parts::setArmRotation( rotation )
{
    armRotation = rotation;
}

void Parts::setForeArmRotation( rotation )
{
    foreArmRotationn = rotation;
}

void Parts::drawPart()
{
    glRotatef(armRotation, 0, 1, 0);
    glColor3f(1,1,0);
    gluCylinder(gluNewQuadric(), basePartRadius, topPartRadius, 
                                                partHeight, slices, stacks);
}

void Parts::drawJoint()
{
    glColor3f(0,0,1);
    glTranslatef(0, 0, partHeight + jointRadius/2);
    glutSolidSphere(jointRadius, slices, stacks);
}

void Parts::drawHand()
{

}

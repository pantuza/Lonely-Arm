#include "parts.h"
#ifdef __APPLE__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

Parts::Parts()
{
    partHeight      = 0.15;
    jointRadius     = 0.02;
    handHeight      = 0.05;

    handRotation    = 0;

    basePartRadius  = 0.01;
    topPartRadius   = 0.01;
    fingerAngle     = 60;

    slices          = 50.0; 
    stacks          = 50.0;
}
/**
 * Public method to draw the entire Arm 
 */
void Parts::pushParts()
{
    glPushMatrix();
       drawPart(baseArmRotation);
        drawJoint();

        glPushMatrix();
            drawPart(armRotation);
            drawJoint();

            glPushMatrix();
                drawPart(foreArmRotation);
                drawJoint();
                drawHand();
            glPopMatrix();

        glPopMatrix();

    glPopMatrix();
}

void Parts::setBaseArmRotation(float rotation)
{
    baseArmRotation = rotation;
}

void Parts::setArmRotation(float rotation)
{
    armRotation = rotation;
}

void Parts::setForeArmRotation(float rotation)
{
    foreArmRotation = rotation;
}

void Parts::drawPart(float rotation)
{
    glRotatef(rotation, 0, 1, 0);
    glColor3f(1,1,0);
    gluCylinder(gluNewQuadric(), basePartRadius, topPartRadius, 
                                                partHeight, slices, stacks);
}

void Parts::setFingerAngle(float angle)
{
    fingerAngle = angle;
}

void Parts::rotateHand()
{
    handRotation += 10;
}

void Parts::drawJoint()
{
    glColor3f(0,0,1);
    glTranslatef(0, 0, partHeight + jointRadius/2);
    glRotatef(handRotation, 0, 0, 1);
    glutSolidSphere(jointRadius, slices, stacks);
}

void Parts::drawHand()
{
    glColor3f(0.5,0.5,0.5);
    glRotatef(60,0,1,0);
    gluCylinder(gluNewQuadric(), 0.008, 0.008, 0.1, slices, stacks);
    glTranslatef(0,0,0.1);

    glRotatef(-fingerAngle,0,1,0);
    glutSolidCone(0.008, 0.1,slices,stacks);
    glRotatef(fingerAngle,0,1,0);

    glTranslatef(0,0,-0.1);

    glRotatef(-120,0,1,0);
    gluCylinder(gluNewQuadric(), 0.008, 0.008, 0.1, slices, stacks);
    glTranslatef(0,0,0.1);
    glRotatef(fingerAngle,0,1,0);
    glutSolidCone(0.008, 0.1,slices,stacks);
    glRotatef(-fingerAngle,0,1,0);
    glTranslatef(0,0,-0.1);
}

void Parts::closeHand()
{
    if( fingerAngle < 120 )
        fingerAngle += 10;
}

void Parts::openHand()
{
    if( fingerAngle >= 0 )
        fingerAngle -= 10;
}

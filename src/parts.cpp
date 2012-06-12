#include "parts.h"
#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
Parts::Parts()
{
    partHeight = 0.15;
    jointRadius = 0.02;
    handHeight = 0.05;

    baseArmRotation = 0.0;
    armRotation = 0.0;
    foreArmRotation = 0.0;

    basePartRadius = 0.01;
    topPartRadius = 0.01;
    slices = 500; 
    stacks = 500;
}

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

void Parts::drawJoint()
{
    glColor3f(0,0,1);
    glTranslatef(0, 0, partHeight + jointRadius/2);
    glutSolidSphere(jointRadius, slices, stacks);
}

void Parts::drawHand()
{
    static float rotation = 0;
    glRotatef(++rotation, 0,1,0);
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_QUADS);
    glVertex3f(0.2, 0, 0);
    glVertex3f(0.2, 0, 0.01);
    glVertex3f(0, 0, 0.01);
    glVertex3f(0, 0, 0);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(-0.2, 0, 0);
    glVertex3f(-0.2, 0, 0.01);
    glVertex3f(0, 0, 0.01);
    glVertex3f(0, 0, 0);
    glEnd();

}

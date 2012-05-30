#include "arm.h"
#include <GL/glut.h>

Arm::Arm() : ROTATION_FACTOR(5), DISPLACEMENT(0.01)
{
    rotation = 180;
    rotation2 = 0;
    direction = 0;
}

void Arm::draw()
{
    

    glColor3f(1,1,0);

    glPushMatrix();
        glTranslatef(direction,-0.15, 1);
        glRotatef(90, 1, 0, 0);
        gluCylinder(gluNewQuadric(), 0.01, 0.01, 0.15, 500, 500);
        glColor3f(0,0,1);
        glTranslatef(0, 0.18, 0);
        glutSolidSphere(0.02, 500, 500);

        glPushMatrix();
            glColor3f(1, 1, 0);
            glTranslatef(0, 0, -0.01);
            glRotatef(rotation, 0, 1, 0);
            gluCylinder(gluNewQuadric(), 0.01, 0.01, 0.15, 500, 500);
            glColor3f(0,0,1);
            glTranslatef(0, 0, 0.16);
            glutSolidSphere(0.02, 500, 500);

            glPushMatrix();
                glColor3f(1, 1, 0);
                glTranslatef(0, 0, 0.01);
                glRotatef(rotation2, 0, 1, 0);
                gluCylinder(gluNewQuadric(), 0.01, 0.01, 0.15, 500, 500);
                glColor3f(0,0,1);
                glTranslatef(0, 0, 0.16);
                glutSolidSphere(0.02, 500, 500);
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}

void Arm::rotateClockwise()
{
    rotation += ROTATION_FACTOR;
}

void Arm::rotateCounterClockwise()
{
    rotation -= ROTATION_FACTOR;
}
void Arm::rotateClockwise2()
{
    rotation2 += ROTATION_FACTOR;
}

void Arm::rotateCounterClockwise2()
{
    rotation2 -= ROTATION_FACTOR;
}

void Arm::moveRight()
{
    direction -= DISPLACEMENT;
}

void Arm::moveLeft()
{
    direction += DISPLACEMENT;
}



#include "arm.h"
#include <GL/glut.h>

Arm::Arm()
{
    rotation = 180;
}

void Arm::draw()
{
    

    glColor3f(1,1,0);

    glPushMatrix();
        glTranslatef(0,-0.15, 1);
        glRotatef(90, 1, 0, 0);
        gluCylinder(gluNewQuadric(), 0.02, 0.02, 0.15, 500, 500);
        glColor3f(0,0,1);
        glTranslatef(0, 0.17, 0);
        glutSolidSphere(0.02, 500, 500);

        glPushMatrix();
            glColor3f(1, 1, 0);
            glTranslatef(0, 0.19, 0);
            glRotatef(rotation, 0, 1, 0);
            gluCylinder(gluNewQuadric(), 0.02, 0.02, 0.10, 500, 500);
        glPopMatrix();

    glPopMatrix();
}

void Arm::rotateClockwise()
{
    rotation++;
}

void Arm::rotateCounterClockwise()
{
    rotation--;
}

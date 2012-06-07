#include "arm.h"
#include "parts.h"
#include <GL/glut.h>

Arm::Arm() : ROTATION_FACTOR(5), DISPLACEMENT(0.01)
{
    rotation = 0;
    rotation2 = 0;
    
    xPosition = 0;
    zPosition = 1;

    Parts armParts(3);
}

void Arm::draw()
{

    glPushMatrix();
        glTranslatef(xPosition, 0.05, zPosition);
        glRotatef(-90, 1, 0, 0);
        armParts.pushParts();
        glRotatef(90, 1, 0, 0);
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
    xPosition -= DISPLACEMENT;
}

void Arm::moveLeft()
{
    xPosition += DISPLACEMENT;
}
void Arm::moveUp()
{
    zPosition += DISPLACEMENT;
}
void Arm::moveDown()
{
    zPosition -= DISPLACEMENT;
}


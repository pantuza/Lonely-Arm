#include "arm.h"
#include "parts.h"
#include <GL/glut.h>

Arm::Arm() : ROTATION_FACTOR(5), DISPLACEMENT(0.01)
{
    rotation = 0;
    rotation2 = 0;
    direction = 0;
}

void Arm::draw()
{
    Parts armParts(3);

    glPushMatrix();
        glTranslatef(direction, 0.05, 1);
        glRotatef(-90, 1, 0, 0);
        
        armParts.pushParts();
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



#include "arm.h"
#include "parts.h"
#include <GL/glut.h>

Arm::Arm() : ROTATION_FACTOR(5), DISPLACEMENT(0.01)
{
    armRotation = 0.0;
    foreArmRotation = 0.0;
    
    xPosition = 0;
    zPosition = 1;

    Parts armParts;
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

void Arm::rotateClockwise(int part)
{
    switch(part) 
    {
       case 1:
            armRotation += ROTATION_FACTOR;
            armParts.setArmRotation(armRotation);
            break;
       case 2:
            foreArmRotation += ROTATION_FACTOR;
            armParts.setForeArmRotation(foreArmRotation);
            break;
    }
}

void Arm::rotateCounterClockwise(int part)
{
    switch(part)
    {
        case 1:
            armRotation -= ROTATION_FACTOR;
            armParts.setArmRotation(armRotation);
            break;
       case 2:
            foreArmRotation -= ROTATION_FACTOR;
            armParts.setForeArmRotation(foreArmRotation);
            break;
    }
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


#include "arm.h"
#include "parts.h"
#include <GL/glut.h>
#include <stdio.h>
#include <iostream>



Arm::Arm() : ROTATION_FACTOR(5), DISPLACEMENT(0.01)
{
    armRotation = 0.0;
    foreArmRotation = 0.0;
    
    xFlightPosition = 0;
    yFlightPosition = 0.5;
    zFlightPosition = 1;

    Parts armParts;
}

void Arm::draw()
{
    glPushMatrix();
     //   std::cout << "xPos:" << xPosition << "\n";
        glTranslatef(xFlightPosition, yFlightPosition, zFlightPosition);
        glRotatef(-90, 1, 0, 0);

        drawBase();
        armParts.pushParts();
        
        glRotatef(90, 1, 0, 0);
    glPopMatrix();
}
void Arm::drawBase()
{
    glPushMatrix();
        glScalef(1,1,0.1);    
        glutSolidCube(0.15);
        glScalef(1,1,1);
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
       case 3:
            armParts.closeHand();
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
       case 3:
            armParts.openHand();
            break;
    }
}
void Arm::setFlyDown()
{
    yFlightPosition -= DISPLACEMENT;
}
void Arm::setFlyUp()
{
     yFlightPosition += DISPLACEMENT;
}
void Arm::setFlyLeft()
{
    xFlightPosition -= DISPLACEMENT;
}
void Arm::setFlyRight()
{
    xFlightPosition += DISPLACEMENT;
}
void Arm::moveRight()
{
   // if(xPosition < 0.5)
        xFlightPosition += DISPLACEMENT;
}

void Arm::moveLeft()
{
    //if(xPosition > -0.5)
        xFlightPosition -= DISPLACEMENT;
}
void Arm::moveUp()
{
    if(zFlightPosition < 1.5)
        zFlightPosition += DISPLACEMENT;
}
void Arm::moveDown()
{
    if(zFlightPosition > 0.5)
        zFlightPosition -= DISPLACEMENT;
}

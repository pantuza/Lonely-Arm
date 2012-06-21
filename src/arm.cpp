#include "arm.h"
#include "parts.h"
#include <GL/glut.h>
#include <stdio.h>
#include <iostream>


Arm::Arm() : ROTATION_FACTOR(5)
{
    armRotation = 0.0;
    foreArmRotation = 0.0;
    
    xFlightPosition = -0.075;
    yFlightPosition = 0.1;
    zFlightPosition = -0.075;
    
    displacement = 0.01;

    Parts armParts;
}

void Arm::draw()
{
    glPushMatrix();
        glTranslatef(xFlightPosition, yFlightPosition, zFlightPosition);
        glRotatef(-90, 1, 0, 0);

        drawBase();
        armParts.pushParts();
        
    glPopMatrix();
}
void Arm::drawBase()
{
    glPushMatrix();
        glColor3f(0.5,0.5,0.8);
        glScalef(1,1,0.1);    
        glutSolidCube(0.15);
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
void Arm::fly()
{
    armParts.setFingerAngle(0);
    armParts.rotateHand();
}

bool Arm::collidedOnYAxis()
{
    return yFlightPosition > -0.65 && yFlightPosition < 0.10;
}

bool Arm::collidedOnXAxis()
{
    return xFlightPosition > -1 && xFlightPosition < 1; 
}
bool Arm::needReposition()
{
    return yFlightPosition < 0.1;
}
void Arm::setFlyDown()
{
    yFlightPosition -= displacement;
    if(collidedOnYAxis())
    { 
        if(collidedOnXAxis())
        {
            yFlightPosition = 0.10;
        }
    }       
}

void Arm::setFlyUp()
{
    yFlightPosition += displacement;
    if(collidedOnYAxis())
    {
        if(collidedOnXAxis())
            {
                yFlightPosition = -0.65;
            }       
    }
}

void Arm::setFlyLeft()
{
    if(collidedOnYAxis()){
        if(collidedOnXAxis())
            xFlightPosition -= displacement;
    }else
        xFlightPosition -= displacement;
}
void Arm::setFlyRight()
{
    if(collidedOnYAxis()){
        if(collidedOnXAxis())
            xFlightPosition += displacement;
    } else
        xFlightPosition += displacement;
}
void Arm::moveRight()
{
    if(xFlightPosition < 0.925)
        xFlightPosition += displacement;
}

void Arm::moveLeft()
{
    if(xFlightPosition > -0.925)
        xFlightPosition -= displacement;
}
void Arm::moveUp()
{
    if(zFlightPosition > -0.85)
        zFlightPosition -= displacement;
}
void Arm::moveDown()
{
    if(zFlightPosition < 1)
        zFlightPosition += displacement;
}

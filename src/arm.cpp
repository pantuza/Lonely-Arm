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

void Arm::setFlyDown()
{
//    std::cout << "y: " << yFlightPosition << "\n";
/*
    if(yFlightPosition > 0.1 || yFlightPosition <= -0.64)
        yFlightPosition -= displacement;
    else if(xFlightPosition < -1.1 || xFlightPosition > 1.1)
        yFlightPosition -= displacement;
*/

    if (yFlightPosition > 0.1 || yFlightPosition <= -0.64) {
        yFlightPosition -= displacement;
        if (yFlightPosition <  0.1)
        	yFlightPosition = 0.1;
    } else if (xFlightPosition < -1.1 || xFlightPosition > 1.1) {
        yFlightPosition -= displacement;
	}

}

void Arm::setFlyUp()
{
    if(yFlightPosition < -0.65 || yFlightPosition >= 0.05)
        yFlightPosition += displacement;
    else if(xFlightPosition < -1.1 || xFlightPosition > 1.1)
        yFlightPosition += displacement;
}

void Arm::setFlyLeft()
{
    std::cout << "y: " << yFlightPosition << "\n";


    if(yFlightPosition <= 0.1 && yFlightPosition > -0.64){
        std::cout << "x: " << xFlightPosition << "\n";
        if(xFlightPosition < -1.1 || xFlightPosition > 1.2)
            xFlightPosition -= displacement;
    }else
        xFlightPosition -= displacement;
}
void Arm::setFlyRight()
{   std::cout << "y: " << yFlightPosition << "\n";

    if(yFlightPosition <= 0.1 && yFlightPosition > -0.64){
            std::cout << "x: " << xFlightPosition << "\n";
        if(xFlightPosition < -1.2 || xFlightPosition > 1.1)
            xFlightPosition += displacement;
}    else
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

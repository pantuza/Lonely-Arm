#include "camera.h"
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <iostream>

float Camera::zoom = 3;
float Camera::angle = 30;
float Camera::eyeX = 0.1;
float Camera::eyeY = 0.1;
float Camera::eyeZ = 0.1;

void Camera::updateCamera(float xArm, float yArm, float zArm)
{
    float radians = angle*PI/180;

    std::cout << "zoom: " << yArm << "\n";
    eyeX = cos(radians)*zoom + xArm;
    eyeY = yArm + 1;    
    eyeZ = sin(radians)*zoom + zArm;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(angle, 2, 1, 30);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyeX, eyeY, eyeZ, xArm, yArm, zArm, 0, 1, 0 );
}

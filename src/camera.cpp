#include "camera.h"
#ifdef __APPLE__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif
#include <math.h>

/** define the static atributes of the Camera class */
float Camera::zoom = 3;
float Camera::angle = 30;
float Camera::eyeX = 0.1;
float Camera::eyeY = 0.1;
float Camera::eyeZ = 0.1;
float Camera::windowRatio = 1;

/**
 * Update the camera posicion, orientation and visualization vector.
 *
 * @param xArm, yArm, zArm : the current position of the Arm to look at.
 */
void Camera::updateCamera(float xArm, float yArm, float zArm)
{
    float radians = angle*PI/180;

    eyeX = cos(radians)*zoom + xArm;
    eyeY = yArm + 1;    
    eyeZ = sin(radians)*zoom + zArm;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30, windowRatio, 1, 30);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    gluLookAt(eyeX, eyeY, eyeZ, xArm, yArm, zArm, 0, 1, 0 );
}

void Camera::resetCamera()
{
    zoom = 3;
    angle = 30;
    eyeX = 0.1;
    eyeY = 0.1;
    eyeZ = 0.1;
}


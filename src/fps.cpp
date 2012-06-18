/*
 * fps.cpp
 *
 *  Created on: 17/06/2012
 *      Author: dev
 */

#include <GL/glut.h>

#include "fps.h"

Fps::Fps() {
	fps = frameCount = 0;
	previousTime = 0;
}

int Fps::newFrame()
{
	// count the frame
	frameCount++;
    //  Get the number of milliseconds since glutInit called
    //  (or first call to glutGet(GLUT ELAPSED TIME)).
    int currentTime = glutGet(GLUT_ELAPSED_TIME);

    //  Calculate time passed
    int timeInterval = currentTime - previousTime;

    if(timeInterval > 1000)
    {
        //  calculate the number of frames per second
        fps = frameCount / (timeInterval / 1000.0f);

        //  Set time
        previousTime = currentTime;

        //  Reset frame count
        frameCount = 0;
    }

    return fps;

}

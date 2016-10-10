#ifdef __APPLE__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif
#include "fps.h"

Fps::Fps() {
	fps = frameCount = 0;
	previousTime = 0;
}

int Fps::newFrame()
{
	frameCount++;
    /** 
     * Get the number of milliseconds since glutInit called
     * (or first call to glutGet(GLUT ELAPSED TIME)).
     */
    int currentTime = glutGet(GLUT_ELAPSED_TIME);

    //  Calculate time passed
    int timeInterval = currentTime - previousTime;

    if(timeInterval > 1000)
    {   // calculate the number of frames per second
        fps = frameCount / (timeInterval / 1000.0f);
        previousTime = currentTime;
        frameCount = 0;
    }
    return fps;
}

#include "platform.h"
#include "arm.h"
#include "camera.h"
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include "text.h"
#include "fps.h"

#define TITLE "Lonely Arm"
#define VERSION "Beta"


class Game
{
    public:
        static void run(int argc, char* argv[]);
    private:
        static Platform platform;
        static Arm arm;
        static void configure();
        static void keyboardCallBack(unsigned char key, int x, int y);
        static void specialKeysCallBack(int key, int x, int y);
        static void displayCallBack();
        static void reshapeCallBack(int width, int height);
        static int currentPart;
        static bool flyingMode;
        static void timerCallBack(int value);
        static Text labelFps;
        static Fps fps;
        static int dt;

};

#define FPS     120

Platform Game::platform;
Arm Game::arm;
int Game::currentPart = 1;
bool Game::flyingMode = false;
Text Game::labelFps;
Fps Game::fps;
int Game::dt = (1000/FPS);

void Game::run(int argc, char* argv[])
{
    glutInit(&argc,argv);
    //glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowPosition(0,0);
    glutCreateWindow(TITLE);
    glutFullScreen();

    configure();

    glutDisplayFunc(displayCallBack);
    glutKeyboardFunc(keyboardCallBack);
    glutSpecialFunc(specialKeysCallBack);
    glutReshapeFunc(reshapeCallBack);

    labelFps.setPosition(0.90, 0.95, 0);

    glutMainLoop();
}

void Game::configure()
{
     GLfloat placeLight[4]={0.2,0.2,0.2,1.0};
     GLfloat diffusedLight[4]={0.7,0.7,0.7,1.0}; // color 
     GLfloat specularLight[4]={1.0, 1.0, 1.0, 1.0}; // "brightness" 
     GLfloat lightPosition[4]={10.0, 10.0, 1.0, 1.0}; // light position variation

     // material brightness 
         GLfloat specularity[4]={1.0,1.0,1.0,1.0};
         GLint materialSpecularity = 60;

     // Gouraud colors
         glShadeModel(GL_SMOOTH);

         // reflection 
         glMaterialfv(GL_FRONT,GL_SPECULAR, specularity);
         // brightness concentration 
     glMateriali(GL_FRONT,GL_SHININESS,materialSpecularity);

         // place light
         glLightModelfv(GL_LIGHT_MODEL_AMBIENT, placeLight);

         glLightfv(GL_LIGHT0, GL_AMBIENT, placeLight);
         glLightfv(GL_LIGHT0, GL_DIFFUSE, diffusedLight );
         glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight );
         glLightfv(GL_LIGHT0, GL_POSITION, lightPosition );

         glEnable(GL_COLOR_MATERIAL);
         glEnable(GL_LIGHTING);
         glEnable(GL_LIGHT0);
         glEnable(GL_DEPTH_TEST);

    glEnable(GL_CULL_FACE);
}

void Game::timerCallBack(int value)
{
    float yPosOnPlatform = arm.getYarm();
    if(value == 1)
    {
        if(flyingMode)
        {
            arm.fly();
            glutPostRedisplay();
            glutTimerFunc(dt, timerCallBack, value);
        } else
        { 
            arm.setDisplacement(0.1);
            glutTimerFunc(dt, timerCallBack, 2);
        }
        
    } else if(value == 2)
    {
        
        arm.setFlyDown();
        glutPostRedisplay();
        if(arm.getYarm() == yPosOnPlatform)
            arm.setDisplacement(0.01);

        else if(flyingMode)
            arm.setDisplacement(0.01);
        
        else if(arm.getYarm() < -5)
            glutTimerFunc(dt, timerCallBack, 3);
        else    
            glutTimerFunc(dt, timerCallBack, value);

    } else if(value == 3)
    {
        std::cout << "time do born again, bitch!\n";
    }

}

void Game::keyboardCallBack (unsigned char key, int x, int y) 
{
//    std::cout << "key pressed: " << key << "\n";
	
    switch( key )
	{
		case 27: 	// ESCAPE key
			exit(0);
			break;
        case ' ': 	// ESPACE key
            Camera::riseAngle();
            glutPostRedisplay(); 
			break;

        case '1':
            currentPart = 1;
            break;
        case '2':
            currentPart = 2;
            break;
        case '3':
            currentPart = 3;
            break;
        case 'f':
            if(flyingMode)
            {
                //std::cout << "paraaaaaaaaa \n";
                flyingMode = false;
                timerCallBack(0);
            }
            else
            {
                //std::cout << "vo pedir pra voar __o__ \n";
                flyingMode = true;
                timerCallBack(1);
            }
            break;
    }
}

void Game::specialKeysCallBack(int key, int x, int y)
{
    int modifier = glutGetModifiers();

    switch( key )
    {
        case GLUT_KEY_LEFT:
            if( modifier & GLUT_ACTIVE_CTRL ){
                arm.moveLeft();
                static int count =0;
                std::cout << count++ << " key" << key << "\n";
}             else if(flyingMode)
                arm.setFlyLeft();           
            else
                arm.rotateCounterClockwise(currentPart);
            break;

        case GLUT_KEY_RIGHT:
            if( modifier & GLUT_ACTIVE_CTRL )
                arm.moveRight();
            else if(flyingMode)
                arm.setFlyRight();
            else
                arm.rotateClockwise(currentPart);
            break;

       case GLUT_KEY_UP:
            if( modifier & GLUT_ACTIVE_CTRL )
                arm.moveUp();
            else if(flyingMode)
                arm.setFlyUp();
            else if(Camera::getZoom() > 1)
                Camera::zoomUp();
            break;

       case GLUT_KEY_DOWN:
            if( modifier & GLUT_ACTIVE_CTRL )
                arm.moveDown();
             else if(flyingMode)
                arm.setFlyDown();           
            else if(Camera::getZoom() < 20)
                Camera::zoomDown();
            break;
    }
    glutPostRedisplay(); 
}

void Game::displayCallBack()
{
    fps.newFrame();

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    Camera::updateCamera(arm.getXarm(), arm.getYarm(), arm.getZarm());
    platform.draw();
    arm.draw();

    labelFps.setText("FPS: %d", fps.getFps());
    labelFps.draw();

    glutSwapBuffers();
}

void Game::reshapeCallBack(int width, int height)
{
    glViewport (0, 0, (GLsizei) width, (GLsizei) height);
    float ratio = (float)width / (float)height;
    Camera::setWindowRatio(ratio);
    Camera::updateCamera(arm.getXarm(), arm.getYarm(), arm.getZarm());
}

int main(int argc, char** argv)
{
	// forçar saída imediata no console do eclipse
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	Game::run(argc,argv);
	return 0;
}

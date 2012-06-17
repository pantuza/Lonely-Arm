#include "platform.h"
#include "arm.h"
#include "camera.h"
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <iostream>

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

};
Platform Game::platform;
Arm Game::arm;
int Game::currentPart = 1;
bool Game::flyingMode = false;

void Game::run(int argc, char* argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

    glutInitWindowPosition(0,0);
    glutCreateWindow(TITLE);
    glutFullScreen();

    configure();

    glutDisplayFunc(displayCallBack);
    glutKeyboardFunc(keyboardCallBack);
    glutSpecialFunc(specialKeysCallBack);
    glutReshapeFunc(reshapeCallBack);

    glutMainLoop();
}

void Game::configure()
{
     GLfloat placeLight[4]={0.2,0.2,0.2,1.0};
     GLfloat diffusedLight[4]={0.7,0.7,0.7,1.0}; // color 
     GLfloat specularLight[4]={1.0, 1.0, 1.0, 1.0}; // "brightness" 
     GLfloat lightPosition[4]={10.0, 10.0, 1.0, 1.0}; // light position variation

     glShadeModel (GL_FLAT);

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

//    glEnable(GL_CULL_FACE);
}

void Game::timerCallBack(int value)
{
    if(value == 1)
    {
        if(flyingMode)
        {
            std::cout << "to voando cara \n";
            arm.fly(true);
            glutPostRedisplay();
            glutTimerFunc(5, timerCallBack, value);
        }
    } else
    {
        arm.fly(false);
        glutPostRedisplay();
    }
    std::cout << "flying: " << flyingMode << "\n";
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
                std::cout << "paraaaaaaaaa \n";
                flyingMode = false;
                timerCallBack(0);
            }
            else
            {
                std::cout << "vo pedir pra voar __o__ \n";
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
            if( modifier & GLUT_ACTIVE_CTRL )
                arm.moveLeft();
             else if(flyingMode)
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
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    platform.draw();
    arm.draw();
    Camera::updateCamera(arm.getXarm(), arm.getYarm(), arm.getZarm());
    glutSwapBuffers();
}

void Game::reshapeCallBack(int width, int height)
{
    glViewport (0, 0, (GLsizei) width, (GLsizei) height);
    Camera::updateCamera(arm.getXarm(), arm.getYarm(), arm.getZarm());
}

int main(int argc, char** argv)
{
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    Game::run(argc,argv);
	return 0;
}

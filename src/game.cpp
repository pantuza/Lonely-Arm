#include "platform.h"
#include "arm.h"
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <iostream>

#define TITLE "Lonely Arm"
#define VERSION "Beta"
#define PI 3.14159265

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
        static void updateCamera();
        static double ratio;
        static float zoom;
        static int currentPart;
        static float angle;
        static bool flyingMode;

};

Platform Game::platform;
Arm Game::arm;
double Game::ratio = 1;
int Game::currentPart = 1;
float Game::zoom = 1;
float Game::angle = 45;
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
    glShadeModel (GL_FLAT);
    glEnable(GL_CULL_FACE);
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
            angle++;
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
            flyingMode = !flyingMode;

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
            else if(zoom < 10)
                zoom += 0.1;
            break;

       case GLUT_KEY_DOWN:
            if( modifier & GLUT_ACTIVE_CTRL )
                arm.moveDown();
             else if(flyingMode)
                arm.setFlyDown();           
            else if(zoom > 3)
                zoom -= 0.1;
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
    
    updateCamera();
    glutSwapBuffers();
}

void Game::reshapeCallBack(int width, int height)
{
    glViewport (0, 0, (GLsizei) width, (GLsizei) height);
    ratio = (double)width / (double)height;
    updateCamera();
}

void Game::updateCamera()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 2, 1, 30);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(cos(angle*PI/180), sin(angle*PI/180), zoom, 0, 0, 1, 0, 1, 0 );
}

int main(int argc, char** argv)
{
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    Game::run(argc,argv);
	return 0;
}

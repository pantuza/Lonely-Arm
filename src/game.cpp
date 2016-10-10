#include "platform.h"
#include "arm.h"
#include "camera.h"
#ifdef __APPLE__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif
#include <math.h>
#include <stdio.h>
#include <iostream>
#include "text.h"
#include "fps.h"

#define TITLE "Lonely Arm"
#define VERSION "1.0"
#define FPS     120
/**
 * Game Class is responsible to control all the game.
 * It controls the GLUT callbacks calls, draw the 
 * platform and arm on the space and udate the camera.
 *
 * Everything is static because it is used by GLUT for 
 * callback functions. Class Methods are not accepted.
 * Static methods are used because it behaves like predefined
 * functions
 */
class Game
{
    public:
        static void run(int argc, char* argv[]);
    private:
        static int currentPart;
        static bool flyingMode;
        static int dt;
        static int lifes;

        static Platform platform;
        static Arm arm;
        static Fps fps;
        static Text labelFps;
        static Text labelLifes;
        static Text labelGameOver;
        static Text labelAxis;
        static Text labelCurrentPart;

        static void configure();
        static void timerCallBack(int value);
        static void keyboardCallBack(unsigned char key, int x, int y);
        static void specialKeysCallBack(int key, int x, int y);
        static void displayCallBack();
        static void reshapeCallBack(int width, int height);
};

int Game::currentPart = 1;
bool Game::flyingMode = false;
int Game::dt = (1000/FPS);
int Game::lifes = 5;
Platform Game::platform;
Arm Game::arm;
Fps Game::fps;
Text Game::labelFps;
Text Game::labelLifes;
Text Game::labelGameOver;
Text Game::labelAxis;
Text Game::labelCurrentPart;

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
    labelLifes.setPosition(-0.95, 0.95, 0);
    labelGameOver.setPosition(0, 0, 0);
    labelGameOver.setFontStyle(GLUT_BITMAP_HELVETICA_18);    
    labelGameOver.setText("Game Over");
    labelAxis.setPosition(-0.95, 0.90, 0);
    labelCurrentPart.setPosition(-0.95, 0.85, 0);

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
        labelLifes.setText("Lifes: %d", --lifes);
        glutPostRedisplay();
        arm.reset();
    }

}

void Game::keyboardCallBack (unsigned char key, int x, int y) 
{
    switch( key )
	{
		case 27: // ESCAPE key
			exit(0);
			break;
        case ' ': // ESPACE key
            Camera::riseAngle();
			break;

        case '1':
            currentPart = 1;
            labelCurrentPart.setText("Selected Part: Arm");
            break;
        case '2':
            currentPart = 2;
            labelCurrentPart.setText("Selected Part: Fore Arm");
            break;
        case '3':
            currentPart = 3;
            labelCurrentPart.setText("Selected Part: Hand");
            break;
        case 'f':
            if(flyingMode)
            {
                flyingMode = false;
            }
            else
            {
                arm.resetRotations();
                flyingMode = true;
                timerCallBack(1);
            }
            break;
        case 'r':
            arm.reset();
            Camera::resetCamera();
            break;
    }
    glutPostRedisplay();
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
    glLoadIdentity();

    fps.newFrame();

    if(lifes == 0)
    {
        labelGameOver.draw();
        glutSwapBuffers();
        return;
    }

    Camera::updateCamera(arm.getXarm(), arm.getYarm(), arm.getZarm());
    platform.draw();
    arm.draw();

    labelFps.setText("FPS: %d", fps.getFps());
    labelLifes.setText("Lifes: %d", lifes);
    labelAxis.setText("Arm axis: x: %.3f   y: %.3f   z: %.3f", 
                                arm.getXarm(), arm.getYarm(), arm.getZarm());

    labelFps.draw();
    labelLifes.draw();
    labelAxis.draw();
    labelCurrentPart.draw();

    glutSwapBuffers();
}

void Game::reshapeCallBack(int width, int height)
{
    glViewport (0, 0, (GLsizei) width, (GLsizei) height);
    float ratio = (float)width / (float)height;
    Camera::setWindowRatio(ratio);
    Camera::updateCamera(arm.getXarm(), arm.getYarm(), arm.getZarm());
}

/**
 * Main execution of the Lonely Arm program
 */
int main(int argc, char** argv)
{
	/** uncomment this lines to enable console print on eclipse IDE */
	// setvbuf(stdout, NULL, _IONBF, 0);
	// setvbuf(stderr, NULL, _IONBF, 0);

	Game::run(argc,argv);
	return 0;
}

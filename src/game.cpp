#include "platform.h"
#include "arm.h"
#include <GL/glut.h>

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
        static void displayCallBack();
        static void reshapeCallBack(int width, int height);
};

Platform Game::platform;
Arm Game::arm;

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
       glutReshapeFunc(reshapeCallBack);

	   glutMainLoop();
}

void Game::configure()
{
    glShadeModel (GL_FLAT);
}

void Game::keyboardCallBack (unsigned char key, int x, int y) 
{
    std::cout << "key pressed: " << key << "\n";
	switch (key)
	{
		case 27: 	// ESCAPE key
			exit(0);
			break;
        case GLUT_KEY_LEFT:
            arm.rotateCounterClockwise();
            break;
        case GLUT_KEY_RIGHT:
            std::cout << "teste\n";
            arm.rotateClockwise();
            break;
	}
}

void Game::displayCallBack()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);

    platform.draw();
    arm.draw();

    glutSwapBuffers();
}

void Game::reshapeCallBack(int width, int height)
{
    glViewport (0, 0, (GLsizei) width, (GLsizei) height);

    glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        double ratio = (double)width / (double)height;
        glOrtho(-1, 1, -1/ratio, 1/ratio, 0, 50);
        gluLookAt(0, 0, -1, 0, 0, 0, 0, 1, 0);
        glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    Game::run(argc,argv);
	return 0;
}

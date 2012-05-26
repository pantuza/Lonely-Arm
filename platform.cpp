#include <string>

#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>


using namespace std;


class Platform
{
	public:
		Platform(int , char**);
		static void test();
	private:
		string testa;
		void init();

};

void Platform::test()
{
	glutSwapBuffers();
}
void Platform::init()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glShadeModel (GL_FLAT);
}
Platform::Platform(int argc, char** argv)
{
	   testa = "olaaaa";
	   glutInit(&argc,argv);
	   glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

	   glutInitWindowPosition(0,0);
	   glutCreateWindow(testa.c_str());
	   glutFullScreen();
	   init();
	   glutDisplayFunc(Platform::test);

	   glutMainLoop();
}

int main(int argc, char** argv)
{
	Platform plat(argc,argv);
	return 0;
}



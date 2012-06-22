#include <stdio.h>
#include <stdarg.h>
#include "text.h"

Text::Text()
	: message()
{
	x = y = z = 0;
	font_style = GLUT_BITMAP_HELVETICA_12;
}

Text::~Text() {
}

void Text::setFontStyle(GLvoid *fs) {
	font_style = fs;
}

void Text::setText(std::string& msg)
{
	message = msg;
}

void Text::setText(const char* format, ...)
{
	va_list args;	//  Variable argument list
	int len;		
	char* text;	

	//  Initialize a variable argument list
	va_start(args, format);

	// Number of characteres
    len = 1024;

	//  Allocate memory for a string of the specified size
	text = (char *)malloc(len);

	//  Write formatted output using a pointer to the list of arguments
	vsprintf(text, format, args);

	//  End using variable argument list
	va_end(args);

	message = text;

    //  Free the allocated memory for the string
	free(text);
}

void Text::setPosition(double _x, double _y, double _z)
{
	x = _x;
	y = _y;
	z = _z;
}

void Text::draw()
{
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
		glLoadIdentity();
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
			glLoadIdentity();
			//  Specify the raster position for pixel operations.
            glRasterPos3d(x, y, z);
			const char *text = message.c_str();
			//  Draw the characters one by one
		    for (int i = 0; text[i] != '\0'; i++)
		        glutBitmapCharacter(font_style, text[i]);
		glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
}


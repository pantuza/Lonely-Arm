/*
 * Text.cpp
 *
 *  Created on: 16/06/2012
 *      Author: dev
 */

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

//  Pointer to a font style..
//  Fonts supported by GLUT are: GLUT_BITMAP_8_BY_13,
//  GLUT_BITMAP_9_BY_15, GLUT_BITMAP_TIMES_ROMAN_10,
//  GLUT_BITMAP_TIMES_ROMAN_24, GLUT_BITMAP_HELVETICA_10,
//  GLUT_BITMAP_HELVETICA_12, and GLUT_BITMAP_HELVETICA_18.
//

void Text::setFontStyle(GLvoid *fs) {
	font_style = fs;
}

//----------------------------------------------------------------------------
void Text::setText(std::string& msg)
{
	message = msg;
}

void Text::setText(const char* format, ...)
{
	va_list args;	//  Variable argument list
	int len;		//	String length
	char* text;	//	Text

	//  Initialize a variable argument list
	va_start(args, format);

	//  Return the number of characters in the string referenced the list of
	// arguments. _vscprintf doesn't count terminating '\0' (that's why +1)
	len = 1024;// _vscprintf(format, args) + 1;

	//  Allocate memory for a string of the specified size
	text = (char *)malloc(len);

	//  Write formatted output using a pointer to the list of arguments
	vsprintf(text, format, args);
	//len = vsprintf(text, format, args);

	//  End using variable argument list
	va_end(args);

	//
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
	// Salva o sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
		// Zera o sistema de coordenadas de projeção
		glLoadIdentity();
		// Salva sistema de coordenadas do modelo
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
			// Zera o sistema de coordenadas do modelo
			glLoadIdentity();
			// Imprime o texto
			//  Specify the raster position for pixel operations.
			glRasterPos3d (x, y, z);
			//
			const char *text = message.c_str();
			//  Draw the characters one by one
		    for (int i = 0; text[i] != '\0'; i++)
		        glutBitmapCharacter(font_style, text[i]);
			// Retorna o sistema de coordenadas do modelo
		glPopMatrix();
	// Retorna o sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
}

/*
 * Text.h
 *
 *  Created on: 16/06/2012
 *      Author: dev
 */

#ifndef TEXT_H_
#define TEXT_H_

#include <GL/glut.h>
#include <string>

class Text {
private:
	std::string message;
	double x, y, z;
	GLvoid *font_style;
public:
	Text();
	virtual ~Text();
	void setFontStyle(GLvoid *);
	void setText(std::string&);
	void setText(const char* format, ...);
	void setPosition(double, double, double);
	virtual void draw();
};

#endif /* TEXT_H_ */

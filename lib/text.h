#ifndef TEXT_H_
#define TEXT_H_

#ifdef __APPLE__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif
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
	void draw();
};

#endif /* TEXT_H_ */

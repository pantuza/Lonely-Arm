#ifndef PLATFORM_H_
#define PLATFORM_H_

#include <string>

using namespace std;

class Platform {

public:
	Platform(int , char**);

private:
	string title;

	static void KeyboardCallback (unsigned char key, int x, int y);
	static void displayCallback();
	void init();

};

#endif

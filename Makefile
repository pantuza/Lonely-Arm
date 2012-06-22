#
# Makefile for the Lonely-Arm project
#
# Rules Description:
# 	. all   - Compile the project
# 	. edit  - open all project files on separated tabs on VIM Editor
# 	. clean - clean the obj and bin directory contents
# 	. run	- compiles the project, then run the /bin/lonely-arm binary file
#
# 	author : Gustavo Pantuza
# 	since  : 10.06.2012
#

BIN=bin/
SRC=src/
LIB=lib/
OBJ=obj/

all:	${BIN}lonely-arm

${BIN}lonely-arm:   ${OBJ}camera.o ${OBJ}arm.o ${OBJ}platform.o ${OBJ}parts.o ${OBJ}game.o ${OBJ}fps.o ${OBJ}text.o
	@/bin/echo -e "\n\e[1;34mCompiling obeject files:\e[0m"
	g++ -o ${BIN}lonely-arm ${OBJ}platform.o ${OBJ}camera.o ${OBJ}game.o ${OBJ}arm.o ${OBJ}parts.o ${OBJ}fps.o ${OBJ}text.o -lGLU -lGL -lglut

${OBJ}camera.o: ${SRC}camera.cpp
	g++ -O0 -g3 -Wall -I${LIB} -c -fmessage-length=0 -o ${OBJ}camera.o ${SRC}camera.cpp

${OBJ}game.o:	${SRC}game.cpp
	g++ -O0 -g3 -Wall -I${LIB} -c -fmessage-length=0 -o ${OBJ}game.o ${SRC}game.cpp

${OBJ}arm.o:	${SRC}arm.cpp
	g++ -O0 -g3 -Wall -I${LIB} -c -fmessage-length=0 -o ${OBJ}arm.o ${SRC}arm.cpp

${OBJ}platform.o:	${SRC}platform.cpp
	g++ -O0 -g3 -Wall -I${LIB} -c -fmessage-length=0 -o ${OBJ}platform.o ${SRC}platform.cpp

${OBJ}parts.o:	${SRC}parts.cpp
	g++ -O0 -g3 -Wall -I${LIB} -c -fmessage-length=0 -o ${OBJ}parts.o ${SRC}parts.cpp

${OBJ}fps.o:	${SRC}fps.cpp
	g++ -O0 -g3 -Wall -I${LIB} -c -fmessage-length=0 -o ${OBJ}fps.o ${SRC}fps.cpp

${OBJ}text.o:	${SRC}text.cpp
	g++ -O0 -g3 -Wall -I${LIB} -c -fmessage-length=0 -o ${OBJ}text.o ${SRC}text.cpp

edit:	
	vim -p Makefile src/* lib/*

clean:	
	@/bin/echo -e "\n\e[1;34mCleaning project...\e[0m"
	@rm -rf ${OBJ}*.o
	@rm -f ${BIN}lonely-arm

run:	all
	./${BIN}lonely-arm

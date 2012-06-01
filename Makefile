BIN=bin/
SRC=src/
LIB=lib/
OBJ=obj/

all:	${BIN}lonely-arm

${BIN}lonely-arm:	${OBJ}game.o ${OBJ}arm.o ${OBJ}platform.o ${OBJ}parts.o
	@echo -e "\n\e[1;34mCompiling obeject files:\e[0m"
	g++ -o ${BIN}lonely-arm ${OBJ}platform.o ${OBJ}game.o ${OBJ}arm.o ${OBJ}parts.o -lGLU -lGL -lglut

${OBJ}game.o:	${SRC}game.cpp
	g++ -O0 -g3 -Wall -I${LIB} -c -fmessage-length=0 -o ${OBJ}game.o ${SRC}game.cpp
	
${OBJ}arm.o:	${SRC}arm.cpp
	g++ -O0 -g3 -Wall -I${LIB} -c -fmessage-length=0 -o ${OBJ}arm.o ${SRC}arm.cpp

${OBJ}platform.o:	${SRC}platform.cpp
	g++ -O0 -g3 -Wall -I${LIB} -c -fmessage-length=0 -o ${OBJ}platform.o ${SRC}platform.cpp

${OBJ}parts.o:	${SRC}parts.cpp
	g++ -O0 -g3 -Wall -I${LIB} -c -fmessage-length=0 -o ${OBJ}parts.o ${SRC}parts.cpp

clean:	
	@echo -e "\n\e[1;34mCleaning project...\e[0m"
	@rm -rf ${OBJ}*.o
	@rm -f ${BIN}lonely-arm

run:	all
	./${BIN}lonely-arm

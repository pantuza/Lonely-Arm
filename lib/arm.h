#ifndef ARM_H_
#define ARM_H_
#include "parts.h"
class Arm
{
    public:
        Arm();
        void draw();
        void rotateClockwise();
        void rotateCounterClockwise();
        void rotateClockwise2();
        void rotateCounterClockwise2();
        void moveLeft();
        void moveRight();
        void moveUp();
        void moveDown();

   private:
        float rotation;
        float rotation2;
        float xPosition;
        float zPosition;
        export Parts armParts;
        const float DISPLACEMENT;
        const int ROTATION_FACTOR;
};

#endif // ARM_H_

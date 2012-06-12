#ifndef ARM_H_
#define ARM_H_
#include "parts.h"
class Arm
{
    public:
        Arm();
        void draw();
        void rotateClockwise(int part);
        void rotateCounterClockwise(int part);
        
        void moveLeft();
        void moveRight();
        void moveUp();
        void moveDown();

   private: 
        
        float armRotation;
        float foreArmRotation;

        float xPosition;
        float zPosition;
        Parts armParts;

        const float DISPLACEMENT;
        const int ROTATION_FACTOR;
};

#endif // ARM_H_

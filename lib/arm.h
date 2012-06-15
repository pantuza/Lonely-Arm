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
        void setFlyDown();
        void setFlyUp();
        void setFlyRight();
        void setFlyLeft();

   private: 
        void drawBase();
        float armRotation;
        float foreArmRotation;

        Parts armParts;

        float xFlightPosition;
        float yFlightPosition;
        float zFlightPosition;

        const float DISPLACEMENT;
        const int ROTATION_FACTOR;
};

#endif // ARM_H_

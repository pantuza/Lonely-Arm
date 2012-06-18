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
       
        inline float getXarm() {return xFlightPosition;};
        inline float getZarm() {return zFlightPosition;};
        inline float getYarm() {return yFlightPosition;};
        inline void setDisplacement(float disp) {displacement = disp;};
        void moveLeft();
        void moveRight();
        void moveUp();
        void moveDown();
        void setFlyDown();
        void setFlyUp();
        void setFlyRight();
        void setFlyLeft();
        void fly();

   private: 
        void drawBase();
        float armRotation;
        float foreArmRotation;
        
        Parts armParts;

        float xFlightPosition;
        float yFlightPosition;
        float zFlightPosition;

        float displacement;
        const int ROTATION_FACTOR;
};

#endif // ARM_H_

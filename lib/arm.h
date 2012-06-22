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

        void reset();
        void resetRotations();
        void moveLeft();
        void moveRight();
        void moveUp();
        void moveDown();

        void fly();
        void setFlyDown();
        void setFlyUp();
        void setFlyRight();
        void setFlyLeft();

   private: 
        float armRotation;
        float foreArmRotation;
        float displacement;
        Parts armParts;

        float xFlightPosition;
        float yFlightPosition;
        float zFlightPosition;

        const int ROTATION_FACTOR;

        void drawBase();
        bool collidedOnXAxis();
        bool collidedOnYAxis();
        bool needReposition();
};

#endif // ARM_H_

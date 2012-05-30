#ifndef ARM_H_
#define ARM_H_

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
   private:
        float rotation;
        float rotation2;
        float direction;
        const float DISPLACEMENT;
        const int ROTATION_FACTOR;
};

#endif // ARM_H_

#ifndef ARM_H_
#define ARM_H_

class Arm
{
    public:
        Arm();
        void draw();
        void rotateClockwise();
        void rotateCounterClockwise();
    private:
        float rotation;
};

#endif // ARM_H_

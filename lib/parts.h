#ifndef PART_H_
#define PART_H_
class Parts
{
    public:
        Parts();
        
        void pushParts();

        void setArmRotation(float rotation);
        void setForeArmRotation(float rotation);
        void setBaseArmRotation(float rotation);

        void setFingerAngle(float angle);

        void rotateHand();
        void closeHand();
        void openHand();

    private:
        /* Attributes */
        float partHeight;
        float handHeight;

        float baseArmRotation;
        float armRotation;
        float foreArmRotation;
        float handRotation;

        float jointRadius;
        float basePartRadius;
        float topPartRadius;
        
        float slices;
        float stacks;
        
        float fingerAngle;       
        /* Methods */
        void drawPart(float rotation);
        void drawJoint();
        void drawHand();
};
#endif /* PART_H_ */


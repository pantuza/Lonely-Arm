#ifndef CAMERA_H_
#define CAMERA_H_

#define PI 3.14159265

class Camera 
{
    private:
        static float eyeX;
        static float eyeY;
        static float eyeZ;
        static float angle;
        static float zoom;
        static float windowRatio;
        
    public:
        inline static float getEyeX() {return eyeX;};
        inline static void setEyeX(float xLookTo) {eyeX = xLookTo;};
        inline static float getEyeY() {return eyeY;};
        inline static void setEyeY(float yLookTo) {eyeY = yLookTo;};
        inline static float getEyeZ() {return eyeZ;};
        inline static void setEyeZ(float zLookTo) {eyeZ = zLookTo;};
        inline static float getZoom() { return zoom;};
        inline static void zoomUp() {zoom -= 0.1;};
        inline static void riseAngle(){angle++;};
        inline static void zoomDown() {zoom += 0.1;};
        inline static void setWindowRatio(float ratio) {windowRatio = ratio;};
        static void updateCamera(float xArma, float yArm, float zArm);        
};
#endif

#ifndef CAMERA_H_
#define CAMERA_H_

#define PI 3.14159265
/**
 * Camera Class that controls camera rotation, visualization
 * angles and zoom on the space
 *
 * Everything is static because it is used by GLUT for 
 * callback functions. Class Methods are not accepted.
 * Static methods are used because it behaves like predefined
 * functions 
 */
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
        inline static void zoomDown() {zoom += 0.1;};

        inline static void riseAngle(){angle++;};
        inline static void setWindowRatio(float ratio) {windowRatio = ratio;};

        static void updateCamera(float xArma, float yArm, float zArm);        
        static void resetCamera();
};
#endif


#include "HUD.h"
#include <iostream>

HUD::HUD(){
    std::string filename = "assets/hud1.ppm";
    int len = filename.size();
    char * HUDfilename = new char[len + 1];
    std::copy(filename.begin(), filename.end(), HUDfilename);
    HUDfilename[len] = '\0';
    this->mImage = LoadPPM(HUDfilename, &mWidth, &mHeight);
}

void HUD::draw(int xRasterPosition, int yRasterPosition) {
    glRasterPos2i(xRasterPosition + this->mWidth, yRasterPosition);
    glPixelZoom(-1, 1);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glDrawPixels(mWidth, mHeight, GL_RGB, GL_UNSIGNED_BYTE, this->mImage);
}

void HUD::setOrthographicProjection(int* viewportWidth, int* viewportHeight) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, (*viewportWidth), 0, (*viewportHeight));
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void HUD::changeLevel(int selectedLevel){
    std::string filename = "assets/hud1.ppm";

    switch (selectedLevel){
        case (2):
            filename = "assets/hud2.ppm";
            break;
        case(3):
            filename = "assets/hud3.ppm";
            break;
        case(4):
            filename = "assets/hud4.ppm";
            break;
        case(5):
            filename = "assets/hud5.ppm";
            break;
        default:
            break;
    }

    int len = filename.size();
    char * HUDfilename = new char[len + 1];
    std::copy(filename.begin(), filename.end(), HUDfilename);
    HUDfilename[len] = '\0';
    this->mImage = LoadPPM(HUDfilename, &mWidth, &mHeight);
}
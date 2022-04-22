#include "raylib.h"
#include "libs/raygui/raygui.h"

#include "qol.hpp"

//Assumes raylib and raygui are already initialised
namespace screens
{
    void DrawInfo(int width, int height, int posX, int posY){
        int centerX = posX+width/2;
        int centerY = posY+height/2;
        qol::DrawTextCentered("OPALFORGE", centerX, centerY-45, 40, BLACK); // These are spaced weirdly but it looked right like this shut up
        qol::DrawTextCentered("creative swiss army knife", centerX, centerY-7, 20, GRAY);
        qol::DrawTextCentered("made with annoyance by glyphli & friends", centerX, centerY+15, 20, LIGHTGRAY);
        qol::DrawTextCentered("ver. 0.0.0d", centerX, height-20, 20, LIGHTGRAY);
    }

    // TOOL CATEGORIES //
    void DrawTest(int width, int height, int posX, int posY);
    
    // TEST TOOLS //
    void DrawBarebones(int width, int height, int posX, int posY){
        int centerX = posX+width/2;
        int centerY = posY+height/2;
        qol::DrawTextCentered("throbb1ng BALLS", centerX, centerY-40, 80, BLACK);
    }

}
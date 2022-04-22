#include "raylib.h"
#include "libs/raygui/raygui.h"

namespace qol
{
    void DrawTextCentered(const char *text, int posX, int posY, int fontSize, Color color){
        DrawText(text, posX-(MeasureText(text, fontSize)/2), posY, fontSize, color);
    }
}
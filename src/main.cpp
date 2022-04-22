#include "raylib.h"

#define TESTBUILD

#define RAYGUI_IMPLEMENTATION
#include "libs/raygui/raygui.h"

#include "screens.hpp"
#include "widgets.hpp"

int main()
{
    // INITIALIZATION //
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Opalforge 0.0.0d");
    SetTargetFPS(60);

    #ifdef TESTBUILD
        int testToolID = 0;
    #endif

    int categoryID = 0;
    int audioToolID = 0;
    int imageToolID = 0;

    int iconWidth = MeasureText("#00#", 10)-1;

    const int sidebarWidth = 40;
    const int sidebarIconOffset = sidebarWidth/2 - iconWidth/2;

//==============================================================================================

    // MAIN LOOP //
    while (!WindowShouldClose())
    {
        BeginDrawing();

            ClearBackground(WHITE);

            // BODY //
            switch (categoryID) // This happens every frame, will need to think up a better system
            {                   // for navigating between screens eventually but for now this works
            case 0: // Info //
                screens::DrawInfo(screenWidth-sidebarWidth, screenHeight, sidebarWidth, 0);
                break;
            
            case 1: // Audio //
                //draw buffer preview at bottom of screen + transport controls//
                break;

            case 2: // Image //
                break;

            #ifdef TESTBUILD
                case 999: // Test //
                    screens::DrawBarebones(screenWidth-sidebarWidth, screenHeight, sidebarWidth, 0);
                    break;
            #endif

            default:
                break;
            }

            // SIDEBAR //
            DrawRectangle(0, 0, sidebarWidth, screenHeight, LIGHTGRAY);
            GuiSetStyle(BUTTON, TEXT_ALIGNMENT, GUI_TEXT_ALIGN_CENTER);
            if (GuiButton((Rectangle){sidebarIconOffset, sidebarIconOffset, iconWidth, iconWidth}, "#124#")) categoryID = 1;// Audio //
            if (GuiButton((Rectangle){sidebarIconOffset, iconWidth + sidebarIconOffset*2, iconWidth, iconWidth}, "#12#")) categoryID = 2;// Image //

            if (GuiButton((Rectangle){sidebarIconOffset, screenHeight - (iconWidth+sidebarIconOffset), iconWidth, iconWidth}, "#15#")) categoryID = 0;// Info //

            #ifdef TESTBUILD
                if (GuiButton((Rectangle){sidebarIconOffset, screenHeight - (iconWidth+sidebarIconOffset)*2, iconWidth, iconWidth}, "#193#")) categoryID = 999;// Test //
            #endif

        EndDrawing();
    }

//==============================================================================================

    // DE-INITIALIZATION //
    CloseWindow();

    return 0;
}

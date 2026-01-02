#include <iostream>

#include <raylib.h>
#include <raymath.h>

#include "definitions.hpp"

int w = SCREEN_WIDTH;
int h = SCREEN_HEIGHT;

Color bgColor = BG_COLOR;
Color fgColor = {static_cast<unsigned char>(255 - bgColor.r),
                 static_cast<unsigned char>(255 - bgColor.g),
                 static_cast<unsigned char>(255 - bgColor.b),
                 255}; // Opposite of background color

using namespace std;
void handleEvents();
void handleWindowResize();
int main()
{

    SetTargetFPS(SCREEN_FPS);
    SetTraceLogLevel(LOG_ERROR);
    if (IS_RESIZABLE)
    {
        SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    }

    InitWindow(w, h, SCREEN_TITLE);

    SetWindowMinSize(MIN_WIDTH, MIN_HEIGHT);
    SetWindowMonitor(GetCurrentMonitor());

    int monitor = GetCurrentMonitor();
    w = GetMonitorWidth(monitor);
    h = GetMonitorHeight(monitor);

    if (IS_WINDOWED)
        SetWindowSize(w, h);

    if (IS_WINDOWED && IS_FULLSCREEN)
        ToggleFullscreen();

    cout << "width: " << w << "\theight: " << h << "\n";

    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(bgColor);
        // start

        if (IsWindowResized())
            handleWindowResize();
        if (IS_EVENTS_FOCUSED_ONLY)
        {
            if (IsWindowFocused())
                handleEvents();
        }
        else
            handleEvents();

        // end
        EndDrawing();
    }
    return 0;
}

void handleEvents()
{
}

void handleWindowResize()
{

    w = GetScreenWidth();
    h = GetScreenHeight();
}
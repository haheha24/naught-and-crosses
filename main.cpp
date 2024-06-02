#include "raylib.h"
#include "Grid.h"
#include <iostream>

int main()
{
    const int windowWidth = 600;
    const int windowHeight = 600;
    InitWindow(windowWidth, windowHeight, "Naughts and Crosses");

    Vector2 mousePoint{ 0.f, 0.f };

    // Initialise the grid class
    float innerSquare{ 400.f };
    Grid grid(
        Rectangle{
            (static_cast<float>((windowWidth - innerSquare) / 2)), // x = (parent width - child width) / 2
            (static_cast<float>((windowHeight - innerSquare) / 2)), // y = (parent height - child height) / 2
            innerSquare,
            innerSquare
        }
    );
    Texture2D naught{ LoadTexture("textures/naught.png") };
    Texture2D cross{ LoadTexture("textures/cross.png") };

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        // update logic
        mousePoint = GetMousePosition();

        if (grid.getTurn())
        {
            grid.setTexture(naught, mousePoint);
        }
        else if (!grid.getTurn())
        {
            grid.setTexture(cross, mousePoint);
        }

        // begin drawing
        BeginDrawing();
        ClearBackground(GRAY);

        grid.drawGrid();

        // end drawing
        EndDrawing();
    }

    // unload textures and close window
    UnloadTexture(naught);
    UnloadTexture(cross);
    CloseWindow();
}
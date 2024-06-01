#include "raylib.h"
#include "Grid.h"

int main()
{
    const int windowWidth = 600;
    const int windowHeight = 600;
    InitWindow(windowWidth, windowHeight, "Naughts and Crosses");

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
    grid.setupGrid();
    Texture2D naught{ LoadTexture("textures/naught.png") };
    Texture2D cross{ LoadTexture("textures/cross.png") };

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        // begin drawing
        BeginDrawing();
        ClearBackground(GRAY);

        grid.drawGrid();


        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            grid.setTexture(cross, grid.getGridElement(1, 1));
        }

        // end drawing
        EndDrawing();
    }

    // unload textures and close window
    CloseWindow();
}
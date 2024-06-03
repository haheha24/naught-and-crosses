#include "raylib.h"
#include "Grid.h"
#include "Button.h"

int main()
{
    const int windowWidth = 600;
    const int windowHeight = 600;
    InitWindow(windowWidth, windowHeight, "Naughts and Crosses");
    SetExitKey(KEY_NULL);

    bool exitWindowRequested = false;
    bool exitWindow = false;

    // load textures
    Texture2D naught{ LoadTexture("textures/naught.png") };
    Texture2D cross{ LoadTexture("textures/cross.png") };
    Texture2D menuBtns{ LoadTexture("textures/menu-buttons-sprite-bnw.png") };

    //initialise general variables
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

    //initialise newGameBtn
    float newGameBtnFrameHeight = static_cast<float>(menuBtns.height / 5);
    float newGameBtnScale{ 0.25 };
    Rectangle newGameSrcRec{
        0,
        newGameBtnFrameHeight * 3,
        static_cast<float>(menuBtns.width / 3.75),
        newGameBtnFrameHeight
    };
    Rectangle newGameDestRec{
        windowWidth - newGameSrcRec.width * newGameBtnScale,
        0,
        static_cast<float>((menuBtns.width / 3.75) * newGameBtnScale),
        newGameBtnFrameHeight * newGameBtnScale
    };
    Button newGameBtn(menuBtns, newGameSrcRec, newGameDestRec);

    SetTargetFPS(60);
    while (!exitWindow)
    {
        // update logic
        //---------------------------------------------------------------------------------------
        if (WindowShouldClose() || IsKeyPressed(KEY_ESCAPE)) exitWindowRequested = true;
        if (exitWindowRequested)
        {
            if (IsKeyPressed(KEY_Y)) exitWindow = true;
            else if (IsKeyPressed(KEY_N)) exitWindowRequested = false;
        }

        mousePoint = GetMousePosition();

        // check new game button state
        newGameBtn.click(mousePoint);
        if (newGameBtn.getBtnAction())
        {
            grid.reset();
            newGameBtn.setBtnAction(false);
        }

        // player turn
        if (grid.getTurn())
        {
            grid.setTexture(naught, mousePoint);
        }
        else if (!grid.getTurn())
        {
            grid.setTexture(cross, mousePoint);
        }

        //---------------------------------------------------------------------------------------
        // begin drawing
        BeginDrawing();
        ClearBackground(BLACK);

        newGameBtn.draw();
        grid.drawGrid();

        if (exitWindowRequested)
        {
            DrawRectangle(0, 100, windowWidth, 200, Color{100, 100, 100, 200});
            DrawText("Are you sure you want\n\nto exit the program?\n\n\n[Y/N]", 40, 180, 30, WHITE);
        }
        // end drawing
        EndDrawing();
    }

    // unload textures and close window
    UnloadTexture(naught);
    UnloadTexture(cross);
    CloseWindow();
}
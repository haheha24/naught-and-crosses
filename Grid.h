#ifndef GRID_H
#define GRID_H

#include "raylib.h"

class Grid {
public:
    Grid(Rectangle rec);
    struct Cell
    {
        int y{}; //col
        int x{};  //row
        bool blank{ true };
        int player{};
        Texture2D tex{ LoadTexture("textures/blank.png") };
        Rectangle rec{};
        Rectangle source{};
        Rectangle dest{};
    };
    void drawGrid();
    void setTexture(Texture2D texture, Vector2 mousePoint);
    // true == naught, false == cross (starts as true)
    bool getTurn() { return turn; }
    void nextTurn() { turn = !turn; }
protected:
    Rectangle container{};
    static const int COLS{ 3 };
    static const int ROWS{ 3 };
    Cell grid[COLS][ROWS];
    const int cellWidth{ static_cast<int>(container.width) / COLS };
    const int cellHeight{ static_cast<int>(container.height) / ROWS };
    float scale{ 0.75 };
private:
    bool turn{ true };
};

#endif // !GRID_H
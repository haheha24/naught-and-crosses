#ifndef GRID_H
#define GRID_H

#include "raylib.h"
#include "raymath.h"
#include <iostream>

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
    Vector2 getCellPos(int col, int row) { return Vector2{ static_cast<float>(grid[col][row].x), static_cast<float>(grid[col][row].y) }; }
    void setTexture(Texture2D texture, int row, int col);
    Rectangle getCellRec(int col, int row) { return  grid[col][row].rec; }

protected:
    Rectangle container{};
    static const int COLS{ 3 };
    static const int ROWS{ 3 };
    Cell grid[COLS][ROWS];
    const int cellWidth{ static_cast<int>(container.width) / COLS };
    const int cellHeight{ static_cast<int>(container.height) / ROWS };
    float scale{ 0.75 };

};

#endif // !GRID_H
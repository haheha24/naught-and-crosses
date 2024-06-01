#ifndef GRID_H
#define GRID_H

#include "raylib.h"
#include "raymath.h"

class Grid {
public:
    Grid(Rectangle rec) :
        container(rec)
    {};
    struct Cell
    {
        int i;
        int j;
        bool blank{ true };
        Texture2D tex;
        Rectangle rec;
    };
    void setupGrid();
    void drawGrid();
    void setTexture(Texture2D texture, Cell cell);
    Cell getGridElement(int col, int row) { return grid[col][row]; }

protected:
    Rectangle container{};
    static const int COLS{ 3 };
    static const int ROWS{ 3 };
    const int cellWidth{ static_cast<int>(container.width) / COLS };
    const int cellHeight{ static_cast<int>(container.height) / ROWS };
    Cell grid[COLS][ROWS];
    float scale{ 0.25 };
private:

};

#endif // !GRID_H
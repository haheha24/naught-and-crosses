#include "Grid.h"


void Grid::setupGrid() {

    for (int i = 0; i < COLS; i++)
    {
        for (int j = 0; j < ROWS; j++)
        {
            grid[i][j] = (Grid::Cell){
                .i = i,
                .j = j,
                .rec = Rectangle {
                    .x = container.x + (i * cellWidth),
                    .y = container.y + (j * cellHeight),
                    .width = static_cast<float>(cellWidth),
                    .height = static_cast<float>(cellHeight)
                }
            };

        }
    }
}

void Grid::drawGrid() {
    DrawRectangle(container.x, container.y, container.width, container.height, WHITE);
    for (int i = 0; i < COLS; i++)
    {
        for (int j = 0; j < ROWS; j++)
        {
            DrawRectangleLines(container.x + (i * cellWidth), container.y + (j * cellHeight), cellWidth, cellHeight, BLACK);
        }
    }
}

void Grid::setTexture(Texture2D texture, Cell cell) {
    cell.tex = texture;
    Vector2 pos = { cell.rec.x + cellWidth / 6, cell.rec.y + cellHeight / 6 };
    DrawTextureEx(cell.tex, pos, {}, scale, WHITE);
    cell.blank = false;
};

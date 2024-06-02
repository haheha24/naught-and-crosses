#include "Grid.h"

Grid::Grid(Rectangle rec) :
    container(rec)
{
    for (int i = 0; i < COLS; i++)
    {
        for (int j = 0; j < ROWS; j++)
        {
            grid[i][j] = (Grid::Cell){
                .y = i,
                .x = j,
                .rec = Rectangle {
                    .x = container.x + (i * cellWidth),
                    .y = container.y + (j * cellHeight),
                    .width = static_cast<float>(cellWidth),
                    .height = static_cast<float>(cellHeight)
                }
            };
            grid[i][j].source = {
                0.f,
                0.f,
                static_cast<float>(grid[i][j].tex.width), static_cast<float>(grid[i][j].tex.height)
            };
            grid[i][j].dest = {
                    grid[i][j].rec.x + cellWidth / 7.5f,
                    grid[i][j].rec.y + cellHeight / 7.5f,
                    grid[i][j].rec.width * scale,
                    grid[i][j].rec.height * scale
            };
        }
    }
};

void Grid::drawGrid() {
    DrawRectangle(container.x, container.y, container.width, container.height, WHITE);
    for (int i = 0; i < COLS; i++)
    {
        for (int j = 0; j < ROWS; j++)
        {
            DrawRectangleLines(container.x + (i * cellWidth), container.y + (j * cellHeight), cellWidth, cellHeight, BLACK);
            DrawTexturePro(grid[i][j].tex, grid[i][j].source, grid[i][j].dest, Vector2{}, 0.f, WHITE);
        }
    }
}

void Grid::setTexture(Texture2D texture, int row, int col) {
    if (grid[col][row].blank)
    {
        grid[col][row].tex = texture;
        grid[col][row].blank;
    }
};

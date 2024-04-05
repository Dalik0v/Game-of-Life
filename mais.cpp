#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ROWS 20
#define COLS 40

void printGrid(int grid[ROWS][COLS]) {
    system("clear"); // Очистка консоли (работает на Unix-подобных системах)
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", grid[i][j] ? '#' : ' ');
        }
        printf("\n");
    }
}

int countNeighbors(int grid[ROWS][COLS], int row, int col) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int nRow = row + i;
            int nCol = col + j;
            if (nRow >= 0 && nRow < ROWS && nCol >= 0 && nCol < COLS && !(i == 0 && j == 0)) {
                count += grid[nRow][nCol];
            }
        }
    }
    return count;
}

void updateGrid(int grid[ROWS][COLS]) {
    int newGrid[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = countNeighbors(grid, i, j);
            if (grid[i][j]) {
                if (neighbors < 2 || neighbors > 3) {
                    newGrid[i][j] = 0;
                } else {
                    newGrid[i][j] = 1;
                }
            } else {
                if (neighbors == 3) {
                    newGrid[i][j] = 1;
                } else {
                    newGrid[i][j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main() {
    int grid[ROWS][COLS] = {0};

    // Пример начального состояния сетки
    grid[5][5] = 1;
    grid[5][6] = 1;
    grid[5][7] = 1;
    grid[6][6] = 1;
    grid[6][7] = 1;
    grid[6][8] = 1;

    // Бесконечный цикл обновления и отображения сетки
    while (1) {
        printGrid(grid);
        updateGrid(grid);
        usleep(200000); // Задержка в микросекундах (200 миллисекунд)
    }

    return 0;
}

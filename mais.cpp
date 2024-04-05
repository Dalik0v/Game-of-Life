#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>   // Для использования std::this_thread::sleep_for
#include <thread>   // Для использования std::this_thread::sleep_for

#define ROWS 10
#define COLS 10

// Функция для отображения сетки в консоли
void printGrid(int grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", grid[i][j] ? '#' : ' ');
        }
        printf("\n");
    }
    printf("\n");
}

// Функция для обновления состояния сетки
void updateGrid(int grid[ROWS][COLS]) {
    int newGrid[ROWS][COLS] = {0}; // Создаем новую пустую сетку

    // Проходим по каждой клетке сетки
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int count = 0;

            // Подсчитываем количество живых соседей для каждой клетки
            for (int ni = i - 1; ni <= i + 1; ni++) {
                for (int nj = j - 1; nj <= j + 1; nj++) {
                    if (ni >= 0 && ni < ROWS && nj >= 0 && nj < COLS && !(ni == i && nj == j)) {
                        count += grid[ni][nj];
                    }
                }
            }

            // Применяем правила игры "Жизнь" для текущей клетки
            if ((grid[i][j] && (count == 2 || count == 3)) || (!grid[i][j] && count == 3)) {
                newGrid[i][j] = 1; // Клетка остается живой
            }
        }
    }

    // Обновляем исходную сетку
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main() {
    int grid[ROWS][COLS] = {0}; // Инициализируем пустую сетку

    // Инициализация случайными значениями
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2; // Заполняем сетку случайными значениями (0 или 1)
        }
    }

    // Бесконечный цикл для обновления и отображения сетки
    while (1) {
        printGrid(grid); // Отображаем текущее состояние сетки
        updateGrid(grid); // Обновляем состояние сетки в соответствии с правилами игры
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Задержка в 0.5 секунды
    }

    return 0;
}

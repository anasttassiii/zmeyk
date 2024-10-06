#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

// Точка
typedef struct {
    int x;
    int y;
} Point;

// Змея
typedef struct {
    Point* body;
    int length;
    int direction;
    int alive;
} Snake;

// Еда
typedef struct {
    Point position;
} Food;

// Игровое поле
typedef struct {
    int width;
    int height;
    Snake snake;
    Food food;
    int score;
} GameField;

// Направление движения
typedef struct {
    int dx;
    int dy;
} Direction;

// Настройки игры
typedef struct {
    int snake_speed;
    int field_width;
    int field_height;
} GameSettings;

// Состояние игры
typedef struct {
    int game_running;
    int game_over;
} GameState;

// Ключ
typedef struct {
    int code;
} Key;

// Массив направлений движения
Direction directions[] = {
    {-1, 0}, // Вверх
    {1, 0},   // Вниз
    {0, -1}, // Влево
    {0, 1}   // Вправо
};
int main()
{
    
}

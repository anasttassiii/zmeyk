﻿#include <iostream>
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
// Инициализация змеи
void init_snake(Snake* snake, int length, int direction) {
    snake->body = (Point*)malloc(length * sizeof(Point)); // Приведение типа
    snake->length = length;
    snake->direction = direction;
    snake->alive = 1;

    // Инициализация тела змеи
    for (int i = 0; i < length; i++) {
        snake->body[i].x = i;
        snake->body[i].y = 0;
    }
}

// Инициализация еды
void init_food(Food* food, GameField* field) {
    srand(time(NULL));
    food->position.x = rand() % field->width;
    food->position.y = rand() % field->height;
}

// Обновление состояния змеи
void update_snake(Snake* snake, GameField* field, Direction direction) {
    // Добавление новой точки
    snake->body[snake->length].x = snake->body[snake->length - 1].x + direction.dx;
    snake->body[snake->length].y = snake->body[snake->length - 1].y + direction.dy;
    snake->length++;

    // Перемещение тела змеи
    for (int i = snake->length - 1; i > 0; i--) {
        snake->body[i] = snake->body[i - 1];
    }
}

// Проверка столкновения змеи с едой
int check_collision_food(Snake* snake, Food* food) {
    return (snake->body[0].x == food->position.x && snake->body[0].y == food->position.y);
}

// Проверка столкновения змеи с границами поля
int check_collision_border(Snake* snake, GameField* field) {
    return (snake->body[0].x < 0 || snake->body[0].x >= field->width ||
        snake->body[0].y < 0 || snake->body[0].y >= field->height);
}

// Проверка самопересечения змеи
int check_collision_snake(Snake* snake) {
    for (int i = 1; i < snake->length; i++) {
        if (snake->body[0].x == snake->body[i].x && snake->body[0].y == snake->body[i].y) {
            return 1;
        }
    }
    return 0;
}
int main() {
    // Инициализация настроек игры
    GameSettings settings;
    settings.snake_speed = 100;
    settings.field_width = 20;
    settings.field_height = 15;

    // Инициализация игрового поля
    GameField field;
    field.width = settings.field_width;
    field.height = settings.field_height;
    field.score = 0;

    // Инициализация змеи
    Snake snake;
    init_snake(&snake, 3, RIGHT);

    // Инициализация еды
    Food food;
    init_food(&food, &field);

    // Инициализация состояния игры
    GameState state;
    state.game_running = 1;
    state.game_over = 0;

    // Игровой цикл
    while (state.game_running) {
        // Обработка нажатия клавиш

        // Обновление состояния змеи
        if (check_collision_food(&snake, &food)) {
            field.score++;
            init_food(&food, &field);
            update_snake(&snake, &field, directions[snake.direction]);
        }
        else {
            update_snake(&snake, &field, directions[snake.direction]);
        }

        // Проверка столкновений
        if (check_collision_border(&snake, &field) || check_collision_snake(&snake)) {
            state.game_over = 1;
            state.game_running = 0;
        }

        // Вывод игрового поля
    }

    // Очистка памяти
    free(snake.body);

    // Вывод финального сообщения
    if (state.game_over) {
        printf("Игра окончена! Ваш счет: %d\n", field.score);
    }

    return 0;
}

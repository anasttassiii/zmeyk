#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale.h>
#include <string.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

// Точка
struct Point {
    int x;
    int y;
};

// Направление движения
struct Direction {
    int dx;
    int dy;
};

// Настройки игры
struct GameSettings {
    int snake_speed;
    int field_width;
    int field_height;
};

// Массив направлений движения
Direction directions[] = {
    {-1, 0}, // Вверх
    {1, 0},   // Вниз
    {0, -1},  // Влево
    {0, 1}    // Вправо
};

// Класс Еда
class Food {
private:
    Point position;

public:
    Food(int fieldWidth, int fieldHeight) {
        srand(static_cast<unsigned int>(time(NULL)));
        resetPosition(fieldWidth, fieldHeight);
    }

    void resetPosition(int fieldWidth, int fieldHeight) {
        position.x = rand() % fieldWidth;
        position.y = rand() % fieldHeight;
    }

    Point getPosition() const {
        return position;
    }
};

// Класс Змея
class Snake {
private:
    Point* body;
    int length;
    int direction;
    bool alive;

public:
    Snake(int initialLength, int initialDirection)
        : length(initialLength), direction(initialDirection), alive(true) {
        body = new Point[length];
        for (int i = 0; i < length; i++) {
            body[i].x = i;
            body[i].y = 0;
        }
    }

    ~Snake() {
        delete[] body;
    }

    void update(Direction dir, Food& food, int fieldWidth, int fieldHeight) {
        if (!alive) return;  // Если змея мертва, обновление не выполняется

        // Перемещение тела змеи
        for (int i = length - 1; i > 0; i--) {
            body[i] = body[i - 1];
        }

        // Обновление головы змеи
        body[0].x += dir.dx;
        body[0].y += dir.dy;

        // Проверка столкновения с границами поля
        if (body[0].x < 0 || body[0].x >= fieldWidth || body[0].y < 0 || body[0].y >= fieldHeight) {
            alive = false; // Змея "умерла", если вышла за границы
            return;
        }

        // Проверка самопересечения
        for (int i = 1; i < length; i++) {
            if (body[0].x == body[i].x && body[0].y == body[i].y) {
                alive = false; // Змея "умерла" при самопересечении
                return;
            }
        }

        // Проверка столкновения с едой
        if (body[0].x == food.getPosition().x && body[0].y == food.getPosition().y) {
            // Увеличение длины змеи при поедании еды
            Point* newBody = new Point[length + 1];
            for (int i = 0; i < length; i++) {
                newBody[i] = body[i];
            }
            newBody[length] = body[length - 1]; // Зафиксируем последнюю позицию
            length++;
            delete[] body; // Освобождение старого массива
            body = newBody; // Присваивание нового массива
            food.resetPosition(fieldWidth, fieldHeight);  // Сброс позиции еды
        }
    }

    bool isAlive() const {
        return alive;
    }

    Point getHeadPosition() const {
        return body[0];
    }
};

// Класс Игровое поле
class GameField {
private:
    int width;
    int height;
    Snake snake;
    Food food;
    int score;

public:
    GameField(GameSettings& settings)
        : width(settings.field_width), height(settings.field_height),
        snake(3, RIGHT), food(width, height), score(0) {}

    void update(Direction dir) {
        snake.update(dir, food, width, height);
    }

    int getScore() const {
        return score;
    }

    Point getSnakeHeadPosition() const {
        return snake.getHeadPosition();
    }

    bool isGameOver() const {
        return !snake.isAlive();
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    // Инициализация настроек игры
    GameSettings settings;
    settings.snake_speed = 100;
    settings.field_width = 20;
    settings.field_height = 15;

    // Инициализация игрового поля
    GameField field(settings);

    // Игровой цикл (пример)
    while (!field.isGameOver()) {
        field.update(directions[RIGHT]); // для примера змея движется вправо
        std::cout << "Счет: " << field.getScore() << std::endl;
        Point headPosition = field.getSnakeHeadPosition();
        std::cout << "Позиция головы змеи: (" << headPosition.x << ", " << headPosition.y << ")\n\n";

        // В реальной реализации тут будет ожидание ввода и управление направлением
    }

    std::cout << "Игра окончена!" << std::endl;

    return 0;
}
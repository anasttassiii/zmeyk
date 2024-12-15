#pragma once
#include <iostream>
#include <ctime>

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };

class Score {
private:
    int score;
public:
    Score() : score(0) {}
    void addScore(int value) {
        score += value;
    }
    int getScore() const {
        return score;
    }
};

class Snake {
protected:
    int width;
    int height;
    int tailX[100], tailY[100]; // В массивах хранятся координаты хвоста змейки
    int nTail;

public:
    Snake() { // Конструктор, задающий начальные значения змейки 
        this->width = 20;
        this->height = 15;
        nTail = 0;
    }
};

class Game : public Snake {
public:
    eDirection dir;
    Score score;
    bool gameover, gameset;
    int xHead, yHead, fruitX, fruitY; // Координаты головы змейки, положения фрукта
    static int gameCount;

    Game() : Snake() { // Конструктор, задающий начальное положение игры
        srand(time(NULL));
        gameCount++;
        gameover = false;
        gameset = false;
        dir = STOP;
        xHead = (this->width / 2) - 1; // Использование this для доступа к члену класса
        yHead = (this->height / 2) - 1;
        fruitX = rand() % (this->width - 1);
        fruitY = rand() % this->height;
        score = Score(); // Инициализация объекта Score
    }

    // Статический метод для получения количества игр
    static int getGameCount() {
        return gameCount;
    }

    // Метод для получения текущего счета
    int getScore() const { // Возвращает значение score из объекта score
        return score.getScore();
    }

    void Draw(); // Рисуем поле
    void Input(); // Получаем входные данные
    void Logic(); // Реализуем логику игры
    void Draw_horizontal_borders(); // Рисуем горизонтальные стенки
    bool Draw_vertical_borders(int, int); // Рисуем вертикальные стенки
    bool Draw_head_of_snake(int, int); // Рисуем голову змейки
    bool Draw_Fruite(int, int); // Рисуем фрукт
    void Draw_Snake_tail_or_space(int, int);
    void Tail_step();
    void Change_of_head_position();
    void Eating_Fruits();
    void head_to_tail_check();
    void meeting_with_boorder();
    bool Check_Tail_and_Fruit_coincidence();
};
﻿#pragma once
#include <iostream>
#include <ctime>
#include <vector>

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };

class IGame {
public:
    virtual void Draw() = 0; // Чисто виртуальная функция
    virtual void Logic() = 0; // Чисто виртуальная функция
    virtual ~IGame() {}
};

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

class Game : public IGame, public Snake {
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

    static int getGameCount() {
        return gameCount;
    }

    int getScore() const {
        return score.getScore();
    }

    virtual void Draw() override; // Рисуем поле
    void Input(); // Получаем входные данные
    virtual void Logic() override; // Реализуем логику игры
    void Draw_horizontal_borders(); // Рисуем горизонтальные стенки
    bool Draw_vertical_borders(int, int); // Рисуем вертикальные стенки
    bool Draw_head_of_snake(int, int); // Рисуем голову змейки
    bool Draw_Fruit(int, int); // Рисуем фрукт
    void Draw_Snake_tail_or_space(int, int);
    void Tail_step();
    void Change_of_head_position();
    void Eating_Fruits();
    void head_to_tail_check();
    void meeting_with_boorder();
    bool Check_Tail_and_Fruit_coincidence();
};

class AdvancedGame : public Game {
private:
    std::vector<int> history; // Хранит историю результатов игры

public:
    AdvancedGame() : Game() {} // Вызов конструктора базового класса

    void SaveScore(int score) {
        history.push_back(score);
    }

    void DisplayHistory() const {
        std::cout << "Game History:" << std::endl;
        for (auto score : history) {
            std::cout << score << " ";
        }
        std::cout << std::endl;
    }

    void Draw() override {
        Game::Draw(); // Вызов метода базового класса
        DisplayHistory(); // Дополнительная функция отображения результатов
    }
};
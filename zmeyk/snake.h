#pragma once
#include <iostream>
#include <ctime>
#include <vector>
#include <string>

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

    // Перегрузка оператора +
    Score operator+(const Score& other) const {
        Score temp;
        temp.score = this->score + other.score;
        return temp;
    }

    // Префиксный оператор ++
    Score& operator++() {
        this->score++;
        return *this;
    }

    // Постфиксный оператор ++
    Score operator++(int) {
        Score temp = *this;
        ++(*this);
        return temp;
    }
};

class Snake {
protected:
    int width;
    int height;
    int tailX[100], tailY[100]; // В массивах хранятся координаты хвоста змейки
    int nTail;

public:
    Snake() // Конструктор, задающий начальные значения змейки 
    {
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
    int xHead, yHead, fruitX, fruitY;
    static int gameCount;

    Game() : Snake() {
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

    Score& getScoreRef();
    int getScorePointer() const;
    friend std::ostream& operator<<(std::ostream& os, const Game& game);

    void Draw();
    void Input();
    void Logic();
    void Draw_horizontal_borders();
    bool Draw_vertical_borders(int, int);
    bool Draw_head_of_snake(int, int);
    bool Draw_Fruite(int, int);
    void Draw_Snake_tail_or_space(int, int);
    void Tail_step();
    void Change_of_head_position();
    void Eating_Fruits();
    void head_to_tail_check();
    void meeting_with_boorder();
    bool Check_Tail_and_Fruit_coincidence();
};
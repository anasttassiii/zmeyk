#pragma once
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
    void addScore(int value) { score += value; }
    int getScore() const { return score; }
};

class Snake {
protected:
    int width, height, nTail; // Теперь nTail защищен
    int tailX[100], tailY[100]; // В массивах хранятся координаты хвоста змейки
public:
    Snake() : width(20), height(15), nTail(0) {} // Конструктор
};

class Game : public IGame, public Snake {
public:bool gameover; // Завершение игры
protected: // Изменён доступ
    eDirection dir;
    Score score;
    
    int xHead, yHead, fruitX, fruitY; // Координаты головы змейки, положения фрукта
    static int gameCount;

public:
    Game() : Snake() { // Вызов конструктора базового класса
        srand(static_cast<unsigned int>(time(NULL)));
        gameCount++;
        gameover = false;
        dir = STOP;
        xHead = (this->width / 2) - 1;
        yHead = (this->height / 2) - 1;
        fruitX = rand() % (this->width - 1);
        fruitY = rand() % this->height;
        score = Score(); // Инициализация объекта Score
    }

    // Виртуальные методы
    virtual void Draw() override;
    void Input();
    virtual void Logic() override;

    static int getGameCount() { return gameCount; }
    int getScore() const { return score.getScore(); }

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
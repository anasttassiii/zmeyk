#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <string>

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };

class Snake {
protected:
    int width;
    int height;
    std::vector<int> tailX;  // Замена массива на вектор
    std::vector<int> tailY;  // Замена массива на вектор
    static int nTail; // длина хвоста

public:
    Snake() { // конструктор, задающий начальные значения змейки
        this->width = 20;
        this->height = 15;
    }
    friend int getTailLength(const Snake& s); // Дружественная функция
    static int plusnTail() { return ++nTail; }

    static int* getnTailPtr() { return &nTail; }

    static int& getnTailRef() { return nTail; }
};

class Game : public Snake {
public:
    eDirection dir;
    bool gameover;
    int xHead, yHead, fruitX, fruitY, score; // координаты головы змейки, положения фрукта

    Game() : Snake() { // конструктор, задающий начальное положение игры
        srand(time(NULL));
        gameover = false;
        dir = STOP;
        xHead = (this->width / 2) - 1; // Использование this для доступа к члену класса
        yHead = (this->height / 2) - 1;
        fruitX = rand() % (this->width - 1);
        fruitY = rand() % this->height;
        score = 0;
        tailX.resize(100); // Резервируем место для 100 элементов
        tailY.resize(100); // Резервируем место для 100 элементов
    }

    void Draw(); // рисуем поле
    void Input(); // получаем входные данные
    void Logic(); // реализуем логику игры
    void Draw_horizontal_borders(); // рисуем горизонтальные стенки
    bool Draw_vertical_borders(int, int); // рисуем вертикальные стенки
    bool Draw_head_of_snake(int, int); // рисуем голову змейки
    bool Draw_Fruite(int, int); // рисуем фрукт
    void Draw_Snake_tail_or_space(int, int);
    void Tail_step();
    void Change_of_head_position();
    void Eating_Fruits();
    void head_to_tail_check();
    void meeting_with_boorder();
    bool Check_Tail_and_Fruit_coincidence();
};
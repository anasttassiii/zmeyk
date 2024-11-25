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
    std::vector<int> tailX;  // ������ ������� �� ������
    std::vector<int> tailY;  // ������ ������� �� ������
    static int nTail; // ����� ������

public:
    Snake() { // �����������, �������� ��������� �������� ������
        this->width = 20;
        this->height = 15;
    }
    friend int getTailLength(const Snake& s); // ������������� �������
    static int plusnTail() { return ++nTail; }

    static int* getnTailPtr() { return &nTail; }

    static int& getnTailRef() { return nTail; }
};

class Game : public Snake {
public:
    eDirection dir;
    bool gameover;
    int xHead, yHead, fruitX, fruitY, score; // ���������� ������ ������, ��������� ������

    Game() : Snake() { // �����������, �������� ��������� ��������� ����
        srand(time(NULL));
        gameover = false;
        dir = STOP;
        xHead = (this->width / 2) - 1; // ������������� this ��� ������� � ����� ������
        yHead = (this->height / 2) - 1;
        fruitX = rand() % (this->width - 1);
        fruitY = rand() % this->height;
        score = 0;
        tailX.resize(100); // ����������� ����� ��� 100 ���������
        tailY.resize(100); // ����������� ����� ��� 100 ���������
    }

    void Draw(); // ������ ����
    void Input(); // �������� ������� ������
    void Logic(); // ��������� ������ ����
    void Draw_horizontal_borders(); // ������ �������������� ������
    bool Draw_vertical_borders(int, int); // ������ ������������ ������
    bool Draw_head_of_snake(int, int); // ������ ������ ������
    bool Draw_Fruite(int, int); // ������ �����
    void Draw_Snake_tail_or_space(int, int);
    void Tail_step();
    void Change_of_head_position();
    void Eating_Fruits();
    void head_to_tail_check();
    void meeting_with_boorder();
    bool Check_Tail_and_Fruit_coincidence();
};
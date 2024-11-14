#pragma once
#include <iostream>
#include <ctime>

enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};

class Snake {
protected:
	int width;
	int height;
	int tailX[100], tailY[100];   // � �������� �������� ���������� ������ ������
	int nTail;      // ����� ������
public:
	Snake()        // �����������, �������� ��������� �������� ������
	{
		width = 20;
		height = 15;
		nTail = 0;
	}
};

class Game : public Snake
{
public:
	eDirection dir;
	bool gameover;
	int xHead, yHead, fruitX, fruitY, score;  // ���������� ������ ������, ��������� ������
	Game() :Snake()   // �����������, �������� ��������� ��������� ����
	{
		srand(time(NULL));
		gameover = false;
		dir = STOP;
		xHead = (width / 2) - 1;
		yHead = (height / 2) - 1;
		fruitX = rand() % (width - 1);
		fruitY = rand() % height;
		score = 0;
	}
	void Draw();   // ������ ����
	void Input();   // �������� ������� ������
	void Logic();  // ��������� ������ ����
	void Draw_horizontal_borders();   // ������ �������������� ������
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



#pragma once
#include <iostream>
#include <ctime>

enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};

class Snake {
protected:
	int width;
	int height;
	int tailX[100], tailY[100];   // в массивах хран€тс€ координаты хвоста змейки
	int nTail;      // длина хвоста
public:
	Snake()        // конструктор, задающий начальные значени€ змейки
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
	int xHead, yHead, fruitX, fruitY, score;  // координаты головы змейки, положени€ фрукта
	Game() :Snake()   // конструктор, задающий начальное положение игры
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
	void Draw();   // рисуем поле
	void Input();   // получаем входные данные
	void Logic();  // реализуем логику игры
	void Draw_horizontal_borders();   // рисуем горизонтальные стенки
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



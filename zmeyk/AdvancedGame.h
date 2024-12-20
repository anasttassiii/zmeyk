#pragma once
#include "snake.h"
#include "History.h"

using namespace std;

class AdvancedGame : public Game {
private:
    History<int> history; // ���������� ��������� ����� ��� �������� �������

public:
    AdvancedGame() : Game() {} // ����� ������������ �������� ������

    // �������� ������������
    AdvancedGame& operator=(const AdvancedGame& other) {
        if (this != &other) {
            Game::operator=(other); // ������� �������� �������� ������������ �������� ������
            history = other.history; // �������� �������
        }
        return *this;
    }

    void SaveScore(int score) {
        history.addScore(score); // ��������� ������� ����
    }

    void Draw() override {
        Game::Draw(); // ����� ������ �������� ������
        history.display(); // ����������� ������� �����
    }

    void ResetHistory() {
        history.clear(); // ������� ������� ��� ����� ����
    }
};
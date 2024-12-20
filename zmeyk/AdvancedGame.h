#pragma once
#include <vector>
#include "snake.h"

using namespace std;

class AdvancedGame : public Game {
private:
    std::vector<int> history; // ������� �����
    int lastScore; // ��� �������� ���������� ������������ �����
public:
    AdvancedGame() : Game(), lastScore(0) {} // ����� ������������ �������� ������

    void SaveScore(int score) {
        if (score != lastScore) { // ��������� ������ ���� ���� ���������
            history.push_back(score);
            lastScore = score; // ��������� ��������� ����������� ����
        }
    }

    void DisplayHistory() const {
        cout << "Game History:";
        if (history.empty()) {
            cout << " No scores yet.";
        }
        for (auto score : history) {
            cout << " " << score; // ����������� ������� �����
        }
        cout << endl;
    }

    void Draw() override {
        Game::Draw(); // ����� ������ �������� ������
        DisplayHistory(); // ����������� ������� �����
    }

    void ResetHistory() {
        history.clear(); // ������� ������� ��� ����� ����
        lastScore = 0; // ���������� ��������� ����������� ����
    }
};
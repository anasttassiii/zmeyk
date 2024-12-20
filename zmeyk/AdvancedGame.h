#pragma once
#include <vector>
#include "snake.h"

using namespace std;

class AdvancedGame : public Game {
private:
    std::vector<int> history; // История очков
    int lastScore; // Для хранения последнего добавленного счета
public:
    AdvancedGame() : Game(), lastScore(0) {} // Вызов конструктора базового класса

    void SaveScore(int score) {
        if (score != lastScore) { // Сохраняем только если счет изменился
            history.push_back(score);
            lastScore = score; // Обновляем последний сохраненный счет
        }
    }

    void DisplayHistory() const {
        cout << "Game History:";
        if (history.empty()) {
            cout << " No scores yet.";
        }
        for (auto score : history) {
            cout << " " << score; // Отображение истории очков
        }
        cout << endl;
    }

    void Draw() override {
        Game::Draw(); // Вызов метода базового класса
        DisplayHistory(); // Отображение истории очков
    }

    void ResetHistory() {
        history.clear(); // Очищаем историю для новой игры
        lastScore = 0; // Сбрасываем последний сохраненный счет
    }
};
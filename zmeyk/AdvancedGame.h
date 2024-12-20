#pragma once
#include "snake.h"
#include "History.h"

using namespace std;

class AdvancedGame : public Game {
private:
    History<int> history; // Используем шаблонный класс для хранения истории

public:
    AdvancedGame() : Game() {} // Вызов конструктора базового класса

    // Оператор присваивания
    AdvancedGame& operator=(const AdvancedGame& other) {
        if (this != &other) {
            Game::operator=(other); // Сначала вызываем оператор присваивания базового класса
            history = other.history; // Копируем историю
        }
        return *this;
    }

    void SaveScore(int score) {
        history.addScore(score); // Сохраняем текущий счет
    }

    void Draw() override {
        Game::Draw(); // Вызов метода базового класса
        history.display(); // Отображение истории очков
    }

    void ResetHistory() {
        history.clear(); // Очищаем историю для новой игры
    }
};
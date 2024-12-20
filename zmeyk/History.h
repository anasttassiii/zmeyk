#pragma once
#include <vector>
#include <iostream>

template <typename T>
class History {
private:
    std::vector<T> scores; // Вектор для хранения элементов

public:
    void addScore(const T& score) {
        scores.push_back(score);
    }

    void display() const {
        std::cout << "Game History:";
        for (const auto& score : scores) {
            std::cout << " " << score;
        }
        std::cout << std::endl;
    }

    void clear() {
        scores.clear(); // Очищаем историю
    }
};
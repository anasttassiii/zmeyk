#include <iostream>
#include <vector>
#include <algorithm> // Для std::sort и std::binary_search
#include "snake.h"
#include <ctime>
#include <windows.h>
#include <conio.h>

using namespace std;

int main() {
    vector<Game> games(100); // Массив объектов Game
    vector<int> scores; // Вектор для хранения результатов

    for (int i = 0; i < 100; i++) {
        games[i] = Game(); // Инициализация объекта Game
        while (!games[i].gameover && !games[i].gameset) {
            games[i].Draw();
            games[i].Input();
            games[i].Logic();
            Sleep(300); // Задержка 300 миллисекунд
        }
        cout << "Game Over for game " << (i + 1) << "! Your score: " << games[i].getScore() << endl;
        scores.push_back(games[i].getScore()); // Сохраняем результат
        Sleep(2500);
        if (games[i].gameset == true) break;
    }

    // Сортировка результатов
    std::sort(scores.begin(), scores.end());

    // Отображение отсортированных результатов
    cout << "Sorted Scores: ";
    for (const auto& score : scores) {
        cout << score << " ";
    }
    cout << endl;

    // Поиск заданного результата
    int scoreToFind;
    cout << "Enter a score to search for: ";
    cin >> scoreToFind;

    if (std::binary_search(scores.begin(), scores.end(), scoreToFind)) {
        cout << "Score " << scoreToFind << " found in the list." << endl;
    }
    else {
        cout << "Score " << scoreToFind << " not found in the list." << endl;
    }

    cout << "Total number of games created: " << Game::getGameCount() - 100 << endl; // Статическое использование
    return 0;
}
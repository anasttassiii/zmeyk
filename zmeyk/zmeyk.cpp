#include <iostream>
#include <vector>
#include <algorithm> // Для std::sort и std::binary_search
#include "snake.h"
#include <ctime>
#include <windows.h>
#include <conio.h>

using namespace std;

int main() {
    vector<AdvancedGame> games(100); // Массив объектов AdvancedGame
    vector<int> scores; // Вектор для хранения результатов

    for (int i = 0; i < 100; i++) {
        games[i] = AdvancedGame(); // Инициализация объекта AdvancedGame
        while (!games[i].gameover && !games[i].gameset) {
            games[i].Draw();
            games[i].Input();
            games[i].Logic();
            Sleep(300); // Задержка 300 миллисекунд
        }
        cout << "Game Over for game " << (i + 1) << "! Your score: " << games[i].getScore() << endl;
        games[i].SaveScore(games[i].getScore()); // Сохраняем результат
        Sleep(2500);
        if (games[i].gameset == true) break;
    }

    // Вывод сохранённых результатов
    cout << "Game History:" << endl;
    for (const auto& game : games) {
        game.DisplayHistory();
    }

    cout << "Total number of games created: " << Game::getGameCount()-100 << endl; // Статическое использование
    return 0;
}
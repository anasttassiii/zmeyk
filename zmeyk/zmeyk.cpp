﻿#include <iostream>
#include <vector>
#include "snake.h"
#include "AdvancedGame.h"
#include <windows.h>

using namespace std;

int main() {
    vector<AdvancedGame> games;
    int numGames = 1; // Здесь можно изменить количество игр для запуска

    for (int i = 0; i < numGames; i++) {
        AdvancedGame game;
        games.push_back(game);

        while (!games[i].gameover) {
            games[i].Draw();
            games[i].Input();
            games[i].Logic();
            Sleep(100); // Задержка 100 мс
        }

        cout << "Game Over! Your score: " << games[i].getScore() << endl;
        games[i].ResetHistory(); // Очищение истории для новой игры
    }

    cout << "Total number of games created: " << Game::getGameCount() << endl; // Статическое использование
    return 0;
}
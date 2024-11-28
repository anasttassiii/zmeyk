#include <iostream>
#include "snake.h"
#include <vector>
#include <windows.h>
#include <conio.h>

using namespace std;

int main() {
    vector<Game> games(100);

    for (int i = 0; i < 100; i++) {
        games[i] = Game();
        while (!games[i].gameover && !games[i].gameset) {
            games[i].Draw();
            games[i].Input();
            games[i].Logic();
            Sleep(300);
        }
        // Используем getScorePointer() вместо getScore()
        cout << "Game Over for game " << (i + 1) << "! Your score: " << games[i].getScorePointer() << endl;
        Sleep(2500);
        if (games[i].gameset) break;
    }
    
    cout << "Total number of games created: " << Game::getGameCount() - 100 << endl;
    return 0;
}
#pragma once
#include <iostream>

// ����������� �����
class IGame {
public:
    virtual void Draw() = 0;
    virtual void Logic() = 0;
    virtual ~IGame() {}
};
#pragma once
#include "car.h"
#include<memory>
#include<string.h>
using std::shared_ptr;

class Executor {
private:
    shared_ptr<Car> car;
public:
    Executor();

    Executor(int _x, int _y, char c);

    void Initialize(int _x = 0, int _y = 0, char c = 'N');

    void Execute(char c);

    void Execute(const char *str);
};

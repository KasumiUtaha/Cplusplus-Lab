#include "Executor.h"

Executor::Executor() {
    car = std::make_shared<Car>();
}

Executor::Executor(int _x, int _y, char c) {
    car = std::make_shared<Car>(_x, _y, c);
}

void Executor::Initialize(int _x, int _y, char c) {
    car.reset();
    car = std::make_shared<Car>(_x, _y, c);
}

void Executor::Execute(char c) {
    switch(c) {
        case 'M': car -> Move(); break;
        case 'L': car -> Turnleft(); break;
        case 'R': car -> Turnright(); break;
        default: cerr<<"Undefined execute char!"; break;
    }
}

void Executor::Execute(const char *str) {
    int len = strlen(str);
    for(int i=0;i<len;i++) Execute(str[i]);
}

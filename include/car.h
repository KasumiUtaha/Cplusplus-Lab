#pragma once
#include<iostream>
#include<tuple>
using std::cout;
using std::cerr;
using std::tuple;

typedef tuple<int, int, char> CarTuple;

enum Direction {
    NORTH,
    SOUTH,
    WEST,
    EAST,
};

class Car {
private:
    int x;
    int y;
    Direction direction;
public:
    Car();

    Car(int _x, int _y, char c);

    char Direction2Char();

    Direction Char2Direction(char c);

    void Move(int step = 1);

    void Turnleft();

    void Turnright();

    CarTuple GetInfo();
};
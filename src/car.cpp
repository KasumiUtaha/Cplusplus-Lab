
#include "car.h"


Car::Car(): x(0), y(0), direction(NORTH) {}

Car::Car(int _x, int _y, char c): x(_x), y(_y) {
    direction = Char2Direction(c);
}

Direction Car::Char2Direction(char c) {
    switch(c) {
        case 'N' : return Direction::NORTH;
        case 'S' : return Direction::SOUTH;
        case 'W' : return Direction::WEST;
        case 'E' : return Direction::EAST;
        default : {
            cerr<<"Error Direciton given to Car!\n";
            exit(0);
        }
    }
}

char Car::Direction2Char() {
    switch (direction)
    {
        case Direction::NORTH : return 'N';
        case Direction::SOUTH : return 'S';
        case Direction::WEST :  return 'W';
        case Direction::EAST :  return 'E';
    }
    return 'N'; // unreachable
}

void Car::Move(int step) {
    switch(direction) {
        case Direction::NORTH : y+=step; break;
        case Direction::SOUTH : y-=step; break;
        case Direction::WEST :  x-=step; break;
        case Direction::EAST :  x+=step; break;
    }
}

void Car::Turnleft() {
    switch(direction) {
        case Direction::NORTH : direction = Direction::WEST; break;
        case Direction::SOUTH : direction = Direction::EAST; break;
        case Direction::WEST :  direction = Direction::SOUTH; break;
        case Direction::EAST :  direction = Direction::NORTH; break;
    }
}

void Car::Turnright() {
    switch(direction) {
        case Direction::NORTH : direction = Direction::EAST; break;
        case Direction::SOUTH : direction = Direction::WEST; break;
        case Direction::WEST :  direction = Direction::NORTH; break;
        case Direction::EAST :  direction = Direction::SOUTH; break;
    }
}

CarTuple Car::GetInfo() {
    return std::make_tuple(x, y, Direction2Char());
}


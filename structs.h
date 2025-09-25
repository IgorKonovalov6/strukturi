#ifndef STRUCTS_H
#define STRUCTS_H

#include <iostream>
#include <cmath>
using namespace std;

const double EPS = 1e-5;
const double PI = acos(-1.0);

// Точка
struct Point {
    double x, y;
};

void readPoint(Point &p);
void printPoint(const Point &p);

// Круг
struct Circle {
    Point center;
    double r;
};

void readCircle(Circle &c);
void printCircle(const Circle &c);
double circleLength(const Circle &c);
double circleArea(const Circle &c);

// Квадрат
struct Square {
    Point topLeft; // верхний левый угол
    double side;
};

void readSquare(Square &s);
void printSquare(const Square &s);
double squarePerimeter(const Square &s);
double squareArea(const Square &s);

#endif
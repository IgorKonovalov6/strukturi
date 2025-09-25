#include "structs.h"
#include <cmath>
#include <algorithm>
using namespace std;

void readPoint(Point &p);
void readCircle(Circle &c);
void readSquare(Square &s);

// Проверка принадлежности точки фигуре
bool pointInCircle(const Point &p, const Circle &c);
bool pointInSquare(const Point &p, const Square &s);

// Проверка нахождения на контуре
bool pointOnCircle(const Point &p, const Circle &c);
bool pointOnSquare(const Point &p, const Square &s);

// Пересечение фигур
bool circlesIntersect(const Circle &c1, const Circle &c2);
bool squaresIntersect(const Square &s1, const Square &s2);
bool circleSquareIntersect(const Circle &c, const Square &s);

// Принадлежность фигуры другой фигуре
bool circleInCircle(const Circle &c1, const Circle &c2);
bool squareInSquare(const Square &s1, const Square &s2);
bool squareInCircle(const Square &s, const Circle &c);
bool circleInSquare(const Circle &c, const Square &s);

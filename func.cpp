#include "func.h"
#include "structs.h"

void readPoint(Point &p) {
    cin >> p.x >> p.y;
}
void readCircle(Circle &c){
    readPoint(c.center);
    cin >> c.r;
}
void readSquare(Square &s){
    cin >> s.topLeft.x >> s.topLeft.y >> s.side;
}

// Точка в круге
bool pointInCircle(const Point &p, const Circle &c) {
    double dist2 = pow(p.x - c.center.x, 2) + pow(p.y - c.center.y, 2);
    return dist2 < c.r * c.r - EPS;
}

bool pointOnCircle(const Point &p, const Circle &c) {
    double dist = sqrt(pow(p.x - c.center.x, 2) + pow(p.y - c.center.y, 2));
    return fabs(dist - c.r) < EPS;
}

// Точка в квадрате
bool pointInSquare(const Point &p, const Square &s) {
    return (p.x > s.topLeft.x && p.x < s.topLeft.x + s.side &&
            p.y < s.topLeft.y && p.y > s.topLeft.y - s.side);
}

bool pointOnSquare(const Point &p, const Square &s) {
    bool onLeft   = fabs(p.x - s.topLeft.x) < EPS && (p.y <= s.topLeft.y && p.y >= s.topLeft.y - s.side);
    bool onRight  = fabs(p.x - (s.topLeft.x + s.side)) < EPS && (p.y <= s.topLeft.y && p.y >= s.topLeft.y - s.side);
    bool onTop    = fabs(p.y - s.topLeft.y) < EPS && (p.x >= s.topLeft.x && p.x <= s.topLeft.x + s.side);
    bool onBottom = fabs(p.y - (s.topLeft.y - s.side)) < EPS && (p.x >= s.topLeft.x && p.x <= s.topLeft.x + s.side);
    return onLeft || onRight || onTop || onBottom;
}

// Пересечение
bool circlesIntersect(const Circle &c1, const Circle &c2) {
    double dist = sqrt(pow(c1.center.x - c2.center.x, 2) + pow(c1.center.y - c2.center.y, 2));
    return dist <= c1.r + c2.r + EPS && dist + min(c1.r, c2.r) >= max(c1.r, c2.r) - EPS;
}

bool squaresIntersect(const Square &s1, const Square &s2) {
    return !(s1.topLeft.x + s1.side < s2.topLeft.x) ||
             (s2.topLeft.x + s2.side < s1.topLeft.x) ||
             (s1.topLeft.y - s1.side > s2.topLeft.y) ||
             (s2.topLeft.y - s2.side > s1.topLeft.y);
}

bool circleSquareIntersect(const Circle &c, const Square &s) {
    double cx = c.center.x;
    double cy = c.center.y;
    double nearestX = max(s.topLeft.x, min(cx, s.topLeft.x + s.side));
    double nearestY = max(s.topLeft.y - s.side, min(cy, s.topLeft.y));
    double dx = cx - nearestX;
    double dy = cy - nearestY;
    return dx*dx + dy*dy <= c.r * c.r + EPS;
}

// Принадлежность фигур
bool circleInCircle(const Circle &c1, const Circle &c2) {
    double dist = sqrt(pow(c1.center.x - c2.center.x, 2) + pow(c1.center.y - c2.center.y, 2));
    return dist + c1.r <= c2.r + EPS;
}

bool squareInSquare(const Square &s1, const Square &s2) {
    return (s1.topLeft.x >= s2.topLeft.x &&
            s1.topLeft.x + s1.side <= s2.topLeft.x + s2.side &&
            s1.topLeft.y <= s2.topLeft.y &&
            s1.topLeft.y - s1.side >= s2.topLeft.y - s2.side);
}

bool squareInCircle(const Square &s, const Circle &c) {
    Point corners[4] = {
        s.topLeft,
        {s.topLeft.x + s.side, s.topLeft.y},
        {s.topLeft.x, s.topLeft.y - s.side},
        {s.topLeft.x + s.side, s.topLeft.y - s.side}
    };
    for (int i = 0; i < 4; i++)
        if (!pointInCircle(corners[i], c)) return false;
    return true;
}

bool circleInSquare(const Circle &c, const Square &s) {
    return (c.center.x - c.r >= s.topLeft.x &&
            c.center.x + c.r <= s.topLeft.x + s.side &&
            c.center.y + c.r <= s.topLeft.y &&
            c.center.y - c.r >= s.topLeft.y - s.side);
}
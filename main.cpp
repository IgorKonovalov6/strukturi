#include "structs.h"
#include "func.h"

int main() {
    Circle c1, c2;
    Square s1, s2;
    Point p;

    cout << "krug 1 (x y r): ";
    readCircle(c1);
    cout << "krug 2 (x y r): ";
    readCircle(c2);

    cout << "kvadrat 1 (x y side): ";
    readSquare(s1);
    cout << "kvadrat 2 (x y side): ";
    readSquare(s2);

    cout << "tochka (x y): ";
    readPoint(p);

    cout << "\ntochka " << (pointInCircle(p, c1) ? "vnutri" : "ne vnutri") << " kruga 1\n";
    cout << "tochka " << (pointOnSquare(p, s1) ? "na granice" : "ne na granice") << " kvadarata 1\n";
    cout << "krugi " << (circlesIntersect(c1, c2) ? "peresekatsa" : "ne peresekatsa") << "\n";
    cout << "kvadrati " << (squaresIntersect(s1, s2) ? "peresekatsa" : "ne peresekatsa") << "\n";
    cout << "krug 1 " << (circleInSquare(c1, s1) ? "vnutri kvadra 1" : "ne vnutri kvadrata 1") << "\n";

    return 0;
}
// Cas 5, predvidi ispis 5: napisi na papir sta ce se ispisati, pa Fn+F5.
#include <iostream>
using namespace std;

struct Tacka { int x, y; };

int main() {
    Tacka t = { 2, 3 };
    Tacka* pt = &t;
    pt->x = pt->y * 2;
    Tacka kopija = *pt;
    kopija.y = 100;
    cout << t.x << " " << t.y << " " << kopija.x << endl;
    return 0;
}
/*
t (2,3)
pt -> t -- t(6, 3)
kopija (6,3) -- (9,100)
6 3 6
*/
// Cas 5, predvidi ispis 2: napisi na papir sta ce se ispisati, pa Fn+F5.
#include <iostream>
using namespace std;

/*
p -> a (1) -- -> b (5)
q -> b (2) -- 1 --
*/

int main() {
    int a = 1, b = 2;
    int* p = &a;
    int* q = &b;
    *q = *p;
    p = q;
    *p = 5;
    cout << a << " " << b << endl;
    return 0;
}

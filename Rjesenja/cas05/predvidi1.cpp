// Cas 5, predvidi ispis 1: napisi na papir sta ce se ispisati, pa Fn+F5.
#include <iostream>
using namespace std;

int main() {
    int a = 3;
    int* p = &a;
    *p = *p + 4;
    cout << a << " " << *p << endl;
    return 0;
}

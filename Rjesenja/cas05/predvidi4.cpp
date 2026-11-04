// Cas 5, predvidi ispis 4: napisi na papir sta ce se ispisati, pa Fn+F5.
#include <iostream>
using namespace std;

int main() {
    int niz[4] = { 5, 10, 15, 20 };
    int* p = niz + 1;
    cout << *p << " " << p[1] << " " << *(p + 2) << endl;
    p++;
    cout << *p - niz[0] << endl;
    return 0;
}
/*
 p (10) 10 15 20
 p (15) 15 - 5 = 10
*/
// Cas 5, predvidi ispis 3: napisi na papir sta ce se ispisati, pa Fn+F5.
#include <iostream>
using namespace std;

void Promijeni(int* p) { p = nullptr; }
void Postavi(int* p) { *p = 9; }

int main() {
    int x = 4;
    int* p = &x;
    Promijeni(p);
    cout << x << endl; 
    Postavi(p);
    cout << x << " " << (p != nullptr) << endl;
    return 0;
}

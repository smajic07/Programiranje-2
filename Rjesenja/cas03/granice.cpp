// Demonstracija: indeks van granica niza.
// Fn+F5 ispise 6 brojeva bez ikakve greske, a zadnji je smece iz memorije.
// U terminalu:  bash ../testiraj.sh granice.cpp   -> stack-buffer-overflow sa tacnom linijom.
#include <iostream>
using namespace std;

int main() {
    const int VEL = 5;
    int ocjene[VEL] = { 8, 6, 10, 9, 7 };
    for (int i = 0; i <= VEL; i++)     // <= ide jedan korak previse
        cout << ocjene[i] << " ";
    cout << endl;
    return 0;
}

/*
    Cas 2, zadatak 2: tablica mnozenja

    Napisati tijelo funkcije void IspisiTablicuMnozenja(int n = 10)
    koja ispise tablicu mnozenja n x n. Brojeve u redu odvojiti
    tabulatorom "\t". Poziv bez argumenta ispise tablicu 10 x 10.

    Primjer, IspisiTablicuMnozenja(3) ispise:
        1   2   3
        2   4   6
        3   6   9

    main je gotov: pokrenuti i provjeriti obje tablice.

    Koristiti: dvije petlje for, jednu unutar druge.
*/
#include <iostream>
using namespace std;

void IspisiTablicuMnozenja(int n = 10) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << i * j << "\t";
        }
        cout << endl;
    }
}

int main() {
    IspisiTablicuMnozenja(3);   // tablica 3 x 3
    cout << endl;
    IspisiTablicuMnozenja();    // tablica 10 x 10
    return 0;
}
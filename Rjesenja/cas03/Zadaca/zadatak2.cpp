/*
    Cas 3, zadatak 2: UkloniDuplikate (ispit 2026-07-09 G2)

    Napisati tijelo funkcije void UkloniDuplikate(int niz[], int& trenutno)
    koja iz niza izbaci sve ponovljene vrijednosti i zadrzi samo prvo
    pojavljivanje svake. Redoslijed preostalih elemenata se ne mijenja,
    a trenutno se smanji za broj izbacenih elemenata.

    Primjeri:
        4 1 4 2 1 4 3  ->  4 1 2 3
        7 7 7          ->  7
        1 2 3          ->  1 2 3

    Koristiti: pomjeranje ulijevo kao kod UkloniRaspon sa casa.
    Pazi: poslije izbacivanja na istu poziciju dolazi sljedeci element,
    pa ga treba provjeriti prije nego sto se ide dalje.
*/
#include <iostream>
using namespace std;

void Ispisi(int niz[], int n) {
    for (int i = 0; i < n; i++) cout << niz[i] << " ";
    cout << endl;
}

void UkloniDuplikate(int niz[], int& trenutno) {
    for (int i = 0; i < trenutno; i++) {
        for (int j = i + 1; j < trenutno; j++) {
            if (niz[i] == niz[j]) {
                for (int k = j; k < trenutno - 1; k++) {
                    niz[k] = niz[k + 1];
                }
                trenutno--;
                j--;
            }
        }
    }
}

int main() {
    int a[] = { 4, 1, 4, 2, 1, 4, 3 };
    int na = 7;
    UkloniDuplikate(a, na);
    Ispisi(a, na);                     // 4 1 2 3

    int b[] = { 7, 7, 7 };
    int nb = 3;
    UkloniDuplikate(b, nb);
    Ispisi(b, nb);                     // 7

    int c[] = { 1, 2, 3 };
    int nc = 3;
    UkloniDuplikate(c, nc);
    Ispisi(c, nc);                     // 1 2 3
    return 0;
}

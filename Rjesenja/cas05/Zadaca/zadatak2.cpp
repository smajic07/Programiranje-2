/*
    Cas 5, zadatak 2: NadjiMax vraca pokazivac

    Napisati tijelo funkcije int* NadjiMax(int* niz, int n) koja vraca
    POKAZIVAC na najveci element niza (ako ih je vise, na prvi).
    Za prazan niz (n <= 0) ili niz == nullptr vraca nullptr.

    main preko vracenog pokazivaca postavi najveci element na 0:
        4 17 8 17 2  ->  4 0 8 17 2

    Koristiti: pokazivac koji na pocetku pokazuje na prvi element,
    i &niz[i] kad se nadje veci element.
    Pazi: vraca se adresa elementa iz niza pozivaoca, a ne adresa
    neke lokalne varijable (vidi lokalna.cpp sa casa).
*/
#include <iostream>
using namespace std;

void Ispisi(int niz[], int n) {
    for (int i = 0; i < n; i++) cout << niz[i] << " ";
    cout << endl;
}

int* NadjiMax(int* niz, int n) {
    if (n <= 0 || niz == nullptr) {
        return nullptr;
    }
    
    int* max_p = &niz[0];
    for (int i = 1; i < n; i++) {
        if (niz[i] > *max_p) {
            max_p = &niz[i];
        }
    }
    return max_p;
}

int main() {
    int niz[5] = { 4, 17, 8, 17, 2 };
    int* p = NadjiMax(niz, 5);
    if (p != nullptr) {
        cout << *p << endl;                     // 17
        cout << (p == &niz[1]) << endl;          // 1: pokazuje na PRVU 17-icu
        *p = 0;
    }
    Ispisi(niz, 5);                             // 4 0 8 17 2
    cout << (NadjiMax(niz, 0) == nullptr) << endl;   // 1: prazan niz
    return 0;

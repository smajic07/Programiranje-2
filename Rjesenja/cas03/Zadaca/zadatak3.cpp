/*
    Cas 3, zadatak 3: bubble sort rastuce i opadajuce

    Napisati tijelo funkcije void BubbleSort(int niz[], int n, bool rastuce)
    koja sortira niz bubble sortom: rastuce ako je rastuce true,
    a opadajuce ako je false.

    Primjer, niz 5 2 9 1 7:
        BubbleSort(niz, 5, true)   ->  1 2 5 7 9
        BubbleSort(niz, 5, false)  ->  9 7 5 2 1

    Koristiti: dvije ugnijezdjene for petlje i zamjenu susjednih elemenata.
    Jedna funkcija za oba smjera: mijenja se samo uslov zamjene.
*/
#include <iostream>
using namespace std;

void Ispisi(int niz[], int n) {
    for (int i = 0; i < n; i++) cout << niz[i] << " ";
    cout << endl;
}

void BubbleSort(int niz[], int n, bool rastuce) {
    // rjesenje ovdje

}

int main() {
    int niz[] = { 5, 2, 9, 1, 7 };
    BubbleSort(niz, 5, true);
    Ispisi(niz, 5);                    // 1 2 5 7 9
    BubbleSort(niz, 5, false);
    Ispisi(niz, 5);                    // 9 7 5 2 1
    return 0;
}

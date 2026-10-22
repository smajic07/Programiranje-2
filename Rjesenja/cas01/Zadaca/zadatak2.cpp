/*
    Cas 1, zadatak 2: datum u formatu 05.10.2025

    Program trazi unos dana, mjeseca i godine (tri cijela broja, odvojena
    razmakom) i ispise datum u formatu DD.MM.GGGG.
    Dan i mjesec manji od 10 dobijaju vodecu nulu.

    Primjeri (unos -> ispis):
        5 10 2025 -> 05.10.2025
        15 3 2026 -> 15.03.2026
        1 1 2000  -> 01.01.2000

    Koristiti: cin za tri broja i if za vodecu nulu (setw i setfill dolaze tek na casu 10).
*/
#include <iostream>
using namespace std;

int main() {
    // rjesenje ovdje
int dan, mjesec, godina;
    cin >> dan >> mjesec >> godina;

    if (dan < 10) {
        cout << "0" << dan << ".";
    } else {
        cout << dan << ".";
    }

    if (mjesec < 10) {
        cout << "0" << mjesec << ".";
    } else {
        cout << mjesec << ".";
    }

    cout << godina << endl;
    return 0;
}

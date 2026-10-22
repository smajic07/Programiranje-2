/*
    Cas 2, zadatak 4: broj dana izmedju dva datuma

    Napisati funkciju
        int RazlikaDana(int d1, int m1, int g1, int d2, int m2, int g2)
    koja vraca broj dana od prvog do drugog datuma.

    Prvo iznad nje prepisati funkcije IsPrestupna, BrojDanaUMjesecu
    i UkupnoDana sa casa (fajl Rjesenja/cas02/cas02.cpp).

    Primjeri:
        RazlikaDana(28, 2, 2024, 1, 3, 2024)  -> 2    (2024. je prijestupna)
        RazlikaDana(28, 2, 2025, 1, 3, 2025)  -> 1
        RazlikaDana(31, 12, 2025, 1, 1, 2026) -> 1    (prelaz godine)
        RazlikaDana(1, 1, 2026, 1, 1, 2027)   -> 365

    main je gotov: pokrenuti i uporediti ispis sa komentarima.
*/
#include <iostream>
using namespace std;

// ovdje prepisati IsPrestupna, BrojDanaUMjesecu i UkupnoDana sa casa

int RazlikaDana(int d1, int m1, int g1, int d2, int m2, int g2) {
    // rjesenje ovdje

    return 0;
}

int main() {
    cout << RazlikaDana(28, 2, 2024, 1, 3, 2024) << endl;    // 2
    cout << RazlikaDana(28, 2, 2025, 1, 3, 2025) << endl;    // 1
    cout << RazlikaDana(31, 12, 2025, 1, 1, 2026) << endl;   // 1
    cout << RazlikaDana(1, 1, 2026, 1, 1, 2027) << endl;     // 365
    return 0;
}

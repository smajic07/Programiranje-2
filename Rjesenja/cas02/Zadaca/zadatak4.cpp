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

bool IsPrestupna(int g) {
    return (g % 4 == 0 && g % 100 != 0) || (g % 400 == 0);
}

int BrojDanaUMjesecu(int m, int g) {
    if (m == 2) {
        return IsPrestupna(g) ? 29 : 28;
    }
    if (m == 4 || m == 6 || m == 9 || m == 11) {
        return 30;
    }
    return 31;
}

int UkupnoDana(int d, int m, int g) {
    int ukupno = d;
    for (int y = 1; y < g; y++) {
        ukupno += IsPrestupna(y) ? 366 : 365;
    }
    for (int month = 1; month < m; month++) {
        ukupno += BrojDanaUMjesecu(month, g);
    }
    return ukupno;
}

int RazlikaDana(int d1, int m1, int g1, int d2, int m2, int g2) {
    int dni1 = UkupnoDana(d1, m1, g1);
    int dni2 = UkupnoDana(d2, m2, g2);
    int razlika = dni2 - dni1;
    return (razlika < 0) ? -razlika : razlika;
}

int main() {
    cout << RazlikaDana(28, 2, 2024, 1, 3, 2024) << endl;    // 2
    cout << RazlikaDana(28, 2, 2025, 1, 3, 2025) << endl;    // 1
    cout << RazlikaDana(31, 12, 2025, 1, 1, 2026) << endl;   // 1
    cout << RazlikaDana(1, 1, 2026, 1, 1, 2027) << endl;     // 365
    return 0;
}
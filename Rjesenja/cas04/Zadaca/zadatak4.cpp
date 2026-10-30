/*
    Cas 4, zadatak 4: najraniji od 5 datuma

    Napisati tijela dvije funkcije:
    - bool PrijeJe(const Datum& a, const Datum& b) vraca true ako je
      datum a prije datuma b. Porede se prvo godine, pa mjeseci, pa dani.
    - Datum Najraniji(Datum niz[], int n) vraca najraniji datum iz niza.

    Za datume 5.10.2025, 1.3.2024, 15.1.2026, 28.2.2024 i 1.3.2025
    najraniji je 28.2.2024.

    main je gotov: pokrenuti i uporediti ispis sa komentarima.
    cout ispisuje bool kao 1 (true) ili 0 (false).
*/
#include <iostream>
using namespace std;

struct Datum {
    int dan, mjesec, godina;
};

void Ispisi(const Datum& d) {
    cout << d.dan << "." << d.mjesec << "." << d.godina << endl;
}

bool PrijeJe(const Datum& a, const Datum& b) {
    // rjesenje ovdje

    return false;
}

Datum Najraniji(Datum niz[], int n) {
    // rjesenje ovdje

    return niz[0];
}

int main() {
    Datum datumi[5] = { {5, 10, 2025}, {1, 3, 2024}, {15, 1, 2026}, {28, 2, 2024}, {1, 3, 2025} };
    cout << PrijeJe(datumi[1], datumi[0]) << endl;   // 1: 1.3.2024 je prije 5.10.2025
    cout << PrijeJe(datumi[1], datumi[3]) << endl;   // 0: 1.3.2024 je poslije 28.2.2024
    Ispisi(Najraniji(datumi, 5));                    // 28.2.2024
    return 0;
}

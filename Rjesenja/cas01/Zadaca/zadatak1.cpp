/*
    Cas 1, zadatak 1: prijestupna godina

    Program trazi unos godine i ispise da li je prijestupna.
    Godina je prijestupna ako je djeljiva sa 4, a nije djeljiva sa 100,
    ili ako je djeljiva sa 400.

    Primjeri (unos -> ispis):
        2024 -> 2024 je prijestupna
        2000 -> 2000 je prijestupna
        1900 -> 1900 nije prijestupna
        2025 -> 2025 nije prijestupna

    Koristiti: %, &&, ||, if i else.
*/
#include <iostream>
using namespace std;

int main() {
    // rjesenje ovdje
int godina;
    cin >> godina;

    if ((godina % 4 == 0 && godina % 100 != 0) || (godina % 400 == 0)) {
        cout << godina << " je prijestupna" << endl;
    } else {
        cout << godina << " nije prijestupna" << endl;
    }
    return 0;
}

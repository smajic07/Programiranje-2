/*
    Cas 5, zadatak 1: zamjena preko pokazivaca i preko reference

    Napisati tijela dvije funkcije koje zamijene vrijednosti dvije varijable:
    - void ZamijeniP(int* a, int* b) radi preko pokazivaca. Ako je bilo
      koji pokazivac nullptr, funkcija ne radi nista.
    - void ZamijeniR(int& a, int& b) radi preko reference (kao na casu 2).

    main je gotov: pokrenuti i uporediti ispis sa komentarima.
    Na kraju u komentaru ispod odgovoriti: po cemu se razlikuju poziv
    i tijelo ove dvije funkcije, i koja od njih moze dobiti nullptr?

    Odgovor:

*/
#include <iostream>
using namespace std;

void ZamijeniP(int* a, int* b) {
    // rjesenje ovdje

}

void ZamijeniR(int& a, int& b) {
    // rjesenje ovdje

}

int main() {
    int x = 3, y = 9;
    ZamijeniP(&x, &y);               // saljemo adrese
    cout << x << " " << y << endl;   // 9 3
    ZamijeniR(x, y);                 // saljemo varijable
    cout << x << " " << y << endl;   // 3 9
    ZamijeniP(nullptr, &y);          // ne smije pasti
    cout << x << " " << y << endl;   // 3 9
    return 0;
}

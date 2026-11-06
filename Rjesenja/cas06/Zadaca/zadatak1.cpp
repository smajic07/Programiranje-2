/*
    Cas 6, zadatak 1: AlocirajTekst napamet

    Napisati tijelo funkcije char* AlocirajTekst(const char* tekst) BEZ
    GLEDANJA u cas06.cpp: pravi kopiju teksta na heapu i vraca njenu adresu.
    Za nullptr vraca nullptr.

    Iza svakog reda u komentaru napisi sta red radi i sta bi se desilo
    bez njega (npr. bez +1, bez provjere nullptr).

    main je gotov: pokrenuti i uporediti ispis sa komentarima.
    Zatim u terminalu:  bash ../../testiraj.sh zadatak1.cpp
    mora proci bez ijedne greske.
*/
#include <iostream>
#include <cstring>
using namespace std;

char* AlocirajTekst(const char* tekst) {
    // rjesenje ovdje

    return nullptr;
}

int main() {
    char* t1 = AlocirajTekst("Programiranje II");
    char* t2 = AlocirajTekst("");
    char* t3 = AlocirajTekst(nullptr);
    if (t1 != nullptr) cout << t1 << " " << strlen(t1) << endl;           // Programiranje II 16
    if (t2 != nullptr) cout << "[" << t2 << "] " << strlen(t2) << endl;   // [] 0
    cout << (t3 == nullptr) << endl;                                       // 1
    delete[] t1;
    delete[] t2;
    return 0;
}

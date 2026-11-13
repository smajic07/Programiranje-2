/*
    Cas 8, zadatak 1: struct DatumVrijeme sa 6 int* polja

    Na ispitima (2024-07-15, 2025-09-01, 2026-06-25) klasa DatumVrijeme cuva
    dan, mjesec, godinu, sate, minute i sekunde kao int* (svaki broj je
    jedan blok na heapu). Ovdje to radimo sa strukturom i funkcijama.

    Napisati tijela funkcija:
    1. DatumVrijeme Kreiraj(int d, int m, int g, int h, int min, int s):
       svako polje dobije svoj new int(...) sa datom vrijednoscu.
    2. DatumVrijeme DubokaKopija(const DatumVrijeme& izvor): novih 6 blokova
       sa istim vrijednostima (moze preko Kreiraj).
    3. void Obrisi(DatumVrijeme& dv): obrise svih 6 blokova i postavi
       pokazivace na nullptr.
    4. string ToString(const DatumVrijeme& dv): vrati tekst u formatu
       05.10.2025 09:30:00 (dan, mjesec, sati, minute i sekunde uvijek na
       dvije cifre).

    main je gotov: pokrenuti i uporediti ispis sa komentarima, pa
        bash ../../testiraj.sh zadatak1.cpp
    ne smije prijaviti ni gresku ni curenje.

    Savjet za ToString: ostringstream ss; pa ss << ... kao u cout, a na kraju
    return ss.str();  Vodece nule: ss << setfill('0') << setw(2) << broj;
    (setw vazi samo za SLJEDECI ispis, pa ga treba pisati ispred svakog broja).
    Moze i rucno: if (broj < 10) ss << "0";
*/
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

struct DatumVrijeme {
    int* dan;
    int* mjesec;
    int* godina;
    int* sati;
    int* minute;
    int* sekunde;
};

DatumVrijeme Kreiraj(int d, int m, int g, int h, int min, int s) {
    // rjesenje ovdje
    DatumVrijeme dv = { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr };
    return dv;
}

DatumVrijeme DubokaKopija(const DatumVrijeme& izvor) {
    // rjesenje ovdje
    DatumVrijeme dv = { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr };
    return dv;
}

void Obrisi(DatumVrijeme& dv) {
    // rjesenje ovdje
}

string ToString(const DatumVrijeme& dv) {
    // rjesenje ovdje
    return "";
}

int main() {
    DatumVrijeme a = Kreiraj(5, 10, 2025, 9, 30, 0);
    DatumVrijeme b = DubokaKopija(a);
    cout << ToString(a) << endl;            // 05.10.2025 09:30:00
    cout << (a.sati != b.sati) << endl;     // 1 (svaka ima svoj blok)

    if (b.sati != nullptr) *b.sati = 10;    // mijenja se samo b
    cout << ToString(a) << endl;            // 05.10.2025 09:30:00
    cout << ToString(b) << endl;            // 05.10.2025 10:30:00

    DatumVrijeme c = Kreiraj(31, 12, 2025, 23, 5, 7);
    cout << ToString(c) << endl;            // 31.12.2025 23:05:07

    Obrisi(a);
    Obrisi(b);
    Obrisi(c);
    cout << (a.dan == nullptr) << " " << (c.sekunde == nullptr) << endl;   // 1 1
    return 0;
}

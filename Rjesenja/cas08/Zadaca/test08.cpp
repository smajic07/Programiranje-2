/*
    MINI TEST, faza 1-2 (casovi 1-8)

    Pravila:
    - 45 minuta U KOMADU, bez starog koda, bez interneta i bez AI.
    - Kad istekne 45 minuta: commit i push, sta god da je uradjeno.
    - main je gotov: uporediti ispis sa komentarima, pa
          bash ../../testiraj.sh test08.cpp
      ne smije prijaviti ni gresku ni curenje (curenje = greska, kao na ispitu).
    - Prag za fazu 3 (klase): 4 od 5 zadataka tacno bez pomoci.
    - Pregledamo na pocetku casa 9.

    1. char* AlocirajTekst(const char* tekst): vrati kopiju teksta na heapu.
       Za nullptr vrati nullptr.

    2. Globalni dinamicki niz int* niz sa brojacem trenutno (dati ispod).
       bool Dodaj(int v): ako v vec postoji u nizu vrati false i ne mijenjaj
       nista; inace povecaj niz za 1 (novi blok, kopiranje, upis, brisanje
       starog), dodaj v na kraj i vrati true.
       void Ispis(): ispise elemente odvojene razmakom pa novi red.

    3. bool UkloniRaspon(int niz[], int& trenutno, int od, int koliko):
       ukloni koliko elemenata pocevsi od indeksa od, ostale pomjeri ulijevo
       i smanji trenutno. Ako je od < 0, koliko <= 0 ili raspon izlazi van
       niza, vrati false i ne mijenjaj nista.

    4. string GenerisiSifru(string imePrezime, int id): vrati sifru u formatu
       AB:2025-003 (prvo slovo imena i prvo slovo prezimena kao velika slova,
       pa :2025- i id na tri cifre sa vodecim nulama).

    5. Na dnu fajla, u komentaru, nacrtati memoriju (stack i heap) za
           Proizvod a; a.naziv = AlocirajTekst("Telefon"); a.cijena = 1500;
           Proizvod plitka = a;
       i u 2-3 recenice objasniti zasto program pukne ako se na kraju pozove
           delete[] a.naziv;  i  delete[] plitka.naziv;
*/
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

// ---------- 1 ----------
char* AlocirajTekst(const char* tekst) {
    // rjesenje ovdje
    return nullptr;
}

// ---------- 2 ----------
int* niz = nullptr;
int trenutno = 0;

bool Dodaj(int v) {
    // rjesenje ovdje
    return false;
}

void Ispis() {
    // rjesenje ovdje
    cout << endl;
}

// ---------- 3 ----------
bool UkloniRaspon(int niz[], int& trenutno, int od, int koliko) {
    // rjesenje ovdje
    return false;
}

// ---------- 4 ----------
string GenerisiSifru(string imePrezime, int id) {
    // rjesenje ovdje
    return "";
}

int main() {
    cout << "--- 1 ---" << endl;
    char* t = AlocirajTekst("Mini test");
    if (t != nullptr) cout << t << endl;        // Mini test
    cout << (AlocirajTekst(nullptr) == nullptr) << endl;   // 1
    delete[] t;

    cout << "--- 2 ---" << endl;
    Dodaj(5);
    Dodaj(3);
    cout << Dodaj(5) << endl;                   // 0 (duplikat)
    cout << Dodaj(8) << endl;                   // 1
    Ispis();                                    // 5 3 8
    delete[] niz;
    niz = nullptr;
    trenutno = 0;

    cout << "--- 3 ---" << endl;
    int brojevi[20] = { 0, 99, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int n = 11;
    cout << UkloniRaspon(brojevi, n, 2, 3) << endl;    // 1
    for (int i = 0; i < n; i++) cout << brojevi[i] << " ";
    cout << endl;                                      // 0 99 4 5 6 7 8 9
    cout << UkloniRaspon(brojevi, n, 6, 5) << endl;    // 0 (van niza)
    cout << n << endl;                                 // 8

    cout << "--- 4 ---" << endl;
    cout << GenerisiSifru("Amina Buric", 3) << endl;   // AB:2025-003
    cout << GenerisiSifru("adnan mehic", 15) << endl;  // AM:2025-015
    cout << GenerisiSifru("Mirza Ramic", 156) << endl; // MR:2025-156
    return 0;
}

/* ---------- 5 ----------
    Crtez:


    Zasto pukne:

*/

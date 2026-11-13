/*
    Cas 7, zadatak 4 (na papiru ili ovdje u komentaru): tabela tri oblika

    Popuni tabelu za sva tri oblika kolekcije sa casa:

    Oblik | Deklaracija             | Kako se dodaje element                | Sta se brise na kraju
    ------+-------------------------+-------------------------------------+----------------------
      1   | int niz[MAX]; int trenutno; | niz[trenutno++] = vrijednost;       | Ništa (nema dinamičke alokacije)
      2   | int* elementi[MAX];     | elementi[trenutno++] = new int(val); | Svaki element sa delete
      3   | int* sifre; string* nazivi; | Alokacija većeg niza, kopiranje, delete[] | Cijeli nizovi sa delete[]

    Zatim jednom recenicom: zasto se kod oblika 2 brise sa delete,
    a kod oblika 3 sa delete[]?

    Odgovor: Kod oblika 2 svaki element je alociran pojedinačno pomoću new pa se briše sa delete, dok su kod oblika 3 sami nizovi alocirani u komadu pomoću new[] pa se brišu sa delete[].

*/
#include <iostream>
using namespace std;

int main() {
    return 0;
}
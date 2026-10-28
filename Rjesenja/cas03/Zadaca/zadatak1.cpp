/*
    Cas 3, zadatak 1: Postoji i Dodaj bez duplikata

    Napisati tijela dvije funkcije:
    - bool Postoji(int niz[], int trenutno, int vrijednost) vraca true ako
      se vrijednost nalazi medju prvih trenutno elemenata niza.
    - bool Dodaj(int niz[], int& trenutno, int vrijednost) dodaje vrijednost
      na kraj niza i povecava trenutno. Vraca false i ne mijenja nista ako
      vrijednost vec postoji ili je niz pun (trenutno == MAX).

    main je gotov: pokrenuti i uporediti ispis sa komentarima.
    cout ispisuje bool kao 1 (true) ili 0 (false).

    Koristiti: for petlju za pretragu, a u Dodaj pozvati Postoji.
*/
#include <iostream>
using namespace std;

const int MAX = 20;

void Ispisi(int niz[], int n) {
    for (int i = 0; i < n; i++) cout << niz[i] << " ";
    cout << endl;
}

bool Postoji(int niz[], int trenutno, int vrijednost) {
    // rjesenje ovdje

    return false;
}

bool Dodaj(int niz[], int& trenutno, int vrijednost) {
    // rjesenje ovdje

    return false;
}

int main() {
    int niz[MAX];
    int trenutno = 0;
    cout << Dodaj(niz, trenutno, 5) << endl;     // 1
    cout << Dodaj(niz, trenutno, 3) << endl;     // 1
    cout << Dodaj(niz, trenutno, 5) << endl;     // 0: 5 vec postoji
    cout << Dodaj(niz, trenutno, 8) << endl;     // 1
    Ispisi(niz, trenutno);                       // 5 3 8
    cout << Postoji(niz, trenutno, 3) << " " << Postoji(niz, trenutno, 7) << endl;   // 1 0

    for (int i = 1; i <= 30; i++) Dodaj(niz, trenutno, i * 100);
    cout << trenutno << endl;                    // 20: niz je pun, visak je odbijen
    return 0;
}

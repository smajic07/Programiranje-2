#include <iostream>

using namespace std;
/*
int Kvadrat(int x);            // prototip (deklaracija): povratni tip, ime, parametri

void PovecajKopiju(int x) { x++; }
void PovecajOriginal(int& x) { x++; }

void Linija(int duzina = 20, char znak = '-') {
    for (int i = 0; i < duzina; i++) cout << znak;
    cout << endl;
}

int Max(int a, int b);            // preopterećenje: isto ime,
double Max(double a, double b);   // različiti tipovi parametara

int brojac = 0;              // globalna

void Funkcija() {
    int x = 5;               // lokalna: nestaje na kraju funkcije
    brojac++;
}
*/
bool IsPrestupna(int godina) {
    return (godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0;
}

int BrojDanaUMjesecu(int mjesec, int godina) {
    if (mjesec == 2) return IsPrestupna(godina) ? 29 : 28;
    if (mjesec == 4 || mjesec == 6 || mjesec == 9 || mjesec == 11) return 30;
    return 31;
}

int UkupnoDana(int dan, int mjesec, int godina) {
    int ukupno = dan;
    for (int g = 1; g < godina; g++) ukupno += IsPrestupna(g) ? 366 : 365;
    for (int m = 1; m < mjesec; m++) ukupno += BrojDanaUMjesecu(m, godina);
    return ukupno;
}

// ABC1 (a), ABC2 (b)
void Zamijeni(int& a, int& b) {   // bez & zamjena se ne vidi u main-u
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    /* PETLJE, FUNKCIJE */
    /*
    // for: kad unaprijed znamo koliko puta (početak; uslov; korak)
    for (int i = 1; i <= 5; i++)
        cout << i << " ";            // 1 2 3 4 5

    // while: uslov se provjerava PRIJE svakog prolaza
    int n = 2026, cifre = 0;
    while (n > 0) {
        n /= 10;
        cifre++;
    }                                // cifre = 4

    // do-while: tijelo se izvrši barem jednom, uslov se provjerava POSLIJE
    int ocjena;
    do {
        cout << "Unesi ocjenu (5-10): ";
        cin >> ocjena;
    } while (ocjena < 5 || ocjena > 10);

    cout << Kvadrat(4) << endl; // poziv: ispisuje 16

    int a = 5;
    PovecajKopiju(a);     // a je i dalje 5
    PovecajOriginal(a);   // a je sada 6
    // PovecajOriginal(5);   // GREŠKA: referenca mora biti vezana za varijablu

    int& r = a;           // r je drugo ime za a
    r = 10;               // a je sada 10

    cout << endl << "a: " << a << endl;

    Linija();          // 20 crtica
    Linija(5);         // 5 crtica
    Linija(5, '*');    // *****

    Funkcija();
    Funkcija();
    cout << brojac;          // 2
    // cout << x;            // GREŠKA: x ne postoji u main()
    for (int i = 0; i < 3; i++) { }
    // cout << i;            // GREŠKA: i živi samo unutar petlje

    */

    cout << UkupnoDana(1, 3, 2024) << endl;
    cout << UkupnoDana(28, 2, 2024) << endl;
    cout << IsPrestupna(2024) << endl;

    cout << UkupnoDana(1, 3, 2024) - UkupnoDana(28, 2, 2024) << endl;   // 2


    int x = 3, y = 7;
    Zamijeni(x, y);
    cout << x << " " << y << endl;    // 7 3 (bez & ostaje 3 7)

    return 0;
}
/*
int Kvadrat(int x) {           // definicija: tijelo funkcije
    return x * x;              // return vraća vrijednost i završava funkciju
}

void Pozdrav() {               // void: ne vraća ništa
    cout << "Zdravo" << endl;
}
*/
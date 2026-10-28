// Cas 3 - Nizovi: pretraga, umetanje, uklanjanje, enum
// Svaki primjer je jedna funkcija. U main-u otkomentarisati jedan po jedan
// poziv (oznaciti red pa Cmd+/), a prethodni zakomentarisati.
#include <iostream>
using namespace std;

const int MAX = 20;

void Ispisi(int niz[], int n) {
    for (int i = 0; i < n; i++) cout << niz[i] << " ";
    cout << endl;
}

// ===== 1. Staticki niz =====
void Primjer1() {
    const int VEL = 5;            // velicina statickog niza mora biti konstanta
    int ocjene[VEL] = { 8, 6, 10, 9, 7 };

    cout << ocjene[0] << endl;    // 8: prvi element
    cout << ocjene[4] << endl;    // 7: zadnji element, indeks je VEL - 1
    ocjene[1] = 7;                // promjena drugog elementa

    for (int i = 0; i < VEL; i++) // prolazak kroz cijeli niz
        cout << ocjene[i] << " ";
    cout << endl;                 // 8 7 10 9 7

    int a[3] = { 1, 2 };          // treci element je 0
    int b[] = { 4, 5, 6 };        // velicina 3 se izracuna sama
    Ispisi(a, 3);                 // 1 2 0
    Ispisi(b, 3);                 // 4 5 6
    // int n = 5; int c[n];       // GRESKA u Visual Studiju (g++ to dozvoljava)
    // cout << ocjene[5];         // cita tudju memoriju: vidi granice.cpp
}

// ===== 2. Niz kao parametar funkcije =====
double Prosjek(int niz[], int n) {                       // niz + broj elemenata
    int suma = 0;
    for (int i = 0; i < n; i++) suma += niz[i];
    return n > 0 ? (double)suma / n : 0;
}

bool Dodaj(int niz[], int& trenutno, int vrijednost) {   // trenutno se mijenja, zato &
    if (trenutno == MAX) return false;
    niz[trenutno] = vrijednost;
    trenutno++;
    return true;
}

void Primjer2() {
    int ocjene[MAX];
    int trenutno = 0;             // MAX je kapacitet, trenutno koliko je popunjeno
    Dodaj(ocjene, trenutno, 8);
    Dodaj(ocjene, trenutno, 6);
    Dodaj(ocjene, trenutno, 10);
    Ispisi(ocjene, trenutno);                  // 8 6 10
    cout << Prosjek(ocjene, trenutno) << endl; // 8
}

// ===== 3. Min, max, prosjek, brojanje i pretraga =====
void Primjer3() {
    int niz[] = { 4, 9, 2, 9, 7, 6 };
    int n = 6, trazeni = 7;

    int maxI = 0;                          // indeks najveceg elementa
    for (int i = 1; i < n; i++)
        if (niz[i] > niz[maxI]) maxI = i;

    int brojParnih = 0;
    for (int i = 0; i < n; i++)
        if (niz[i] % 2 == 0) brojParnih++;

    int indeks = -1;                       // linearna pretraga: -1 znaci "nije nadjeno"
    for (int i = 0; i < n; i++)
        if (niz[i] == trazeni) { indeks = i; break; }

    cout << "max: " << niz[maxI] << " na indeksu " << maxI << endl;  // 9 na indeksu 1
    cout << "parnih: " << brojParnih << endl;                         // 3
    cout << "indeks od 7: " << indeks << endl;                        // 4
}

// ===== 5. Bubble sort =====
void Primjer5() {
    int niz[] = { 5, 2, 9, 1 };
    int n = 4;
    for (int i = 0; i < n - 1; i++) {            // n - 1 prolaza
        for (int j = 0; j < n - 1 - i; j++)      // zadnjih i elemenata je vec na mjestu
            if (niz[j] > niz[j + 1]) {           // > za rastuce, < za opadajuce
                int temp = niz[j];
                niz[j] = niz[j + 1];
                niz[j + 1] = temp;
            }
        Ispisi(niz, n);                          // 2 5 1 9, pa 2 1 5 9, pa 1 2 5 9
    }
}

// ===== 6. Paralelni nizovi =====
void Primjer6() {
    int sifre[MAX];
    double cijene[MAX];
    int trenutno = 0;

    sifre[trenutno] = 101; cijene[trenutno] = 1500; trenutno++;
    sifre[trenutno] = 102; cijene[trenutno] = 55;   trenutno++;

    for (int i = 0; i < trenutno; i++)           // par broj i: sifre[i] i cijene[i]
        cout << sifre[i] << " - " << cijene[i] << " KM" << endl;
}

// ===== 7. enum i niz naziva =====
enum Kategorija { ELEKTRONIKA, KNJIGE, MODA, PREHRANA };
const char* KategorijaNazivi[] = { "ELEKTRONIKA", "KNJIGE", "MODA", "PREHRANA" };
enum Razred { PRVI = 1, DRUGI, TRECI, CETVRTI };   // brojanje moze poceti od 1

void Primjer7() {
    Kategorija k = KNJIGE;
    cout << k << endl;                        // 1: enum se ispisuje kao broj
    cout << KategorijaNazivi[k] << endl;      // KNJIGE: naziv iz paralelnog niza
    // Kategorija x = 2;                      // GRESKA: int se ne pretvara sam u enum
    Kategorija y = (Kategorija)2;
    cout << KategorijaNazivi[y] << endl;      // MODA
    cout << TRECI << endl;                    // 3
}

// ===== Zajednicko kodiranje (4. umetanje i uklanjanje) =====
// Student prvo na papiru pomjera elemente i diktira petlje, instruktor kuca.
bool DodajNaPoziciju(int niz[], int& trenutno, int pozicija, int vrijednost) {
    // kucamo zajedno
    if (trenutno >= MAX || pozicija > trenutno || pozicija < 0) {
        return false;
    }
    
    for (int i = trenutno; i > pozicija; i--) {
        niz[i] = niz[i - 1];
    }

    niz[pozicija] = vrijednost;
    trenutno++;

    return true;
}

bool UkloniRaspon(int niz[], int& trenutno, int od, int koliko) {
    // kucamo zajedno
    if (od < 0 || koliko <= 0 || od + koliko > trenutno) {
        return false;
    }

    for (int i = od; i + koliko < trenutno; i++) {
        niz[i] = niz[i + koliko];
    }

    trenutno -= koliko;

    return false;
}

void ZajednickoKodiranje() {
    int niz[MAX];
    int trenutno = 0;
    for (int i = 0; i < 10; i++) Dodaj(niz, trenutno, i);
    Ispisi(niz, trenutno);                     // 0 1 2 3 4 5 6 7 8 9

    DodajNaPoziciju(niz, trenutno, 1, 99);
    Ispisi(niz, trenutno);                     // 0 99 1 2 3 4 5 6 7 8 9

    UkloniRaspon(niz, trenutno, 2, 3);
    Ispisi(niz, trenutno);                     // 0 99 4 5 6 7 8 9  (test sa ispita 2025-09-01)
}

int main() {
    // Primjer1();                  // 1. staticki niz
    // Primjer2();               // 2. niz kao parametar funkcije
    // Primjer3();               // 3. max, brojanje, pretraga
    // Primjer5();               // 5. bubble sort
    // Primjer6();               // 6. paralelni nizovi
    // Primjer7();               // 7. enum i niz naziva
    ZajednickoKodiranje();    // 4. umetanje i uklanjanje
    return 0;
}

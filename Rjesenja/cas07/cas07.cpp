// Cas 7 - Dinamicki niz koji raste i tri oblika kolekcije
// Svaki primjer je jedna funkcija. U main-u otkomentarisati jedan po jedan
// poziv (oznaciti red pa Cmd+/), a prethodni zakomentarisati.
// Svaki program ide sa Fn+F5 I sa:  bash ../testiraj.sh cas07.cpp
#include <iostream>
#include <string>
using namespace std;

// ===== 1. Niz koji raste: cetiri koraka =====
// int*& jer funkcija mijenja pokazivac pozivaoca (cas 5), a ne samo svoju kopiju
void DodajNaKraj(int*& niz, int &trenutno, int vrijednost) {
    int* novi = new int[trenutno + 1];       // 1. novi blok veci za 1
    for (int i = 0; i < trenutno; i++)       // 2. kopiraj stare elemente
        novi[i] = niz[i];
    novi[trenutno] = vrijednost;             // 3. upisi novi element
    delete[] niz;                            //    i obrisi stari blok
    niz = novi;                              // 4. preusmjeri pokazivac
    trenutno++;
}

void Primjer1() {
    int* niz = nullptr;                      // na pocetku nema bloka
    int trenutno = 0;
    DodajNaKraj(niz, trenutno, 10);
    DodajNaKraj(niz, trenutno, 20);
    DodajNaKraj(niz, trenutno, 30);
    for (int i = 0; i < trenutno; i++) cout << niz[i] << " ";
    cout << endl;                            // 10 20 30
    delete[] niz;                            // na kraju jedan delete[]
    niz = nullptr;
    // Debugger: breakpoint na red "niz = novi;" u DodajNaKraj,
    // a u WATCH: niz, novi, *novi@3 (stara i nova adresa bloka)
}

// ===== 2. Uklanjanje uz cuvanje redoslijeda: pomjeranje ulijevo (kao cas 3) =====
void Primjer2() {
    int* niz = new int[5] { 10, 20, 30, 40, 50 };
    int trenutno = 5;
    int indeks = 1;                          // uklanjamo 20
    for (int i = indeks; i < trenutno - 1; i++)
        niz[i] = niz[i + 1];
    trenutno--;                              // blok ima 5 mjesta, ali vaze samo 4
    for (int i = 0; i < trenutno; i++) cout << niz[i] << " ";
    cout << endl;                            // 10 30 40 50
    delete[] niz;
    // Drugi nacin (zadaca 1): novi niz manji za 1, u koji se kopira sve osim uklonjenog.
}

// ===== 3. Tri oblika kolekcije =====
void Primjer3() {
    const int MAX = 5;

    // Oblik 1: staticki niz vrijednosti
    int vrijednosti[MAX];
    int broj1 = 0;
    vrijednosti[broj1++] = 7;
    vrijednosti[broj1++] = 8;
    cout << "Oblik 1: " << vrijednosti[0] << " " << vrijednosti[1] << endl;   // 7 8
    // na kraju se nista ne brise

    // Oblik 2: staticki niz pokazivaca, svaki element posebno na heapu
    int* elementi[MAX] = { nullptr };
    int broj2 = 0;
    elementi[broj2++] = new int(7);
    elementi[broj2++] = new int(8);
    cout << "Oblik 2: " << *elementi[0] << " " << *elementi[1] << endl;      // 7 8 (* jer je element adresa)
    for (int i = 0; i < broj2; i++) {        // na kraju: delete za svaki element
        delete elementi[i];
        elementi[i] = nullptr;
    }

    // Oblik 3: pokazivac na dinamicki niz koji raste
    int* niz = nullptr;
    int broj3 = 0;
    DodajNaKraj(niz, broj3, 7);
    // broj3 = 1; niz = { 7 };
    DodajNaKraj(niz, broj3, 8);
    // broj3 = 2; niz = { 7, 8 };
    cout << "Oblik 3: " << niz[0] << " " << niz[1] << endl;                  // 7 8
    delete[] niz;                            // na kraju jedan delete[]
    niz = nullptr;
}

// ===== 4. int* _trenutno (ispiti 2020-2024) =====
void Primjer4() {
    int niz[5];
    int* _trenutno = new int(0);
    niz[*_trenutno] = 42;          // indeks je vrijednost na adresi, ne sama adresa
    (*_trenutno)++;                // zagrade su obavezne: *_trenutno++ pomjera pokazivac!
    cout << *_trenutno << " " << niz[0] << endl;   // 1 42
    delete _trenutno;              // u destruktoru
    _trenutno = nullptr;

    // Namjerna greska iz postavki 2021-07-16, 2021-09-09 i 2023-09-18:
    // int* t = nullptr;           // brojac bez new
    // (*t)++;                     // otkomentarisati oba reda: Segmentation fault
}

/*
    ===== Zajednicko kodiranje, cas 7: kolekcija parova bez templatea (oblik 3) =====
    Sifre i nazivi proizvoda cuvaju se u dva dinamicka niza sa zajednickim
    brojacem trenutno: sifre[i] i nazivi[i] su isti proizvod.

    1. void Dodaj(int sifra, string naziv): oba niza narastu za 1, u cetiri
       koraka (novi blokovi veci za 1, kopiranje starih elemenata, upis novog
       para i brisanje starih blokova, preusmjeravanje pokazivaca), pa trenutno++.
    2. void Ispisi(): svaki par u svom redu, u formatu  101 - Laptop
    3. void ObrisiSve(): obrise oba niza, postavi ih na nullptr i trenutno na 0.

    ZajednickoKodiranje() doda tri proizvoda, ispise ih i sve obrise.
    Ocekivani ispis:
        101 - Laptop
        102 - Mis
        103 - Tastatura
        Ukupno: 3
        Poslije brisanja: 0
    Na kraju  bash ../testiraj.sh cas07.cpp  ne smije prijaviti curenje.
*/
int* sifre = nullptr;
string* nazivi = nullptr;
int trenutno = 0;

void Dodaj(int sifra, string naziv) {
    // kucamo zajedno
    int nova_velicina = trenutno + 1;
    int* nove_sifre = new int[nova_velicina];
    string* novi_nazivi = new string[nova_velicina];
    
    for (int i = 0; i < trenutno; i++) {
        nove_sifre[i] = sifre[i];
        novi_nazivi[i] = nazivi[i];
    }
    
    nove_sifre[trenutno] = sifra;
    novi_nazivi[trenutno] = naziv;

    delete[] sifre;
    delete[] nazivi;
    sifre = nove_sifre;
    nazivi = novi_nazivi;

    ++trenutno;
}

void Ispisi() {
    for (int i = 0; i < trenutno; i++) {
        cout << sifre[i] << " " << nazivi[i] << endl;
    }
}

void ObrisiSve() {
    delete[] sifre;
    delete[] nazivi;
    sifre = nullptr;
    nazivi = nullptr;
    trenutno = 0;
}

void ZajednickoKodiranje() {
    Dodaj(101, "Laptop");
    Dodaj(102, "Mis");
    Dodaj(103, "Tastatura");
    Ispisi();
    cout << "Ukupno: " << trenutno << endl;              // 3
    ObrisiSve();
    cout << "Poslije brisanja: " << trenutno << endl;    // 0
}

int main() {
    // Primjer1();                  // 1. niz koji raste (cetiri koraka)
    // Primjer2();               // 2. uklanjanje pomjeranjem ulijevo
    // Primjer3();               // 3. tri oblika kolekcije
    // Primjer4();               // 4. int* _trenutno
    ZajednickoKodiranje();    // kolekcija parova (oblik 3)
    return 0;
}

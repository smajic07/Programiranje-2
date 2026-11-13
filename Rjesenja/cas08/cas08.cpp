// Cas 8 - Plitka i duboka kopija
// Svaki primjer je jedna funkcija. U main-u otkomentarisati jedan po jedan
// poziv (oznaciti red pa Cmd+/), a prethodni zakomentarisati.
// Svaki program ide sa Fn+F5 I sa:  bash ../testiraj.sh cas08.cpp
#include <iostream>
#include <cstring>
using namespace std;

char* AlocirajTekst(const char* tekst) {      // sa casa 6
    if (tekst == nullptr) return nullptr;
    size_t vel = strlen(tekst) + 1;
    char* temp = new char[vel];
    strcpy_s(temp, vel, tekst);
    return temp;
}

struct Proizvod {
    char* naziv;       // tekst na heapu
    int cijena;        // obican broj
};

// ===== 1. Sta se kopira kad se kopira struktura: plitka kopija =====
void Primjer1() {
    Proizvod a;
    a.naziv = AlocirajTekst("Telefon");
    a.cijena = 1500;
    // nova "Telefon" na heapu, nova 1500 u memoriji na stacku
    Proizvod b = a;                 // kopira se SVAKO POLJE: cijena, ali i ADRESA teksta
    // ista "Telefon" na heapu, nova 1500 u memoriji na stacku
    cout << (void*)a.naziv << " " << (void*)b.naziv << endl;   // ista adresa: dijele tekst
    cout << &a << " " << &b << endl; 

    b.cijena = 999;                 // b ima svoju cijenu: a ostaje 1500
    b.naziv[0] = 'Y';               // ali tekst je zajednicki: mijenja se i a
    cout << a.naziv << " " << a.cijena << endl;   // Yelefon 1500
    cout << b.naziv << " " << b.cijena << endl;   // Yelefon 999

    delete[] a.naziv;               // tekst se brise JEDNOM
    a.naziv = nullptr;
    b.naziv = nullptr;
    // delete[] b.naziv;            // otkomentarisati: isti blok drugi put -> double free
    // cout << b.naziv << endl;     // otkomentarisati: viseci pokazivac (heap-use-after-free) ako nema 39-40
}

// ===== 2. Plitka kopija i bez "=": prenos po vrijednosti =====
void PromijeniKopiju(Proizvod p) {  // p je kopija od a, ali sa ISTOM adresom teksta
    p.naziv[0] = 'Z';               // mijenja zajednicki tekst
    p.cijena = 0;                   // mijenja samo svoju cijenu
}

void Primjer2() {
    Proizvod a;
    a.naziv = AlocirajTekst("Telefon");
    a.cijena = 1500;
    PromijeniKopiju(a);
    cout << a.naziv << " " << a.cijena << endl;   // Zelefon 1500
    delete[] a.naziv;
    a.naziv = nullptr;
}

// ===== 3. Pokazivac na pokazivac: dinamicki niz tekstova =====
void Primjer3() {
    int n = 3;
    char** tekstovi = new char*[n];                     // niz od n pokazivaca
    tekstovi[0] = AlocirajTekst("Amina");
    tekstovi[1] = AlocirajTekst("Goran");
    tekstovi[2] = AlocirajTekst("Berun");
    for (int i = 0; i < n; i++) cout << tekstovi[i] << " ";
    cout << endl;                                       // Amina Goran Berun
    for (int i = 0; i < n; i++) delete[] tekstovi[i];   // prvo svaki tekst
    delete[] tekstovi;                                  // pa niz pokazivaca
}

/*
    ===== Zajednicko kodiranje, cas 8: plitka i duboka kopija =====
    1. Proizvod Kreiraj(const char* naziv, int cijena): vrati novi Proizvod
       ciji je naziv KOPIJA teksta na heapu (AlocirajTekst), a cijena data cijena.
    2. Proizvod DubokaKopija(const Proizvod& izvor): vrati novi Proizvod
       sa SVOJIM tekstom (iskoristiti Kreiraj).
    3. U ZajednickoKodiranje():
       - a = Kreiraj("Telefon", 1500);
       - plitka = a;  i  duboka = DubokaKopija(a);
       - ispisi da li plitka i duboka imaju istu adresu teksta kao a (1 ili 0);
       - duboka.naziv[0] = 'X';  pa  plitka.naziv[0] = 'Y';
       - ispisi sva tri naziva;
       - obrisi tekstove tako da svaki blok bude obrisan TACNO JEDNOM.
    Ocekivani ispis:
        1 0
        Yelefon Yelefon Xelefon
    Ucenik prije pokretanja nacrta stack i heap. Na kraju i Fn+F5 i
    bash ../testiraj.sh cas08.cpp  moraju proci bez greske i bez curenja.
*/
Proizvod Kreiraj(const char* naziv, int cijena) {
    return { AlocirajTekst(naziv), cijena };
}

Proizvod DubokaKopija(const Proizvod& izvor) {
    return Kreiraj(izvor.naziv, izvor.cijena);
}

void ZajednickoKodiranje() {
    // kucamo zajedno: student diktira, instruktor kuca
    Proizvod a = Kreiraj("Telefon", 1500);
    Proizvod a_plitka = a, a_duboka = DubokaKopija(a);
    cout << ((void*)a_plitka.naziv == (void*)a.naziv) << endl;
    cout << ((void*)a_duboka.naziv == (void*)a.naziv) << endl;
    a_duboka.naziv[0] = 'X';
    a_plitka.naziv[0] = 'Y';
    cout << a.naziv << " "<< a_plitka.naziv << " "<< a_duboka.naziv << " " << endl;
    // a_plitka.naziv -> ista adresa kao i -> a.naziv
    delete[] a.naziv;
    // delete[] a_plitka.naziv; // - obrisali smo vec, kompajler vec tu adresu smatra slobodnom, ako se ovo pokrene dobije se error
    delete[] a_duboka.naziv;
}

int main() {
    // Primjer1();                  // 1. plitka kopija sa "="
    // Primjer2();               // 2. plitka kopija pri prenosu po vrijednosti
    // Primjer3();               // 3. char** : dinamicki niz tekstova
    ZajednickoKodiranje();    // Kreiraj i DubokaKopija
    return 0;
}

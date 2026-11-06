// Cas 6 - Dinamicka memorija: new i delete
// Svaki primjer je jedna funkcija. U main-u otkomentarisati jedan po jedan
// poziv (oznaciti red pa Cmd+/), a prethodni zakomentarisati.
// Od ovog casa svaki program ide sa Fn+F5 I sa:  bash ../testiraj.sh cas06.cpp
#include <iostream>
#include <cstring>
using namespace std;

// ===== 1. Jedan podatak na heapu: new i delete =====
void Primjer1() {
    int* p = new int(5);     // na heapu napravi int sa vrijednoscu 5 i vrati njegovu adresu
    cout << *p << endl;      // 5
    *p = 8;                  // mijenja vrijednost na heapu
    cout << *p << endl;      // 8
    delete p;                // vrati memoriju; p i dalje cuva staru adresu
    p = nullptr;             // zato ga odmah postavimo na nullptr

    int* q = new int;        // bez pocetne vrijednosti: sadrzaj je nasumican
    double* d = new double(1499.99);
    cout << *d << endl;      // 1499.99
    delete q;                // svaki new ima svoj delete
    delete d;
}

// ===== 2. Niz na heapu: new[] i delete[] =====
void Primjer2() {
    int n;
    cout << "Koliko ocjena: ";
    cin >> n;                        // velicina se zna tek tokom izvrsavanja
    double* ocjene = new double[n];  // niz od n elemenata na heapu
    for (int i = 0; i < n; i++)
        ocjene[i] = 6 + i;           // koristi se kao obican niz
    for (int i = 0; i < n; i++)
        cout << ocjene[i] << " ";
    cout << endl;                    // za n = 3: 6 7 8
    delete[] ocjene;                 // niz se brise sa delete[]
    ocjene = nullptr;
}

// ===== Na casu: datum na heapu, bez klase =====
void DatumNaHeapu() {
    int* dan = new int(5);
    int* mjesec = new int(10);
    int* godina = new int(2025);
    cout << *dan << "." << *mjesec << "." << *godina << endl;   // 5.10.2025

    int* dan2 = dan;                 // drugi pokazivac na ISTI blok, a ne nova kopija
    delete dan;
    delete mjesec;
    delete godina;
    // delete dan2;                  // otkomentarisati: dvostruko brisanje, program pukne
    dan = mjesec = godina = dan2 = nullptr;
}

/*
    ===== Zajednicko kodiranje, cas 6 =====
    1. char* AlocirajTekst(const char* tekst) pravi kopiju teksta na heapu
       i vraca njenu adresu. Za nullptr vraca nullptr.
       Mjesta treba strlen + 1 (za '\0'); kopira se sa strcpy_s.
    2. U ZajednickoKodiranje():
       - napravi int na heapu sa vrijednoscu 5, ispisi ga, obrisi i postavi na nullptr;
       - ucitaj n, napravi niz od n ocjena (double) na heapu, ucitaj ocjene,
         ispisi prosjek i obrisi niz;
       - napravi naziv = AlocirajTekst("Laptop FITLx"), ispisi ga i obrisi.
    Na kraju i Fn+F5 i  bash ../testiraj.sh cas06.cpp  moraju proci bez greske.
*/ 
char* AlocirajTekst(const char* tekst) {
    if (tekst == nullptr) return nullptr;
    
    int n = strlen(tekst) + 1;
    char* temp = new char[n];
    strcpy_s(temp, n, tekst);

    return temp;
}

// kucamo zajedno: student diktira, instruktor kuca
void ZajednickoKodiranje() {
    int* a = new int(5);
    cout << "a: " << *a << endl;
    delete a;
    a = nullptr;

    int n;
    cin >> n;
    
    double* ocjene = new double[n];

    double suma = 0;
    for (int i = 0; i < n; i++) {
        cin >> ocjene[i];
        suma += ocjene[i];
    }

    double prosjek = suma / n;

    cout << "prosjek: " << prosjek << endl;;

    delete[] ocjene;
    ocjene = nullptr;

    char* naziv = AlocirajTekst("Laptop FITLx");
    cout << *naziv << endl;
    for (int i = 0; i < strlen(naziv); i++) {
        cout << naziv[i];
    }

    cout << endl;

    delete[] naziv;
    naziv = nullptr;
}

int main() {
    // Primjer1();                  // 1. new i delete
    // Primjer2();               // 2. new[] i delete[] (unos u TERMINAL)
    // DatumNaHeapu();           // na casu: datum na heapu, pa dvostruko brisanje
    ZajednickoKodiranje();    // AlocirajTekst
    return 0;
}

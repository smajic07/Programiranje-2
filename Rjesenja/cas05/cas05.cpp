// Cas 5 - Memorija, adrese i pokazivaci
// Svaki primjer je jedna funkcija. U main-u otkomentarisati jedan po jedan
// poziv (oznaciti red pa Cmd+/), a prethodni zakomentarisati.
// Za svaki primjer ucenik PRVO crta memoriju (kutije i strelice), pa tek onda pokrecemo.
#include <iostream>
using namespace std;

// ===== 1. Stack i heap =====
void Primjer1() {
    int x = 65;                    // lokalna varijabla: zivi na stacku
    int* h = new int(7);           // new: novi int na heapu (detaljno na casu 6)
    cout << "adresa x (stack): " << &x << endl;   // 0x7ff...
    cout << "adresa *h (heap): " << h << endl;    // 0x55... ili 0x56...
    cout << x << " " << *h << endl;               // 65 7
    delete h;                      // ono sto je napravljeno sa new, brise se sa delete
    cout << x << " " << *h << endl;               // 65 7
    // Debugger: breakpoint na cout, pa u DEBUG CONSOLE:  -exec x/4xb &x
    // ispis 0x41 0x00 0x00 0x00: int ima 4 bajta, najnizi ide prvi, 0x41 je 65
}

// ===== 2. Adresa i pokazivac =====
void Primjer2() {
    int x = 5;
    int* p = &x;                   // & daje adresu od x; p "pokazuje na" x
    cout << p << endl;             // adresa, svaki put druga
    cout << *p << endl;            // 5: * ide na adresu i cita vrijednost
    *p = 10;                       // mijenja x preko pokazivaca
    cout << x << endl;             // 10
    int* q = nullptr;              // pokazivac koji ne pokazuje nigdje
    if (q != nullptr) cout << *q;  // uvijek provjera prije *
    // cout << *q;                 // GRESKA tokom izvrsavanja: Segmentation fault
    // double d = 2.5;
    // int* r = &d;                // GRESKA pri kompajliranju: int* smije pokazivati samo na int
}

// ===== 3. Pokazivac kao parametar =====
void Uvecaj(int* p) { if (p != nullptr) (*p)++; }
void UvecajR(int& r) { r++; }

void Primjer3() {
    int x = 5;
    Uvecaj(&x);                    // saljemo adresu: x = 6
    cout << x << endl;             // 6
    UvecajR(x);                    // referenca (cas 2): x = 7
    cout << x << endl;             // 7
    Uvecaj(nullptr);               // dozvoljeno, funkcija to provjeri
    // UvecajR(nullptr);           // GRESKA: referenca ne moze biti "nista"
}

// ===== 4. Niz i pokazivac =====
void Primjer4() {
    int niz[3] = { 10, 20, 30 };
    int* p = niz;                  // isto sto i &niz[0]
    cout << *p << endl;            // 10
    cout << *(p + 1) << endl;      // 20: p + 1 je adresa sljedeceg int-a
    cout << p[2] << endl;          // 30: p[i] je kraci zapis za *(p + i)
    cout << p << " " << p + 1 << endl;   // adrese se razlikuju za 4 (jedan int)
    p++;                           // p sada pokazuje na niz[1]
    cout << *p << endl;            // 20
}

// ===== 5. const char*, char* i pokazivac na strukturu =====
struct Datum { int dan, mjesec, godina; };

void Primjer5() {
    const char* ime = "Amar";      // tekst u navodnicima je konstanta
    // char* t = "Amar";           // GRESKA u Visual Studiju 2022 (g++ samo upozori)
    // ime[0] = 'O';               // GRESKA: konstanta se ne mijenja
    cout << ime << " " << ime[1] << endl;   // Amar m

    Datum d = { 1, 1, 2026 };
    Datum* pd = &d;
    (*pd).dan = 14;
    cout << d.dan << "." << d.mjesec << "." << pd->godina << endl;   // 14.1.2026
    pd->dan = 15;                  // isto sto i (*pd).dan = 15
    (*pd).mjesec = 3;
    cout << d.dan << "." << d.mjesec << "." << pd->godina << endl;   // 15.3.2026
}

// 1 2 3 4

/*
    Zajednicko kodiranje, cas 5: pokazivaci korak po korak.
    Prije svakog reda ucenik kaze sta ce se desiti i nacrta stack
    (varijabla = kutija sa vrijednoscu, pokazivac = kutija sa strelicom).

    1. Napravi int x = 5 i pokazivac p koji pokazuje na x.
       Ispisi x, adresu od x, p i *p.
           Ocekivano: 5, ista adresa dva puta, 5

    2. Preko p (bez pisanja x =) promijeni x u 10.

    3. Funkcija void Uvecaj(int* p) poveca za 1 vrijednost na koju
       p pokazuje, ako p nije nullptr (vec postoji iznad, iz Primjera 3).
       Pozovi je za x i ispisi x.
           Ocekivano: 11

    4. Napravi niz {1, 2, 3} i pokazivac q na njegov prvi element.
       Ispisi drugi element preko q[...] i treci preko *(q + ...).
           Ocekivano: 2 3

    5. Napravi Datum d = {1, 1, 2026} i pokazivac pd na d.
       Preko pd i operatora -> postavi dan na 15 i ispisi d.dan.
           Ocekivano: 15
*/

void UvecajV2(int* p) {
    if (p != nullptr) {
        (*p)++;
    }
}

// ===== Zajednicko kodiranje: ucenik crta stack poslije svakog reda =====
void ZajednickoKodiranje() {
    // 1.
    int x = 5;
    int* p = &x;
    cout << x << " " << &x << " " << p << " " << *p << endl;
    
    // 2.
    *p = 10;
    cout << *p << " " << x << endl; 

    // 3.
    UvecajV2(&x);
    cout << x << endl;

    // 4.
    int niz[4] = {1, 2, 3};
    int* q = &niz[0]; // = niz
    cout << q[1] << " " << *(q + 2) << endl;

    // 5.
    Datum d = {1, 1, 2026};
    Datum* pd = &d;   
    d.dan = 15;
    // d->dan = 11; - GREŠKA
    // pd.dan = 15; - GREŠKA
    pd->dan = 15;
    cout << d.dan << endl;

    (*pd).dan = 18;
    cout << d.dan << endl;

    d.dan = 30;
    cout << d.dan << endl;
}

int main() {
    // Primjer1();                  // 1. stack i heap, bajtovi u memoriji
    // Primjer2();               // 2. adresa i pokazivac
    // Primjer3();               // 3. pokazivac kao parametar
    // Primjer4();               // 4. niz i pokazivac
    // Primjer5();               // 5. const char* i ->
    ZajednickoKodiranje();    // crtanje stacka
    return 0;
}

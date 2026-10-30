// Cas 4 - Tekst (char niz i string) i struct
// Svaki primjer je jedna funkcija. U main-u otkomentarisati jedan po jedan
// poziv (oznaciti red pa Cmd+/), a prethodni zakomentarisati.
#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;

// ===== 1. Tekst kao niz znakova =====
void Primjer1() {
    char ime[30] = "Amar Macic";   // 10 znakova + '\0', ostalih 19 mjesta se ne koristi
    char kratko[4] = "Ana";        // 3 slova + '\0'
    // char premalo[3] = "Ana";    // GRESKA: nema mjesta za '\0'
    char c = ime[0];               // 'A'
    ime[0] = 'O';                  // tekst je sada "Omar Macic"
    // ime = "Novo ime";           // GRESKA: niz se ne dodjeljuje sa =, koristi se strcpy_s
    cout << c << endl;             // A
    cout << ime << endl;           // Omar Macic
    cout << kratko << endl;        // Ana
    cout << "'" << ime[4] << "'" << endl;        // Ana
    cout << (int)ime[10] << endl;  // 0: znak '\0' na kraju teksta
}

// ===== 2. Funkcije za char nizove (<cstring>) =====
void Primjer2() {
    char ime[30];
    strcpy_s(ime, 30, "Amar");                         // kopira tekst
    strcat_s(ime, 30, " Macic");                       // dodaje na kraj
    cout << ime << endl;                               // Amar Macic
    cout << strlen(ime) << endl;                       // 10
    cout << strcmp(ime, "Amar Macic") << endl;         // 0: jednaki
    cout << (strcmp("Ana", "Berin") < 0) << endl;      // 1: Ana je po abecedi prije
    cout << (strstr(ime, "Mac") != nullptr) << endl;   // 1: "Mac" postoji u tekstu
    cout << (char)toupper('a') << endl;                // A
    // if (ime == "Amar Macic")    // GRESKA u logici: poredi adrese, a ne slova
}

// ===== 3. Ucitavanje teksta sa razmacima (unos kucati u TERMINAL) =====
void Primjer3() {
    char ime[30];
    cout << "Ime i prezime: ";
    cin.getline(ime, 30);          // char niz: cijeli red, najvise 29 znakova
    cout << "[" << ime << "]" << endl;

    string puno;
    cout << "Grad: ";
    getline(cin, puno);            // string: cijeli red, bez ogranicenja
    cout << "[" << puno << "]" << endl;

    int godine;
    cout << "Godine: ";
    cin >> godine;                 // korisnik ukuca 20 i Enter
    cin.ignore();                  // preskoci Enter koji je ostao (zakomentarisati da se vidi problem)
    cout << "Hobi: ";
    getline(cin, puno);            // bez ignore bi ovdje odmah procitao prazan red
    cout << "[" << puno << "]" << endl;
}

// ===== 4. std::string =====
void Primjer4() {
    string ime = "Amina";
    string puno = ime + " Buric";                      // spajanje: "Amina Buric"
    cout << puno << endl;                              // Amina Buric
    cout << puno.length() << endl;                     // 11
    cout << puno[0] << endl;                           // A
    cout << (puno == "Amina Buric") << endl;           // 1: string se poredi po slovima
    cout << puno.find(' ') << endl;                    // 5: pozicija prvog razmaka
    cout << (puno.find('x') == string::npos) << endl;  // 1: nije nadjeno
    cout << puno.substr(6, 5) << endl;                 // Buric: od pozicije 6, duzine 5
    cout << to_string(42) + "!" << endl;               // 42!: broj u tekst
    cout << stoi("2026") + 1 << endl;                  // 2027: tekst u broj
}

/*
char* AlocirajTekst(const char* tekst) {
    if (tekst == nullptr) return nullptr;
    int vel = strlen(tekst) + 1;      // +1 za '\0'
    char* novi = new char[vel];       // novi blok memorije na heapu (cas 6)
    strcpy_s(novi, vel, tekst);
    return novi;
}
*/

// ===== 5. Prelaz izmedju string i const char* =====
void Primjer5() {
    string s = "Amar Macic";
    const char* c = s.c_str();     // string u const char*: pogled na isti tekst
    string s2 = c;                 // const char* u string: kopija teksta
    cout << c << endl;             // Amar Macic
    cout << strlen(c) << endl;     // 10: radi i funkcija za char nizove
    cout << s2 << endl;            // Amar Macic
    // char* kopija = AlocirajTekst(c);   // ovako ispiti pune char* atribut (cas 6)
}

// ===== 6. struct =====
struct Datum {
    int dan, mjesec, godina;
};

void Ispisi(const Datum& d) {      // struktura se prenosi kao const referenca
    cout << d.dan << "." << d.mjesec << "." << d.godina << endl;
}

void Primjer6() {
    Datum d1 = { 5, 10, 2025 };    // polja redom: dan, mjesec, godina
    Datum d2;
    d2.dan = 15; d2.mjesec = 1; d2.godina = 2026;
    Datum d3 = d1;                 // kopija svih polja
    Datum termini[5];              // niz struktura
    termini[0] = d2;
    Ispisi(termini[0]);            // 15.1.2026
    Ispisi(d3);                    // 5.10.2025
}

/*
    Zajednicko kodiranje, cas 4: tri funkcije koje VRACAJU tekst,
    a ne ispisuju ga. Ispis radi ZajednickoKodiranje() u main-u.

    1. string Inicijali(const string& imePrezime)
       Vraca velika pocetna slova imena i prezimena.
           Inicijali("Amina Buric")  -> "AB"
           Inicijali("amar macic")   -> "AM"

    2. string ToString(const Datum& d)
       Vraca datum u formatu DD.MM.GGGG, sa vodecom nulom za dan
       i mjesec manje od 10.
           {5, 10, 2025}  -> "05.10.2025"
           {15, 1, 2026}  -> "15.01.2026"

    3. string GenerisiSifru(string imePrezime, int id)   (ispitna funkcija)
       Vraca sifru u formatu XY:2025-NNN: inicijali, dvotacka, fiksna
       godina 2025, crtica i id sa vodecim nulama do tri cifre.
           GenerisiSifru("Amina Buric", 3)   -> "AB:2025-003"
           GenerisiSifru("Amar Macic", 15)   -> "AM:2025-015"
*/

// ===== Zajednicko kodiranje: student diktira, instruktor kuca =====
string Inicijali(const string& imePrezime) {          // "amina buric" -> "AB"
    string inicijali; // ""

    inicijali += (char)toupper(imePrezime[0]); // "A"

    const int indeksRazmaka = imePrezime.find(' '); // 5

    inicijali += (char)toupper(imePrezime[indeksRazmaka + 1]); // "AB"

    return inicijali;
}

string ToString(const Datum& d) {                     // 5.10.2025 -> "05.10.2025"
    string s = "";

    s += d.dan < 10 ? "0" : "";
    s += to_string(d.dan) + ".";

    s += d.mjesec < 10 ? "0" : "";
    s += to_string(d.mjesec) + ".";

    s += to_string(d.godina);

    return s;
}

string GenerisiSifru(string imePrezime, int id) {     // ("Amina Buric", 3) -> "AB:2025-003"
    string sifra = Inicijali(imePrezime) + ":2025-";

    if (id < 10) sifra += "00";
    else if (id < 100) sifra += "0";

    sifra += to_string(id);

    return sifra;
}

void ZajednickoKodiranje() {
    char ime[30];
    strcpy_s(ime, "Amar Macic");
    cout << strlen(ime) << endl;                       // 10
    cout << (strcmp(ime, "Amar Macic") == 0) << endl;  // 1
    cout << Inicijali(ime) << endl;                    // AM
    Datum d = { 5, 10, 2025 };
    cout << ToString(d) << endl;                       // 05.10.2025
    cout << GenerisiSifru("Amina Buric", 3) << endl;   // AB:2025-003
}

int main() {
    // Primjer1();                  // 1. char niz i '\0'
    // Primjer2();               // 2. funkcije za char nizove
    // Primjer3();               // 3. getline i cin.ignore (unos u TERMINAL)
    // Primjer4();               // 4. std::string
    // Primjer5();               // 5. string i const char*
    // Primjer6();               // 6. struct
    ZajednickoKodiranje();    // Inicijali, ToString, GenerisiSifru
    return 0;
}

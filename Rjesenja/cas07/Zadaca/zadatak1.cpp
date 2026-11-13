/*
    Cas 7, zadatak 1: oblik 3, Ukloni koji smanjuje niz

    Kolekcija parova sa casa: sifre i nazivi su dva dinamicka niza sa
    zajednickim brojacem trenutno. Dodaj, Ispisi i ObrisiSve su gotovi.

    Napisati tijelo funkcije bool Ukloni(int sifra) koja:
    - nadje par sa tom sifrom; ako ga nema, vrati false i ne mijenja nista,
    - napravi nove nizove manje za 1 i u njih kopira sve parove OSIM
      uklonjenog, cuvajuci redoslijed,
    - obrise stare nizove, preusmjeri pokazivace i smanji trenutno.
    Kad se ukloni zadnji par, nizovi postaju nullptr (new int[0] se ne pravi).

    main je gotov: pokrenuti i uporediti ispis sa komentarima, pa
        bash ../../testiraj.sh zadatak1.cpp
    ne smije prijaviti ni gresku ni curenje.

    Savjet: dva brojaca, i kroz stari niz i j kroz novi; j se ne povecava
    za preskoceni element.
*/
#include <iostream>
#include <string>
using namespace std;

int* sifre = nullptr;
string* nazivi = nullptr;
int trenutno = 0;

void Dodaj(int sifra, string naziv) {
    int* tempS = new int[trenutno + 1];
    string* tempN = new string[trenutno + 1];
    for (int i = 0; i < trenutno; i++) {
        tempS[i] = sifre[i];
        tempN[i] = nazivi[i];
    }
    tempS[trenutno] = sifra;
    tempN[trenutno] = naziv;
    delete[] sifre;
    delete[] nazivi;
    sifre = tempS;
    nazivi = tempN;
    trenutno++;
}

void Ispisi() {
    for (int i = 0; i < trenutno; i++)
        cout << sifre[i] << " - " << nazivi[i] << endl;
    cout << "---" << endl;
}

void ObrisiSve() {
    delete[] sifre;
    delete[] nazivi;
    sifre = nullptr;
    nazivi = nullptr;
    trenutno = 0;
}

bool Ukloni(int sifra) {
    int indeks = -1;
    for (int i = 0; i < trenutno; i++) {
        if (sifre[i] == sifra) {
            indeks = i;
            break;
        }
    }
    if (indeks == -1) return false;

    if (trenutno == 1) {
        delete[] sifre;
        delete[] nazivi;
        sifre = nullptr;
        nazivi = nullptr;
        trenutno = 0;
        return true;
    }

    int* tempS = new int[trenutno - 1];
    string* tempN = new string[trenutno - 1];

    for (int i = 0, j = 0; i < trenutno; i++) {
        if (i != indeks) {
            tempS[j] = sifre[i];
            tempN[j] = nazivi[i];
            j++;
        }
    }

    delete[] sifre;
    delete[] nazivi;
    sifre = tempS;
    nazivi = tempN;
    trenutno--;

    return true;
}

int main() {
    Dodaj(101, "Laptop");
    Dodaj(102, "Mis");
    Dodaj(103, "Tastatura");
    Dodaj(104, "Monitor");
    cout << Ukloni(102) << endl;    // 1
    Ispisi();                        // 101 - Laptop, 103 - Tastatura, 104 - Monitor
    cout << Ukloni(999) << endl;    // 0: nema te sifre
    cout << Ukloni(101) << Ukloni(104) << Ukloni(103) << endl;   // 111
    cout << trenutno << " " << (sifre == nullptr) << endl;      // 0 1
    ObrisiSve();
    return 0;
}
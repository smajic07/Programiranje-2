/*
    Cas 3, zadatak 4: paralelni nizovi sifara i cijena

    Sifra proizvoda je u nizu sifre, a njegova cijena u nizu cijene,
    na istom indeksu. Oba niza dijele isti brojac trenutno.

    Napisati tijela tri funkcije:
    - bool DodajPar(int sifre[], double cijene[], int& trenutno, int sifra, double cijena)
      dodaje par na kraj oba niza; vraca false ako je niz pun.
    - void IspisiParove(int sifre[], double cijene[], int trenutno)
      ispise svaki par u redu, u formatu:  101 - 1500 KM
    - int IndeksNajskupljeg(double cijene[], int trenutno)
      vraca INDEKS najskupljeg proizvoda (ne cijenu), da bi main
      preko istog indeksa dobio i sifru.

    Ocekivani ispis:
        101 - 1500 KM
        102 - 55 KM
        103 - 1499.5 KM
        Najskuplji: 101 (1500 KM)
*/
#include <iostream>
using namespace std;

const int MAX = 20;

bool DodajPar(int sifre[], double cijene[], int& trenutno, int sifra, double cijena) {
    if (trenutno == MAX) {
        return false;
    }
    sifre[trenutno] = sifra;
cijene[trenutno] = cijena;
    trenutno++;
    return true;
}

void IspisiParove(int sifre[], double cijene[], int trenutno) {
    for (int i = 0; i < trenutno; i++) {
        cout << sifre[i] << " - " << cijene[i] << " KM" << endl;
    }
}

int IndeksNajskupljeg(double cijene[], int trenutno) {
    if (trenutno <= 0) return -1;
    int maxIndeks = 0;
    for (int i = 1; i < trenutno; i++) {
        if (cijene[i] > cijene[maxIndeks]) {
            maxIndeks = i;
        }
    }
    return maxIndeks;
}

int main() {
    int sifre[MAX] = {};
    double cijene[MAX] = {};
    int trenutno = 0;
    DodajPar(sifre, cijene, trenutno, 101, 1500);
    DodajPar(sifre, cijene, trenutno, 102, 55);
    DodajPar(sifre, cijene, trenutno, 103, 1499.5);
    IspisiParove(sifre, cijene, trenutno);
    int m = IndeksNajskupljeg(cijene, trenutno);
    cout << "Najskuplji: " << sifre[m] << " (" << cijene[m] << " KM)" << endl;   // 101 (1500 KM)
    return 0;
}
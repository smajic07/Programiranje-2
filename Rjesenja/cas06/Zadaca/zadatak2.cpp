/*
    Cas 6, zadatak 2: n imena na heapu

    Napisati tijela tri funkcije:
    - char* AlocirajTekst(const char* tekst): prepisi svoju iz zadatka 1.
    - int UcitajImena(char* imena[], int max): korisnik unese broj imena
      (najvise max), pa svako ime u svom redu (ime moze imati razmak).
      Svako ime se cuva kao kopija na heapu: imena[i] = AlocirajTekst(unos).
      Funkcija vraca koliko je imena ucitano.
    - void ObrisiImena(char* imena[], int n): obrise sve tekstove sa delete[]
      i postavi pokazivace na nullptr.

    Primjer unosa (kuca se u TERMINAL):
        3
        Amina Buric
        Amar Macic
        Maid Ramic
    Ispis iz main-a:
        1. Amina Buric
        2. Amar Macic
        3. Maid Ramic
        Obrisano: 1

    Pazi: poslije cin >> n treba cin.ignore() (cas 4).
    Zasto kopija: unos je jedan privremeni char niz koji se u svakom krugu
    petlje prepisuje, pa bi bez kopije svi pokazivaci pokazivali na isti tekst.
    Provjera: bash ../../testiraj.sh zadatak2.cpp ne smije prijaviti curenje.
*/
#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 10;

char* AlocirajTekst(const char* tekst) {
    if (tekst == nullptr) return nullptr;
    int duzina = strlen(tekst);
    char* noviTekst = new char[duzina + 1];
    strcpy(noviTekst, tekst);
    return noviTekst;
}

int UcitajImena(char* imena[], int max) {
    int n;
    cin >> n;
    cin.ignore();
    if (n > max) n = max;
    for (int i = 0; i < n; i++) {
        char unos[100];
        cin.getline(unos, 100);
        imena[i] = AlocirajTekst(unos);
    }
    return n;
}

void ObrisiImena(char* imena[], int n) {
    for (int i = 0; i < n; i++) {
        delete[] imena[i];
        imena[i] = nullptr;
    }
}

int main() {
    char* imena[MAX] = { nullptr };
    int n = UcitajImena(imena, MAX);
    for (int i = 0; i < n; i++)
        cout << i + 1 << ". " << imena[i] << endl;
    ObrisiImena(imena, n);
    bool sviObrisani = true;
    for (int i = 0; i < n; i++)
        if (imena[i] != nullptr) sviObrisani = false;
    cout << "Obrisano: " << sviObrisani << endl;   // 1
    return 0;
}

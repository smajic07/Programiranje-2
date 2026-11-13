/*
    Cas 7, zadatak 2: oblik 2, DodajNaPoziciju i UkloniSaPozicije

    Kolekcija je staticki niz pokazivaca: svaki element je jedan int
    napravljen sa new. Ispisi i ObrisiSve su gotovi.

    Napisati tijela dvije funkcije:
    - bool DodajNaPoziciju(int pozicija, int vrijednost): pomjeri pokazivace
      od pozicije udesno (od kraja, kao na casu 3) i na poziciju stavi
      new int(vrijednost). Vraca false ako je niz pun ili je pozicija
      van 0..trenutno.
    - bool UkloniSaPozicije(int pozicija): OBRISE element sa te pozicije
      (delete), pomjeri ostale pokazivace ulijevo i zadnje mjesto postavi
      na nullptr. Vraca false ako je pozicija van 0..trenutno-1.
      Bez delete curi memorija (ta greska postoji u rjesenju 2020-07-15).

    main je gotov: pokrenuti i uporediti ispis sa komentarima, pa
        bash ../../testiraj.sh zadatak2.cpp
    ne smije prijaviti ni gresku ni curenje.
*/
#include <iostream>
using namespace std;

const int MAX = 10;
int* elementi[MAX] = { nullptr };
int trenutno = 0;

void Ispisi() {
    for (int i = 0; i < trenutno; i++) cout << *elementi[i] << " ";
    cout << endl;
}

void ObrisiSve() {
    for (int i = 0; i < trenutno; i++) {
        delete elementi[i];
        elementi[i] = nullptr;
    }
    trenutno = 0;
}

bool DodajNaPoziciju(int pozicija, int vrijednost) {
    if (trenutno == MAX || pozicija < 0 || pozicija > trenutno)
        return false;

    for (int i = trenutno; i > pozicija; i--) {
        elementi[i] = elementi[i - 1];
    }
    elementi[pozicija] = new int(vrijednost);
    trenutno++;
    return true;
}

bool UkloniSaPozicije(int pozicija) {
    if (pozicija < 0 || pozicija >= trenutno)
        return false;

    delete elementi[pozicija];

    for (int i = pozicija; i < trenutno - 1; i++) {
        elementi[i] = elementi[i + 1];
    }
    elementi[trenutno - 1] = nullptr;
    trenutno--;
    return true;
}

int main() {
    DodajNaPoziciju(0, 10);
    DodajNaPoziciju(1, 30);
    DodajNaPoziciju(1, 20);
    Ispisi();                                    // 10 20 30
    UkloniSaPozicije(0);
    Ispisi();                                    // 20 30
    cout << DodajNaPoziciju(5, 99) << endl;    // 0: pozicija van granica
    cout << UkloniSaPozicije(7) << endl;       // 0
    cout << (elementi[2] == nullptr) << endl;  // 1: zadnje mjesto oslobodjeno
    ObrisiSve();
    return 0;
}
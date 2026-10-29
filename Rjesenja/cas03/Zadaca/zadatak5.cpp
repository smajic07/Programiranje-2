/*
    Cas 3, zadatak 5: ispis kategorija pomocu enum-a i niza naziva

    Napisati tijelo funkcije void IspisiKategorije() koja jednom petljom
    ispise sve kategorije, svaku u svom redu, u formatu  broj: NAZIV

    Ocekivani ispis:
        0: ELEKTRONIKA
        1: KNJIGE
        2: MODA
        3: PREHRANA

    Koristiti: for petlju od ELEKTRONIKA do PREHRANA i niz KategorijaNazivi.
    Vrijednosti enum-a su brojevi 0 do 3, pa se mogu koristiti kao indeksi.
*/
#include <iostream>
using namespace std;

enum Kategorija { ELEKTRONIKA, KNJIGE, MODA, PREHRANA };
const char* KategorijaNazivi[] = { "ELEKTRONIKA", "KNJIGE", "MODA", "PREHRANA" };

void IspisiKategorije() {
    for (int i = ELEKTRONIKA; i <= PREHRANA; i++) {
        cout << i << ": " << KategorijaNazivi[i] << endl;
    }
}

int main() {
    IspisiKategorije();
    return 0;
}

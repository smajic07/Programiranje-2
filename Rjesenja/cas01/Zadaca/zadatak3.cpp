/*
    Cas 1, zadatak 3: cijena sa popustom

    Program trazi unos cijene (realan broj) i kategorije (cijeli broj od 1 do 4)
    i ispise konacnu cijenu.
    Kategorija 2 dobija 10% popusta, a kategorije 1, 3 i 4 placaju punu cijenu.
    Za kategoriju van 1-4 ispisati "Nepostojeca kategorija, cijena bez popusta."
    i zatim punu cijenu.

    Primjeri (unos -> ispis):
        100 2 -> Konacna cijena: 90 KM
        100 1 -> Konacna cijena: 100 KM
        250 2 -> Konacna cijena: 225 KM
        100 5 -> Nepostojeca kategorija, cijena bez popusta.
                 Konacna cijena: 100 KM

    Koristiti: double za cijenu, if, else if.
*/
#include <iostream>
using namespace std;

int main() {
    // rjesenje ovdje
    double cijena;
    int kategorija;

    cin >> cijena >> kategorija;

    if (kategorija == 2) {
        cout << "Konacna cijena: " << cijena - (cijena * 0.10) << " KM" << endl;
    } else if (kategorija == 1 || kategorija == 3 || kategorija == 4) {
        cout << "Konacna cijena: " << cijena << " KM" << endl;
    } else {
        cout << "Nepostojeca kategorija, cijena bez popusta." << endl;
        cout << "Konacna cijena: " << cijena << " KM" << endl;
    }

    return 0;

}

// Cas 6: cetiri greske sa memorijom. Pokazati jednu po jednu:
// otkomentarisati jedan poziv u main-u (ostale zakomentarisane),
// pa Fn+F5, a zatim u terminalu:  bash ../testiraj.sh greske.cpp
#include <iostream>
using namespace std;

void Curenje() {
    int* a = new int(5);
    a = new int(6);          // CURENJE: blok sa 5 vise nema pokazivac
    cout << *a << endl;
    delete a;                // brise samo blok sa 6
}

void VisecPokazivac() {
    int* b = new int(7);
    delete b;
    cout << *b << endl;      // VISECI POKAZIVAC: cita obrisanu memoriju
}

void DvostrukoBrisanje() {
    int* c = new int(8);
    int* d = c;              // d pokazuje na ISTI blok
    delete c;
    delete d;                // DVOSTRUKO BRISANJE: isti blok drugi put
}

void PogresanDelete() {
    int* niz = new int[5];
    niz[0] = 1;
    cout << niz[0] << endl;
    delete niz;              // GRESKA: niz napravljen sa new[] brise se sa delete[]
}

int main() {
    Curenje();
    // VisecPokazivac();
    // DvostrukoBrisanje();
    // PogresanDelete();
    return 0;
}

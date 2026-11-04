// Cas 5: vracanje adrese lokalne varijable.
// g++ upozori "address of local variable 'a' returned", a program padne
// (Segmentation fault). Adresa lokalne varijable se nikad ne vraca.
#include <iostream>
using namespace std;

/*
Veza sa ispitom!!
Ista greška je u studentskom rješenju ispita 2026-06-25 G1. 
Funkcija tamo prima vector po vrijednosti, dakle kopiju, 
i vraća adresu elementa iz te kopije, a kopija nestane na kraju funkcije.
*/
int* Losa() {
    int a = 5;
    return &a;     // a nestaje kad funkcija zavrsi -> viseci pokazivac
}

int main() {
    int* p = Losa();
    cout << *p << endl;
    return 0;
}

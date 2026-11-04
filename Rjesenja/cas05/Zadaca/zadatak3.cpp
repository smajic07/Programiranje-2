/*
    Cas 5, zadatak 3: crtez stacka

    1. Bez pokretanja, na papiru nacrtaj stack za program ispod, u trenutku
       kad je izvrsen red  int* q = &c;  (varijabla je kutija sa imenom
       i vrijednoscu, pokazivac je kutija sa strelicom).
    2. Upisi u main-u iza "ocekujem:" sta ce se ispisati.
    3. Postavi breakpoint na prvi cout, Fn+F5, i u WATCH dodaj
       &a, &c, p, q, *p i *q. Provjeri da p ima istu adresu kao &a,
       a q istu kao &c.
    4. Fn+F5 do kraja i uporedi ispis sa svojim odgovorima.
*/
#include <iostream>
using namespace std;

int main() {
    int a = 1, b = 2, c = 3;
    int* p = &a;
    int* q = &c;
    cout << *p + *q << endl;              // ocekujem:
    *q = 7;
    p = q;
    *p = *p + b;
    cout << a << " " << b << " " << c << endl;   // ocekujem:
    return 0;
}

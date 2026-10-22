/*
    Cas 2, zadatak 5: f(int x), f(int& x) i f(const int& x)

    Prvo bez pokretanja upisati u main-u iza "ocekujem:" sta ce
    se ispisati. Zatim pokrenuti i uporediti. Na kraju otkomentarisati
    red B(5) i procitati gresku.

    Odgovoriti svojim rijecima:
    1. Sta funkcija dobije u svakom od tri slucaja?
    2. U kojem slucaju funkcija moze promijeniti varijablu iz main-a?
    3. Zasto B(5) ne radi, a A(5) i C(5) rade?
    4. Kada se koristi const & (npr. const string&) umjesto kopije?

    Odgovor:

*/
#include <iostream>
using namespace std;

void A(int x) { x++; }
void B(int& x) { x++; }
void C(const int& x) { cout << x << endl; }

int main() {
    int a = 5;
    A(a);
    cout << a << endl;   // ocekujem:
    B(a);
    cout << a << endl;   // ocekujem:
    C(a);                // ocekujem:
    // B(5);             // otkomentarisati na kraju
    return 0;
}

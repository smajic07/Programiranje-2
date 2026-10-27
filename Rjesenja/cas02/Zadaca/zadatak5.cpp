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
    1. A dobije kopiju vrijednosti, B dobije referencu tj. 
    original, C dobije konstantnu referencu.
    2. Samo u slučaju B.
    3. B(5) ne radi jer int& mora izmijeniti konkretnu varijablu iz memorije, a broj 5 nije varijabla.   
    A(5) radi jer napravi novu kopiju broja 5, a C(5) radi jer const dozvoljava C++ da privremeno zapamti broj 5 bez prava izmjene.
    4. Kada želimo izbjeći bespotrebno kopiranje velikih objekata, a kada zelimo osigurati da funkcija ne može promijeniti podatke.
*/
#include <iostream>
using namespace std;

void A(int x) { x++; }
void B(int& x) { x++; }
void C(const int& x) { cout << x << endl; }

int main() {
    int a = 5;
    A(a);
    cout << a << endl;   // ocekujem: 5
    B(a);
    cout << a << endl;   // ocekujem: 6
    C(a);                // ocekujem: 6
    // B(5);             // otkomentarisati na kraju
    return 0;
}
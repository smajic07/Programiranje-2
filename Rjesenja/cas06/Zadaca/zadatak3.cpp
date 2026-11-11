/*
    Cas 6, zadatak 3: nadji tri greske sa memorijom

    U main-u ispod su tri greske sa memorijom: curenje memorije, viseci
    pokazivac i pogresno brisanje niza. Program se kompajlira i sa Fn+F5
    uglavnom "radi".

    1. Bez pokretanja nadji sve tri greske ocima. Iza svake u komentaru
       napisi koja je i sta se tu desava u memoriji.
    2. Pokreni u terminalu:  bash ../../testiraj.sh zadatak3.cpp
       testiraj.sh javlja jednu po jednu gresku. Popravi je i pokreni
       ponovo, sve dok ne prodje bez ijedne greske.
    3. Ispravan program ispisuje 6, 7 i 81, svaki u svom redu.
*/
#include <iostream>
using namespace std;

int main() {
    int* a = new int(5);
    delete a; // Memory Leak: Pokazivač a je prepisan sa novom alokacijom prije nego što je stara oslobođena, pa se gubi adresa memorije sa vrijednošću 5.
    a = new int(6);
    cout << *a << endl;

    int* b = new int(7);
    delete b;
    cout << *b << endl; // Viseći pokazivač: Pristupa se memoriji na koju b još uvijek pokazuje iako je ta memorija obrisana.

    int* niz = new int[10];
    for (int i = 0; i < 10; i++) niz[i] = i * i;
    cout << niz[9] << endl;
    delete[] niz; // Pogrešno brisanje niza: Korištenjem običnog delete umjesto delete[] niz dolazi do nedefinisanog ponašanja jer je memorija alocirana sa new[]

    delete a;
    return 0;
}

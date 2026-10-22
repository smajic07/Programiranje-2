/*
    Cas 1, zadatak 4: zasto 5 / 2 daje 2?

    1. Jednom recenicom odgovori na pitanje u komentaru ispod.
    2. U main ispisi 5 / 2, 5 / 2.0 i (double)5 / 2 i provjeri da li ispis
       potvrdjuje tvoj odgovor.

    Ocekivani ispis:
        2 2.5 2.5

    Odgovor: Kad dijelimo dva cijelam broja, decimalni dio se brise i ostane nam samo cijeli broj.
    A ako nam je bar jedan clan double ili float, decimalna vrijednost ostaje.
*/
#include <iostream>
using namespace std;

int main() {
    // rjesenje ovdje
    cout << 5 / 2 << " " << 5 / 2.0 << " " << (double)5 / 2 << endl;

    return 0;
}

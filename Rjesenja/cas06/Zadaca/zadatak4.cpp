/*
    Cas 6, zadatak 4: Spoji dva teksta

    Napisati tijelo funkcije char* Spoji(const char* a, const char* b)
    koja na heapu napravi NOVI tekst "a b" (a, razmak, b) i vrati njegovu
    adresu. Ako je a ili b nullptr, vraca nullptr.

    Primjeri:
        Spoji("Amina", "Buric")  -> "Amina Buric"
        Spoji("FIT", "Mostar")   -> "FIT Mostar"   (duzina 10)
        Spoji(nullptr, "x")      -> nullptr

    Koristiti: strlen, new char[...], strcpy_s i strcat_s.
    Pazi koliko mjesta treba: slova od a, razmak, slova od b i '\0'.
    main brise rezultate sa delete[]; provjeri sa
        bash ../../testiraj.sh zadatak4.cpp
*/
#include <iostream>
#include <cstring>
using namespace std;

char* Spoji(const char* a, const char* b) {
    // rjesenje ovdje

    return nullptr;
}

int main() {
    char* s1 = Spoji("Amina", "Buric");
    char* s2 = Spoji("FIT", "Mostar");
    char* s3 = Spoji(nullptr, "x");
    if (s1 != nullptr) cout << s1 << endl;                       // Amina Buric
    if (s2 != nullptr) cout << s2 << " " << strlen(s2) << endl;  // FIT Mostar 10
    cout << (s3 == nullptr) << endl;                             // 1
    delete[] s1;
    delete[] s2;
    return 0;
}

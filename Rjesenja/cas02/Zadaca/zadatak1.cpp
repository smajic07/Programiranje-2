/*
    Cas 2, zadatak 1: SumaCifara i IsProst

    Napisati tijela dvije funkcije:
    - int SumaCifara(int n) vraca zbir cifara broja n.
    - bool IsProst(int n) vraca true ako je n prost broj, inace false.
      Prost broj je veci od 1 i djeljiv je samo sa 1 i sa samim sobom.

    main je gotov: pokrenuti i uporediti ispis sa komentarima.
    cout ispisuje bool kao 1 (true) ili 0 (false).

    Primjeri:
        SumaCifara(2026) -> 10
        SumaCifara(7)    -> 7
        IsProst(17)      -> 1
        IsProst(21)      -> 0
        IsProst(2)       -> 1
        IsProst(1)       -> 0

    Koristiti: while, for, % i /.
*/
#include <iostream>
using namespace std;

int SumaCifara(int n) {
    // rjesenje ovdje

    return 0;
}

bool IsProst(int n) {
    // rjesenje ovdje

    return false;
}

int main() {
    cout << SumaCifara(2026) << endl;   // 10
    cout << SumaCifara(7) << endl;      // 7
    cout << IsProst(17) << endl;        // 1
    cout << IsProst(21) << endl;        // 0
    cout << IsProst(2) << endl;         // 1
    cout << IsProst(1) << endl;         // 0
    return 0;
}

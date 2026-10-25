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
    int suma = 0;
    if (n < 0) n = -n;
    while (n > 0) {
        suma += n % 10;
        n /= 10;
    }
    return suma;
}

bool IsProst(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
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
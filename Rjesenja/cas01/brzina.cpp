#include <iostream>
using namespace std;
int main() {
    long long s = 0;
    for (long long i = 0; i < 100000000; i++)
        s += i % 7;
    cout << s << endl;
    return 0;
}

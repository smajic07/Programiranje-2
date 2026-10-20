#!/bin/bash
# testiraj.sh - kompajlira i pokrece ispitni zadatak na Macu ili Linuxu (npr. GitHub Codespaces).
# Upotreba:   ./testiraj.sh Ispit.cpp      (ulaz iz fajla: ./testiraj.sh Program.cpp < ulaz.txt)
# Fajl fit_mac.h mora biti u istom folderu kao ova skripta.

if [ -z "$1" ]; then
    echo "Upotreba: ./testiraj.sh Ispit.cpp"
    exit 1
fi

SKRIPTA="$(cd "$(dirname "$0")" && pwd)"
IZVOR="$1"
RADNI="${IZVOR%.cpp}_mac.cpp"

# Mac: clang++ i alat leaks. Linux: g++, a curenje memorije prijavljuje sam AddressSanitizer.
if [ "$(uname)" = "Darwin" ]; then KOMPAJLER=clang++; else KOMPAJLER=g++; fi

# 1. Kopija sa izmjenama koje Visual Studio dozvoljava, a clang/gcc ne:
#    void main -> int main, exception("poruka") -> runtime_error("poruka"), bez system("cls") i system("pause>0")
perl -pe 's/\bvoid\s+main\s*\(/int main(/; s/\bthrow\s+exception\s*\(/throw runtime_error(/g; s/system\("cls"\);//g; s/system\("pause>0"\);//g' "$IZVOR" > "$RADNI"

# 2. Verzija sa AddressSanitizerom i UBSanom: hvata citanje izvan niza, dvostruki delete, koristenje obrisane memorije
$KOMPAJLER -std=c++17 -g -Wall -Wno-sign-compare -pthread -include "$SKRIPTA/fit_mac.h" -fsanitize=address,undefined -fno-omit-frame-pointer \
    -o program_asan "$RADNI" || exit 1

echo "================ Pokretanje sa provjerom memorije ================"
if [ ! -t 0 ]; then
    ./program_asan                  # ulaz iz fajla: ./testiraj.sh program.cpp < ulaz.txt
elif grep -Eq 'cin[[:space:]]*>>|getline[[:space:]]*\([[:space:]]*cin' "$RADNI"; then
    ./program_asan                  # program trazi unos: kucate ga u terminalu
else
    yes '' | ./program_asan         # ispitni main: yes '' salje Enter svakom cin.get()
fi

if [ "$(uname)" = "Darwin" ]; then
    # 3. Na Macu AddressSanitizer ne prijavljuje curenje, pa to radi alat leaks nad obicnom verzijom
    clang++ -std=c++17 -g -include "$SKRIPTA/fit_mac.h" -o program "$RADNI" || exit 1
    echo
    echo "================ Provjera curenja memorije (leaks) ================"
    yes '' | leaks --atExit -- ./program > leaks_izvjestaj.txt 2>&1
    grep -E "leaks for|Process .* leaks" leaks_izvjestaj.txt || tail -n 5 leaks_izvjestaj.txt
    echo "(cijeli izvjestaj: leaks_izvjestaj.txt)"
fi

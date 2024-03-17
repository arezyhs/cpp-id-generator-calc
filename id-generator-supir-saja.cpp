/* INI KODINGAN UDAH GA KEPAKE BOS,
PAKE YANG INCLUDE ORDER AJE!
    */

#include <iostream>
#include <iomanip>
#include <string>
#include <unordered_set>
#include <cstdlib>
#include <ctime>
using namespace std;

// arezyh.s
// generator ID untuk supir baru/update supir.
string generatorIDSupir(string nama, char gender, string tanggal_lahir, unordered_set<string>& duplikasiID) {
    // nama depan nama - nama akhir kan?
    int digitDuaPertama = abs((tolower(nama[0]) - 'a' + 1) - (tolower(nama[nama.length() - 1]) - 'a' + 1));
    // kalau L = 1, kalau P = 0.
    int digitKetiga = (gender == 'L') ? 1 : 0;
    // angka terakhir dari DD-MM-YYYY dijumlah, terus lanjut mod 9.
    int digitKeempat = ((tanggal_lahir[1] - '0') + (tanggal_lahir[4] - '0') + (tanggal_lahir[9] - '0')) % 9;
    // mulai dari nol ya, naik kalau ada duplikasi.
    int digitKelima = 0;

    string IDSupir; // buat nyimpen ID supir.
    do {
        // digabungin semua tuh...
        IDSupir = to_string(digitDuaPertama) +
                   to_string(digitKetiga) +
                   to_string(digitKeempat) +
                   to_string(digitKelima);
        // + 0 di awal jika < 5 digit
        if (IDSupir.length() < 5) {
            IDSupir = string(5 - IDSupir.length(), '0') + IDSupir;
        }
        digitKelima++; // digitKelimat +1 kalau ada duplikasi.

    } while (duplikasiID.find(IDSupir) != duplikasiID.end());
// arezyh.s
    duplikasiID.insert(IDSupir);
    cout << "ID Supir   : " << IDSupir << endl;
    return IDSupir;
}

int main() {
    unordered_set<string> duplikasiID;  // simpen ID yang udah jadi di sini.

    // UBAH DATA SUPIR DI BAWAH!!!
    string namaSupir = "Akbar SetiyawA"; // ubah nama supir di sini
    char genderSupir = 'L'; // ubah gender supir 'L' atau 'P' di sini
    string tanggalLahirSupir = "27-10-2002"; // ubah tanggalLahirSupir dengan formad DD-MM-YYYY di sini.
    string IDSupir = generatorIDSupir(namaSupir, genderSupir, tanggalLahirSupir, duplikasiID);
    cout << "ID Supir   : " << IDSupir << endl;

    return 0;
}
// arezyh.s

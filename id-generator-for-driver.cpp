#include <iostream>
#include <iomanip>
#include <string>
#include <unordered_set>
#include <cstdlib>
#include <ctime>
using namespace std;

// arezyh.s
// generator ID untuk supir baru/update supir.
string buatIDBaru(string nama, char gender, string tanggal_lahir, unordered_set<string>& duplikasiID) {
    int digitDuaPertama = abs((tolower(nama[0]) - 'a' + 1) - (tolower(nama[nama.length() - 1]) - 'a' + 1));
    int digitKetiga = (gender == 'L') ? 1 : 0;
    int digitKeempat = ((tanggal_lahir[1] - '0') + (tanggal_lahir[4] - '0') + (tanggal_lahir[9] - '0')) % 9;

    int digitKelima = 0;
    string hasilID;

    do {
        hasilID = to_string(digitDuaPertama) +
                   to_string(digitKetiga) +
                   to_string(digitKeempat) +
                   to_string(digitKelima);
        // + 0 di awal jika < 5 digit
        if (hasilID.length() < 5) {
            hasilID = string(5 - hasilID.length(), '0') + hasilID;
        }
        digitKelima++;

        if (digitKelima > 99) {
            cerr << "Error: Infinite loop detected. Unable to generate a unique ID." << endl;
            exit(EXIT_FAILURE);
        }

    } while (duplikasiID.find(hasilID) != duplikasiID.end());

    duplikasiID.insert(hasilID);
    cout << "ID Supir   : " << hasilID << endl;

    return hasilID;
}

int main() {
    unordered_set<string> duplikasiID;  // Untuk melacak ID yang telah dibuat

    // UBAH DATA SUPIR DI BAWAH!!!
    string namaSupir = "Akbar Setiyawan"; // Change the name of the driver
    char genderSupir = 'L';
    string tanggalLahirSupir = "27-10-2002";
    string userID = buatIDBaru(namaSupir, genderSupir, tanggalLahirSupir, duplikasiID);

    return 0;
}
// arezyh.s

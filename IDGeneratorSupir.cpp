#include <iostream>
#include <iomanip>
#include <string>
#include <unordered_set>
#include <cstdlib>
#include <ctime>
using namespace std;

// ID Generator (FIX)
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

        // Menambahkan leading zero jika jumlah digit kurang dari 5
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

    // Pindahkan cout ke sini agar ID ditampilkan dengan benar
    cout << "ID yang dihasilkan: " << hasilID << endl;

    return hasilID;
}

int main() {
    unordered_set<string> duplikasiID;  // Untuk melacak ID yang telah dibuat

    // fungsi loop untuk memasukkan data Dummy sebanyak n.
    for (int i = 0; i < 21; i++) {
        // Contoh penggunaan
        string nama = "Akbar Setiyawn";
        char gender = 'L';
        string tanggal_lahir = "27-02-2002";
        // Panggil fungsi buatIDBaru
        string userID = buatIDBaru(nama, gender, tanggal_lahir, duplikasiID);
    }

    return 0;
}

#include <iostream>
#include <iomanip>
#include <string>
#include <unordered_set>
#include <cstdlib>
#include <ctime>
using namespace std;

// GENERATOR ID STRUKTUR DATA
string buatIDBaru(string nama, char gender, string tanggal_lahir, unordered_set<string>& duplikasiID) {
    // DIGIT DUA PERTAMA
    int digitDuaPertama = abs((tolower(nama[0]) - 'a' + 1) - (tolower(nama[nama.length() - 1]) - 'a' + 1));

    // DIGIT KETIGA
    int digitKetiga = (gender == 'L') ? 1 : 0;

    // DIGIT KEEMPAT
    int digitKeempat = ((tanggal_lahir[1] - '0') + (tanggal_lahir[4] - '0') + (tanggal_lahir[9] - '0')) % 9;

    // DIGIT KELIMA
    int digitKelima = 0; // default = 0
    string hasilID;

    // CEK DUPLIKASI ID, MENJADI 6 DIGIT APABILA DIGIT KELIMA > 9
    do {
        // Tampilkan ID sebagai 5 digit jika digitKelima belum mencapai puluhan
        hasilID = to_string(digitDuaPertama) + to_string(digitKetiga) + to_string(digitKeempat) + to_string(digitKelima);
        
        if (duplikasiID.find(hasilID) == duplikasiID.end()) {
            cout << "ID yang dihasilkan: " << setw(2) << setfill('0') << digitDuaPertama << digitKetiga << digitKeempat << digitKelima << endl;
        }

        digitKelima++; // increment digit ke-5 apabila ada id yang sama.

    } while (duplikasiID.find(hasilID) != duplikasiID.end());

    // Tambahkan ID ke dalam set
    duplikasiID.insert(hasilID);

    return hasilID;
}

int main() {
    unordered_set<string> duplikasiID;  // Untuk melacak ID yang telah dibuat

    // fungsi loop untuk memasukkan data SUGENG PANGESTU
    for (int i = 0; i < 21; i++) {
        // Contoh penggunaan
        string nama = "Sugeng Pangestu";
        char gender = 'L';
        string tanggal_lahir = "21-02-1999";
        // Panggil fungsi buatIDBaru
        string userID = buatIDBaru(nama, gender, tanggal_lahir, duplikasiID);
    }

    return 0;
}

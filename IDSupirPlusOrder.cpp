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
    cout << "ID SUPIR   : " << hasilID << endl;

    return hasilID;
}

string buatIDOrder(char platNomor, string idSupir, string tujuan, string namaPelanggan) {
    int urutanAlphabet = tolower(platNomor) - 'a' + 1;
    int digitIDSupir = stoi(idSupir) ;
    int urutanTujuan = 0;

    if (tujuan.length() >= 2) {
        char lastChar1 = tolower(tujuan[tujuan.length() - 2]);
        char lastChar2 = tolower(tujuan[tujuan.length() - 1]);
        urutanTujuan = (lastChar1 - 'a' + 1) + (lastChar2 - 'a' + 1);
    } else {
        cerr << "Error: MINIMAL HARUS 2 CHAR PADA DESTINASI TUJUAN!" << endl; // buat test
        exit(EXIT_FAILURE);
    }

    int jumlahHurufNama = 0;
    for (char huruf : namaPelanggan) {
        if (isalpha(huruf)) {
            jumlahHurufNama += tolower(huruf) - 'a' + 1;
        }
    }

    int digitTerakhir = jumlahHurufNama % 10;

    // Format ID order
    return to_string(urutanAlphabet) +
           // Pad digitIDSupir with leading zeros to make it a 5-digit number
           to_string(digitIDSupir / 10000) +
           to_string(digitIDSupir % 10000) +
           to_string(urutanTujuan) +
           to_string(digitTerakhir);
}


// TEST DATA SUPIR DAN PELANGGAN DI SINI!!!!!!! UBAH DATANYA SENDIRI!!!!
int main() {
    unordered_set<string> duplikasiID;  // Untuk melacak ID yang telah dibuat

    // UBAH DATA SUPIR DI BAWAH!!!
    string namaSupir = "Sugeng Cihuy";
    char genderSupir = 'L';
    string tanggalLahirSupir = "21-02-1999";
    string userID = buatIDBaru(namaSupir, genderSupir, tanggalLahirSupir, duplikasiID);

    // UBAH DATA PELANGGAN DI BAWAH
    char platNomor = 'L';
    string idSupir = userID; // ambil dari ID SUPIR
    string tujuan = "Ketintang";
    string namaPelanggan = "Komeng";

    string orderID = buatIDOrder(platNomor, idSupir, tujuan, namaPelanggan);
    cout << "ID Order   : " << orderID << endl;

    return 0;
}

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

    string hasilID; // buat nyimpen ID supir.
    do {
        // digabungin semua tuh...
        hasilID = to_string(digitDuaPertama) +
                   to_string(digitKetiga) +
                   to_string(digitKeempat) +
                   to_string(digitKelima);
        // + 0 di awal jika < 5 digit
        if (hasilID.length() < 5) {
            hasilID = string(5 - hasilID.length(), '0') + hasilID;
        }
        digitKelima++; // digitKelimat +1 kalau ada duplikasi.

    } while (duplikasiID.find(hasilID) != duplikasiID.end());
// arezyh.s
    duplikasiID.insert(hasilID);
    cout << "ID Supir   : " << hasilID << endl;

    return hasilID;
}

// generator ID untuk order supir.
string generatorIDOrder(string platNomor, string idSupir, string tujuan, string namaPelanggan) {
    // mendapatkan nilai dari karakter pertama platNomor!
    int digitPlatNomor = (tolower(platNomor[0]) - 'a' + 1); // untuk digit 1 dan 2
    // kalau nilai karakternya <10, tambahin nol. Misal A = 1, jadinya 01.
    string digitPlatNomorStr = (digitPlatNomor < 10) ? "0" + to_string(digitPlatNomor) : to_string(digitPlatNomor); // untuk digit ke 3 4 5 6 7
    // mendapatkan ID supir. klasik...
    string digitIDSupirStr = (idSupir.length() < 5) ? string(5 - idSupir.length(), '0') + idSupir : idSupir;

    int digitTujuan = 0; // digit 8 9
    if (tujuan.length() >= 2) {
        char lastChar1 = tolower(tujuan[tujuan.length() - 2]);
        char lastChar2 = tolower(tujuan[tujuan.length() - 1]);
        digitTujuan = (lastChar1 - 'a' + 1) + (lastChar2 - 'a' + 1);
    } else {
        // ini gak usah dicopas juga ya!
        cerr << "Error: MINIMAL HARUS ADA DUA HURUF PADA DESTINASI TUJUAN!" << endl;
        exit(EXIT_FAILURE);
    }
// arezyh.s
    int jumlahHurufNama = 0; // digit 10
    for (char huruf : namaPelanggan) {
        if (isalpha(huruf)) {
            jumlahHurufNama += tolower(huruf) - 'a' + 1;
        }
    }
    int digitTerakhir = jumlahHurufNama % 10;

    // gabungin semuanya menjadi 10 digit ID order.
    return digitPlatNomorStr +
           digitIDSupirStr +
           to_string(digitTujuan) +
           to_string(digitTerakhir);
}


// TEST DATA SUPIR DAN PELANGGAN DI SINI!!!!!!! UBAH DATANYA SENDIRI!!!!
int main() {
    unordered_set<string> duplikasiID;  // Untuk melacak ID yang telah dibuat

    // UBAH DATA SUPIR DI BAWAH!!!
    string namaSupir = "Akbar SetiyawA"; // ubah nama supir di sini
    char genderSupir = 'L'; // ubah gender supir 'L' atau 'P' di sini
    string tanggalLahirSupir = "27-10-2002"; // ubah tanggalLahirSupir dengan formad DD-MM-YYYY di sini.
    string userID = generatorIDSupir(namaSupir, genderSupir, tanggalLahirSupir, duplikasiID);

    // UBAH DATA PELANGGAN DI BAWAH
    string platNomor = "AE"; // ubah plat nomor di sini, bebas! kan cuma diambil huruf pertama -_-
    string idSupir = userID; // ambil dari userID langsung
    string tujuan = "Ketintang"; // ubah tujuan di sini
    string namaPelanggan = "Komeng"; // ubah nama pelanggan di sini
    // arezyh.s
    string orderID = generatorIDOrder(platNomor, idSupir, tujuan, namaPelanggan);
    cout << "ID Order   : " << orderID << endl;

    return 0;
}

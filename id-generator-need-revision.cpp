#include <iostream>
#include <iomanip>
#include <string>
#include <unordered_set>
#include <cstdlib>
#include <ctime>

using namespace std;

// arezyh.s

// global.
unordered_set<int> usedIds;

// fungsi untuk menghasilkan ID.
int buatIDBaru(const string& nama, char kelamin, const string& tgl_lahir) {
    // menghitung 2 digit pertama
    int digitDuaPertama = abs((tolower(nama[0]) - 'a' + 1) - (tolower(nama[nama.length() - 1]) - 'a' + 1));

    // Menghitung digit ke 3
    int digitKetiga = (kelamin == 'L') ? 1 : 0;

    // Menghitung digit ke 4
    int digitKeempat = ((tgl_lahir[1] - '0') + (tgl_lahir[4] - '0') + (tgl_lahir[9] - '0')) % 9;

    // Menggabungkan digit-digit menjadi ID
    int hasilID = digitDuaPertama * 1000 + digitKetiga * 100 + digitKeempat * 10;

    // Menangani digit ke 5 untuk mengatasi duplikasi
    // static unordered_set<int> usedIds;
    int digitKelima = 0;

    while (usedIds.count(hasilID + digitKelima)) {
        digitKelima++;

        if (digitKelima > 9) {
            digitKelima = 0;
            digitKeempat = (digitKeempat + 1) % 9;
            hasilID = digitDuaPertama * 1000 + digitKetiga * 100 + digitKeempat * 10;
        }
    }

    hasilID += digitKelima;
    usedIds.insert(hasilID);

    return hasilID;
}

// fungsi menampilkan daftar ID saja.
void tampilkanDaftarID() {
    cout << "Daftar ID yang telah dibuat:" << endl;
    for (int id : usedIds) {
        cout << setw(5) << setfill('0') << id << endl;
    }
    cout << endl;
    system("pause");
}

// fungsi membuat data dummies
void buatDataDummies() {
    srand(time(0));

    for (int i = 0; i < 100; ++i) {
        string nama = "Sugeng Pangestu";
        char kelamin = (rand() % 2 == 0) ? 'L' : 'P';
        string tgl_lahir = "21-02-1999";

        cout << nama << endl;

        buatIDBaru(nama, kelamin, tgl_lahir);
    }
}

int main() {
    buatDataDummies();

    int pilihan;
    do {
        cout << "---------------------------" << endl;
        cout << "       ID GENERATOR        " << endl;
        cout << "---------------------------" << endl;
        cout << "1. Buat ID untuk user baru " << endl;
        cout << "2. Lihat daftar ID         " << endl;
        cout << "3. Keluar program          " << endl;
        cout << ">> ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                string nama;
                char kelamin;
                string tgl_lahir;

                cout << "Nama         : ";
                cin.ignore();
                getline(cin, nama);

                cout << "Gender (L/P) : ";
                cin >> kelamin;

                cout << "Tanggal Lahir (DD-MM-YYYY) : ";
                cin >> tgl_lahir;

                int hasilID = buatIDBaru(nama, kelamin, tgl_lahir);
                cout << ">> ID yang dihasilkan: " << setw(5) << setfill('0') << hasilID << endl;
                system("pause"); system("cls");
                break;
            }
            case 2:
                tampilkanDaftarID();
                break;
            case 3:
                cout << "Berhasil keluar!" << endl;
                break;
            default:
                cout << "Pilih opsi yang benar!" << endl;
        }
    } while (pilihan != 3);

    return 0;
}

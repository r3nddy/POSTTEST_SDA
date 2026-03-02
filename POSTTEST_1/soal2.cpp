#include <iostream> // io
#include <string> // opsional buat tipe data string
#include <limits> // buat bersihin buffer keseluruhan

using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {

    const int Jumlah_MHS = 5;

    Mahasiswa daftarMahasiswa[Jumlah_MHS];

    cout << "--- Input Data 5 Mahasiswa ---" << endl;

    for (int i = 0; i < Jumlah_MHS; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Nama : ";
        getline(cin, daftarMahasiswa[i].nama);
        cout << "NIM : ";
        cin >> daftarMahasiswa[i].nim;
        cout << "IPK : ";
        cin >> daftarMahasiswa[i].ipk;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int idxTertinggi = 0;
    for (int i = 1; i < Jumlah_MHS; i++) {
        if (daftarMahasiswa[i].ipk > daftarMahasiswa[idxTertinggi].ipk) {
            idxTertinggi = i;
        }
    }

    cout << "\n----------------------------------" << endl;
    cout << "Data Mahasiswa Dengan IPK Tertinggi:" << endl;
    cout << "Nama : " << daftarMahasiswa[idxTertinggi].nama << endl;
    cout << "NIM : " << daftarMahasiswa[idxTertinggi].nim << endl;
    cout << "IPK : " << daftarMahasiswa[idxTertinggi].ipk << endl;
    cout << "-----------------------------------" << endl;

    return 0;
}
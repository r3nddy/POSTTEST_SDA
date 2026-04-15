#include <iostream>
#include <string>
#include <iomanip>

#ifdef _WIN32
    #define CLEAR system("cls") // bersihkan terminal (windows)
    #include <windows.h> // untuk ascii art dan warna (windows)
#else
    #define CLEAR system("clear") // bersihkan terminal (linux, macOs)
#endif

using namespace std;

struct Hewan {
    int id;
    string nama;
    string jenis;
    string kondisi;
    double harga;
};

struct RiwayatTindakan {
    int idHewan;
    string namaHewan;
    string jenisHewan;
    string tindakan;
    string waktu;
};

struct AntrianNode {
    int id;
    string nama;
    string jenis;
    string kondisi;
    double harga;
    AntrianNode* next; 
};

struct RiwayatNode {
    int idHewan;
    string namaHewan;
    string jenisHewan;
    string tindakan;
    string waktu;
    RiwayatNode* next;
};

const int MAX = 100;
Hewan daftarHewan[MAX];
int jumlahHewan = 0;

AntrianNode* queueFront = nullptr;
AntrianNode* queueRear = nullptr;
int jumlahAntrian = 0;

RiwayatNode* stackTop = nullptr;
int jumlahRiwayat = 0;


void tekanEnter() {
    cout << "\n" << "    Tekan Enter untuk melanjutkan...";
    cin.ignore(1000, '\n');
}

int generateIdRekursif(int n = 1) {
    for (int i = 0; i < jumlahHewan; i++) {
        if (daftarHewan[i].id == n) {
            return generateIdRekursif(n + 1);
        }
    }
    return n;
}

int inputMenu(int minOpsi, int maxOpsi) {
    int opsi = 0;
    while (true) {
        cout << "\nPilih Menu: ";
        if (cin >> opsi) {
            cin.ignore(1000, '\n');
            if (opsi >= minOpsi && opsi <= maxOpsi) {
                return opsi;
            }
            cout << "[!] " << "Pilihan harus " << minOpsi << " - " << maxOpsi << "." << endl;
        } else {
            cout << "[!] " << "Input tidak valid." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
}

int inputInt(const string& prompt) {
    int nilai;
    while (true) {
        cout << prompt;
        if (cin >> nilai && nilai >= 0) {
            cin.ignore(1000, '\n');
            return nilai;
        }
        cout << "[!] Input tidak valid, masukkan angka bulat positif." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

double inputDouble(const string& prompt) {
    double nilai;
    while (true) {
        cout << prompt;
        if (cin >> nilai && nilai >= 0) {
            cin.ignore(1000, '\n');
            return nilai;
        }
        cout << "[!] " << "Input tidak valid, masukkan angka positif." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
}


void header() {
    cout << "  █▀█ █▀█ █   █ ▄▀▀ █▀█ █▀█ ██▀" << endl;
    cout << "  █▀▀ █▀█ ▀▄▀▄▀ ▀▄▄ █▀█ █▀▄ █▄▄" << endl;
    cout << "  ─────────────────────────────────────────────" << endl;
    cout << "  █▀█ ██▀ ▀█▀ ▄▀▀ █▄█ █▀█ █▀█" << endl;
    cout << "  █▀▀ █▄▄  █  ▄▄▀ █ █ █▄█ █▀▀" << endl;
    cout << "  ─────────────────────────────────────────────" << endl;
}

void menuUtama() {
    cout << "\n+====================================================+" << endl;
    cout << "|           MENU UTAMA PAWCARE PETSHOP               |" << endl;
    cout << "+====================================================+" << endl;
    cout << "| No | Fitur                                         |" << endl;
    cout << "|----|-----------------------------------------------|" << endl;
    cout << "|  1 | Tampilkan Semua Data Hewan (via Pointer)      |" << endl;
    cout << "|  2 | Tambah Data Hewan Baru                        |" << endl;
    cout << "|  3 | Update Data Hewan                             |" << endl;
    cout << "|  4 | Hapus Data Hewan                              |" << endl;
    cout << "|----|-----------------------------------------------|" << endl;
    cout << "|  5 | Linear Search - Cari Berdasarkan Nama         |" << endl;
    cout << "|  6 | Fibonacci Search - Cari Berdasarkan ID        |" << endl;
    cout << "|----|-----------------------------------------------|" << endl;
    cout << "|  7 | Bubble Sort - Urutkan Nama (A-Z)              |" << endl;
    cout << "|  8 | Selection Sort - Urutkan Harga (Termurah)     |" << endl;
    cout << "|----|-----------------------------------------------|" << endl;
    cout << "|  9 | Enqueue - Daftarkan Hewan ke Antrian          |" << endl;
    cout << "| 10 | Dequeue - Panggil Pasien Terdepan             |" << endl;
    cout << "| 11 | Push - Catat Tindakan ke Riwayat              |" << endl;
    cout << "| 12 | Pop - Batalkan Tindakan Terakhir              |" << endl;
    cout << "| 13 | Peek - Lihat Antrian & Riwayat Teratas        |" << endl;
    cout << "| 14 | Tampilkan Semua Antrian                       |" << endl;
    cout << "| 15 | Tampilkan Semua Riwayat                       |" << endl;
    cout << "|----|-----------------------------------------------|" << endl;
    cout << "| 16 | Keluar Program                                |" << endl;
    cout << "+====================================================+" << endl;
}
 
void tampilSemuaHewan(Hewan* arr, int n) {
    CLEAR;
    const int WIDE = 94;

    cout << "=========================================================" << endl;
    cout << "|             DAFTAR SEMUA HEWAN PELIHARAAN             |" << endl;
    cout << "=========================================================" << endl;

    if (n == 0) {
        cout << "\n   [!] " << "Belum ada data hewan." << endl;
        tekanEnter();
        return;
    }

    cout << left;
    cout << string(WIDE, '=') << endl;
    cout << "| " << setw(5)  << "ID"
         << "| " << setw(21) << "Nama Hewan"
         << "| " << setw(10) << "Jenis"
         << "| " << setw(17) << "Kondisi"
         << "| " << setw(30) << "Harga (Rp)"
         << "|" << endl;
    cout << string(WIDE, '-') << endl;

    for (int i = 0; i < n; i++) {
        cout << "| " << setw(5)  << (arr + i)->id
            << "| " << setw(21) << (arr + i)->nama
            << "| " << setw(10) << (arr + i)->jenis
            << "| " << setw(17) << (arr + i)->kondisi
            << "| " << setw(30) << fixed << setprecision(0) << (arr + i)->harga
            << "|" << endl;
    }

    cout << string(WIDE, '=') << endl;
    tekanEnter();
}

void tambahHewan() {
    CLEAR;
    cout << "============================================================" << endl;
    cout << "--- [ TAMBAH DATA HEWAN BARU ] ---" << endl;
    cout << "============================================================" << endl;

    if (jumlahHewan >= MAX) {
        cout << "\n   [!] " << "Kapasitas data hewan penuh!" << endl;
        tekanEnter();
        return;
    }

    Hewan hewanBaru;

    hewanBaru.id = generateIdRekursif();
    cout << "\n   ID Hewan    : " << hewanBaru.id << " (otomatis)" << endl;

    cout << "   Nama Hewan  : ";
    getline(cin, hewanBaru.nama);

    cout << "\n   Jenis Hewan :" << endl;
    cout << "   " << "[1]" << " Kucing   " << "[2]" << " Anjing   "
        << "[3]" << " Kelinci" << endl;
    cout << "   " << "[4]" << " Burung   "
        << "[5]" << " Hamster  "
        << "[6]" << " Lainnya" << endl;

    // jenis
    int pilihanJenis = inputMenu(1, 6);
    switch (pilihanJenis) {
        case 1: hewanBaru.jenis = "Kucing"; break;
        case 2: hewanBaru.jenis = "Anjing"; break;
        case 3: hewanBaru.jenis = "Kelinci"; break;
        case 4: hewanBaru.jenis = "Burung"; break;
        case 5: hewanBaru.jenis = "Hamster"; break;
        case 6: cout << "   Jenis lainnya: ";
                getline(cin, hewanBaru.jenis);
                break;
        default: 
            cout << "Input Tidak Valid" << endl; break;
    }

    // kondisi
    cout << "\n   Kondisi Hewan:" << endl;
    cout << "   " << "[1] Sehat         "
         << "[2] Sakit         "
         << "[3] Dalam Perawatan" << endl;

    int pilihanKondisi = inputMenu(1, 3);
    switch(pilihanKondisi) {
        case 1: hewanBaru.kondisi = "Sehat"; break;
        case 2: hewanBaru.kondisi = "Sakit"; break;
        case 3: hewanBaru.kondisi = "Dalam Perawatan"; break;
        default: 
            cout << "Input Tidak Valid" << endl; break;
    }

    // harga
    hewanBaru.harga = inputDouble("   Harga (Rp)   : ");

    daftarHewan[jumlahHewan] = hewanBaru;
    jumlahHewan++;

    cout << "\n   [OK] " << "Data hewan " << hewanBaru.nama << " berhasil ditambahkan!" << endl;
    tekanEnter();
}

void updateHewan() {
    CLEAR;
    cout << "\n=========================================================" << endl;
    cout << "|                   UPDATE DATA HEWAN                   |" << endl;
    cout << "=========================================================" << endl;

    if (jumlahHewan == 0) {
        cout << "\n   [!] " << "Belum ada data hewan untuk diubah." << endl;
        tekanEnter();
        return;
    }

    // tampilan ringkas daftar hewan menggunakan pointer
    cout << "\n   Daftar Hewan:\n" << endl;
    for (int i = 0; i < jumlahHewan; i++) {
        Hewan* ptr = &daftarHewan[i];
        cout << "   " << "[" << i + 1 << "] "<< ptr->nama
             << " (ID: " << ptr->id << ", " << ptr->jenis << ")" << endl;
    }

    int nomor = inputInt("\n   Masukkan nomor data yang akan diubah: ");
    
    if (nomor < 1 || nomor > jumlahHewan) {
        cout << "\n   [!] " << "Nomor tidak valid." << endl;
        tekanEnter();
        return;
    }

    Hewan* ptr = &daftarHewan[nomor - 1];

    cout << "\n   (Kosongkan/Enter untuk tetap menggunakan nilai lama)\n" << endl;

    string input;

    // nama
    cout << "   Nama baru [" << ptr->nama << "]: ";
    getline(cin, input);
    if (!input.empty()) {
        ptr->nama = input;
    } 

    // kondisi
    cout << "\n   Kondisi baru:" << endl;
    cout << "   " << "[1]" << " Sehat  "
         << "[2]" << " Sakit  "
         << "[3]" << " Dalam Perawatan  "
         << "[4]" << " Tetap (" << ptr->kondisi << ")" << endl;

    int pilihanKondisi = inputMenu(1, 4);
    switch (pilihanKondisi) {
        case 1: ptr->kondisi = "Sehat";             break;
        case 2: ptr->kondisi = "Sakit";             break;
        case 3: ptr->kondisi = "Dalam Perawatan";   break;
        case 4: /* tetap */                          break;
        default:
            cout << "Input Tidak Valid" << endl; break;
    }

    // harga
    double hargaBaru = inputDouble("   Harga baru (0=skip): ");
    if (hargaBaru > 0) ptr->harga = hargaBaru;

    cout << "\n   [OK] " << "Data hewan berhasil diperbarui!" << endl;
    tekanEnter();

}

// delete
void hapusHewan() {
    CLEAR;
    cout << "=========================================================" << endl;
    cout << "|                   HAPUS DATA HEWAN                    |" << endl;
    cout << "=========================================================" << endl;

    if (jumlahHewan == 0) {
        cout << "\n   [!] " << "Belum ada data hewan untuk dihapus." << endl;
        tekanEnter();
        return;
    }

    // Tampil daftar menggunakan pointer
    cout << "\n   Daftar Hewan:\n" << endl;
    for (int i = 0; i < jumlahHewan; i++) {
        Hewan* ptr = &daftarHewan[i];
        cout << "   " << "[" << i + 1 << "] "
             << ptr->nama
             << " (ID: " << ptr->id << ", " << ptr->jenis << ")" << endl;
    }

    int idx = inputInt("\n   Masukkan nomor hewan yang akan dihapus: ");

    if (idx < 1 || idx > jumlahHewan) {
        cout << "\n   [!] " << "Nomor tidak valid." << endl;
        tekanEnter();
        return;
    }

    string namaHapus = (daftarHewan + (idx - 1))->nama;
    for (int i = idx - 1; i < jumlahHewan - 1; i++) {
        Hewan* ptrCurr = daftarHewan + i;
        Hewan* ptrNext = daftarHewan + i + 1;
        *ptrCurr = *ptrNext; // pergeseran via dereferensi pointer
    }
    jumlahHewan--;

    cout << "\n   [OK] " << "Data hewan " << namaHapus << " berhasil dihapus!" << endl;
    tekanEnter();
}

void cariHewan(Hewan* &hasil, Hewan* arr, int n, string keyword) {
    hasil = nullptr;
    for (int i = 0; i < n; i++) {
        if ((arr + i)->nama == keyword) {
            hasil = arr + i;
            return;
        }
    }
}

void linearSearchNama() {
    CLEAR;
    cout << "\n+========================================================+" << endl;
    cout << "|        LINEAR SEARCH - CARI BERDASARKAN NAMA           |" << endl;
    cout << "+========================================================+" << endl;

    if (jumlahHewan == 0) {
        cout << "\n   [!] Belum ada data hewan." << endl;
        tekanEnter();
        return;
    }

    cout << "\n   Masukkan nama hewan yang dicari: ";
    string keyword;
    getline(cin, keyword);

    Hewan* result = nullptr;
    cariHewan(result, daftarHewan, jumlahHewan, keyword);

    cout << "\n   Proses Linear Search..." << endl;
    cout << "   Membandingkan satu per satu dari index 0...\n" << endl;

    int langkah = 0;

    for (int i = 0; i < jumlahHewan; i++) {
        
        Hewan* ptr = daftarHewan + i;
        langkah++;

        cout << "   Step " << setw(2) << langkah
             << " | Index [" << i << "] "
             << "-> Cek: " << ptr->nama;

        if (ptr->nama == keyword) {
            cout << "  --> COCOK!" << endl;

            if (i > 0) {
                Hewan* ptrDepan = daftarHewan + 0;
                cout << "\n   [SWAP via pointer] "
                     << ptr->nama << " <-> " << ptrDepan->nama
                     << " (dipindahkan ke index 0)" << endl;

                Hewan temp = *ptr;
                *ptr = *ptrDepan;
                *ptrDepan = temp;
            }

            Hewan* hasil = daftarHewan + 0;
            cout << endl;
            cout << "   +======================================================+" << endl;
            cout << "   |  HASIL DITEMUKAN                                     |" << endl;
            cout << "   +======================================================+" << endl;
            cout << "   |  ID      : " << left << setw(42) << hasil->id      << "|" << endl;
            cout << "   |  Nama    : " << left << setw(42) << hasil->nama    << "|" << endl;
            cout << "   |  Jenis   : " << left << setw(42) << hasil->jenis   << "|" << endl;
            cout << "   |  Harga   : Rp " << left << setw(39) << fixed << setprecision(0) << hasil->harga << "|" << endl;
            cout << "   |  Kondisi : " << left << setw(42) << hasil->kondisi << "|" << endl;
            cout << "   +======================================================+" << endl;
            cout << "\n   Total langkah pencarian: " << langkah << endl;
            break;
        } else {
            cout << "  --> tidak cocok" << endl;
        }
    }

    if (result == nullptr) {
        cout << "\n   [!] Hewan dengan nama '" << keyword << "' tidak ditemukan." << endl;
        cout << "   Total langkah pencarian: " << langkah << endl;
    }

    tekanEnter();
}

void fibonacciSearchId() {
    CLEAR;
    cout << "\n   +========================================================+" << endl;
    cout << "   |      FIBONACCI SEARCH - CARI BERDASARKAN ID            |" << endl;
    cout << "   +========================================================+" << endl;
 
    if (jumlahHewan == 0) {
        cout << "\n   [!] Belum ada data hewan." << endl;
        tekanEnter();
        return;
    }
 
    Hewan temp[MAX];
    for (int i = 0; i < jumlahHewan; i++) temp[i] = daftarHewan[i];
 
    for (int i = 1; i < jumlahHewan; i++) {
        Hewan key = *(temp + i);
        int j = i - 1;
        while (j >= 0 && (temp + j)->id > key.id) {
            Hewan* ptrDst = temp + j + 1;
            Hewan* ptrSrc = temp + j;
            *ptrDst = *ptrSrc; // pergeseran via dereferensi pointer
            j--;
        }
        *(temp + j + 1) = key;
    }
 
    int n = jumlahHewan;
    int targetID = inputInt("   Masukkan ID hewan yang dicari: ");
 
    cout << "\n   Proses Fibonacci Search pada " << n << " data terurut..." << endl;
    cout << "   Membangun bilangan Fibonacci >= n...\n" << endl;
 
    int fibM2 = 0;
    int fibM1 = 1;
    int fibM  = fibM2 + fibM1;
 
    while (fibM < n) {
        fibM2 = fibM1;
        fibM1 = fibM;
        fibM  = fibM2 + fibM1;
    }
 
    cout << "   Fibonacci: F(m)=" << fibM
         << ", F(m-1)=" << fibM1 << ", F(m-2)=" << fibM2 << "\n" << endl;
 
    int offset = -1;
    int langkah = 0;
    bool ditemukan = false;
    int idxHasil = -1;
 
    while (fibM > 1) {
        int i = min(offset + fibM2, n - 1);
        langkah++;
 
        Hewan* ptr = temp + i;
 
        cout << "   Step " << setw(2) << langkah
             << " | Index [" << i << "] "
             << "-> ID: " << ptr->id;
 
        if (ptr->id < targetID) {
            cout << "  --> < target, geser kanan" << endl;
            fibM  = fibM1;
            fibM1 = fibM2;
            fibM2 = fibM - fibM1;
            offset = i;
        } else if (ptr->id > targetID) {
            cout << "  --> > target, geser kiri" << endl;
            fibM  = fibM2;
            fibM1 = fibM1 - fibM2;
            fibM2 = fibM - fibM1;
        } else {
            cout << "  --> COCOK!" << endl;
            idxHasil = i;
            ditemukan = true;
            break;
        }
    }
 
    if (!ditemukan && fibM1 && offset + 1 < n) {
        langkah++;
        Hewan* ptr = temp + offset + 1;
        cout << "   Step " << setw(2) << langkah
             << " | Index [" << offset + 1 << "] "
             << "-> ID: " << ptr->id;
        if (ptr->id == targetID) {
            cout << "  --> COCOK!" << endl;
            idxHasil = offset + 1;
            ditemukan = true;
        } else {
            cout << "  --> tidak cocok" << endl;
        }
    }
 
    if (ditemukan) {
        Hewan* hasil = temp + idxHasil;
 
        if (idxHasil > 0) {
            Hewan* ptrDepan = temp + 0;
            cout << "\n   [SWAP via pointer] "
                 << hasil->nama << " <-> " << ptrDepan->nama
                 << " (dipindahkan ke index 0)" << endl;

            Hewan tempSwap = *hasil;
            *hasil = *ptrDepan;
            *ptrDepan = tempSwap;
            hasil = temp + 0;
        }
 
        cout << endl;
        cout << "   +======================================================+" << endl;
        cout << "   |  HASIL DITEMUKAN                                     |" << endl;
        cout << "   +======================================================+" << endl;
        cout << "   |  ID      : " << left << setw(42) << hasil->id      << "|" << endl;
        cout << "   |  Nama    : " << left << setw(42) << hasil->nama    << "|" << endl;
        cout << "   |  Jenis   : " << left << setw(42) << hasil->jenis   << "|" << endl;
        cout << "   |  Harga   : Rp " << left << setw(39) << fixed << setprecision(0) << hasil->harga << "|" << endl;
        cout << "   |  Kondisi : " << left << setw(42) << hasil->kondisi << "|" << endl;
        cout << "   +======================================================+" << endl;
        cout << "\n   Total langkah pencarian: " << langkah << endl;
    } else {
        cout << "\n   [!] Hewan dengan ID " << targetID << " tidak ditemukan." << endl;
        cout << "   Total langkah pencarian: " << langkah << endl;
    }
 
    tekanEnter();
}

// ===================== SORTING =====================

void bubbleSortNama() {
   CLEAR;
    cout << "\n   +========================================================+" << endl;
    cout << "   |       BUBBLE SORT - URUTKAN NAMA (A -> Z)             |" << endl;
    cout << "   +========================================================+" << endl;

    if (jumlahHewan == 0) {
        cout << "\n   [!] Belum ada data hewan." << endl;
        tekanEnter();
        return;
    }

    cout << "\n   Proses Bubble Sort...\n" << endl;

    int totalSwap = 0;

    for (int i = 0; i < jumlahHewan - 1; i++) {
        bool adaSwap = false;
        cout << "   Pass " << i + 1 << ":" << endl;

        for (int j = 0; j < jumlahHewan - 1 - i; j++) {
            Hewan* ptrA = daftarHewan + j;
            Hewan* ptrB = daftarHewan + j + 1;

            if (ptrA->nama > ptrB->nama) {
                cout << "   " << ptrA->nama << " > " << ptrB->nama << " -> SWAP (Harga: Rp " << fixed << setprecision(0) << ptrA->harga << " <-> Rp " << ptrB->harga << ")" << endl;
                Hewan temp = *ptrA;
                *ptrA = *ptrB;
                *ptrB = temp;
                adaSwap = true;
                totalSwap++;
            }
        }

        if (!adaSwap) {
            cout << "   Tidak ada swap di pass " << i + 1 << ", array sudah terurut." << endl;
            break;
        }
    }

    cout << "\n   [OK] Data berhasil diurutkan berdasarkan nama (A-Z)!" << endl;
    cout << "   Total swap: " << totalSwap << endl;

    cout << "\n   Hasil setelah Bubble Sort:" << endl;
    cout << left;
    cout << "   +------+---------------------+----------+-----------------+---------------------+" << endl;
    cout << "   | " << setw(5)  << "ID"
         << "| " << setw(20) << "Nama Hewan"
         << "| " << setw(9)  << "Jenis"
         << "| " << setw(16) << "Kondisi"
         << "| " << setw(20) << "Harga (Rp)"
         << "|" << endl;
    cout << "   +------+---------------------+----------+-----------------+---------------------+" << endl;
    for (int i = 0; i < jumlahHewan; i++) {
        Hewan* ptr = daftarHewan + i;
        cout << left;
        cout << "   | " << setw(5)  << ptr->id
             << "| " << setw(20) << ptr->nama
             << "| " << setw(9)  << ptr->jenis
             << "| " << setw(16) << ptr->kondisi
             << "| " << setw(20) << fixed << setprecision(0) << ptr->harga
             << "|" << endl;
    }
    cout << "   +------+---------------------+----------+-----------------+---------------------+" << endl;

    tekanEnter();
}

void selectionSortHarga() {
    CLEAR;
    cout << "\n   +========================================================+" << endl;
    cout << "   |     SELECTION SORT - URUTKAN HARGA (TERMURAH)        |" << endl;
    cout << "   +========================================================+" << endl;

    if (jumlahHewan == 0) {
        cout << "\n   [!] Belum ada data hewan." << endl;
        tekanEnter();
        return;
    }

    cout << "\n   Proses Selection Sort...\n" << endl;

    int totalSwap = 0;

    for (int i = 0; i < jumlahHewan - 1; i++) {
        int idxMin = i;
        Hewan* ptrMin = daftarHewan + i;

        for (int j = i + 1; j < jumlahHewan; j++) {
            Hewan* ptrJ = daftarHewan + j;
            if (ptrJ->harga < ptrMin->harga) {
                idxMin = j;
                ptrMin = ptrJ;
            }
        }

        if (idxMin != i) {
            Hewan* ptrI = daftarHewan + i;
            cout << "   Pass " << i + 1 << ": Min=" << ptrMin->nama
                 << "(Rp " << fixed << setprecision(0) << ptrMin->harga << ")"
                 << " <-> " << ptrI->nama
                 << "(Rp " << fixed << setprecision(0) << ptrI->harga << ") -> SWAP" << endl;
            Hewan temp = *ptrI;
            *ptrI = *ptrMin;
            *ptrMin = temp;
            totalSwap++;
        } else {
            cout << "   Pass " << i + 1 << ": sudah di posisi yang benar." << endl;
        }
    }

    cout << "\n   [OK] Data berhasil diurutkan berdasarkan harga (termurah ke termahal)!" << endl;
    cout << "   Total swap: " << totalSwap << endl;

    cout << "\n   Hasil setelah Selection Sort:" << endl;
    cout << left;
    cout << "   +------+---------------------+----------+-----------------+---------------------+" << endl;
    cout << "   | " << setw(5)  << "ID"
         << "| " << setw(20) << "Nama Hewan"
         << "| " << setw(9)  << "Jenis"
         << "| " << setw(16) << "Kondisi"
         << "| " << setw(20) << "Harga (Rp)"
         << "|" << endl;
    cout << "   +------+---------------------+----------+-----------------+---------------------+" << endl;
    for (int i = 0; i < jumlahHewan; i++) {
        Hewan* ptr = daftarHewan + i;
        cout << left;
        cout << "   | " << setw(5)  << ptr->id
             << "| " << setw(20) << ptr->nama
             << "| " << setw(9)  << ptr->jenis
             << "| " << setw(16) << ptr->kondisi
             << "| " << setw(20) << fixed << setprecision(0) << ptr->harga
             << "|" << endl;
    }
    cout << "   +------+---------------------+----------+-----------------+---------------------+" << endl;

    tekanEnter();
}


bool isQueueEmpty() {
    return queueFront == nullptr;
}

void enqueueAntrian() {
    CLEAR;
    cout << "\n   +========================================================+" << endl;
    cout << "   |     ENQUEUE - DAFTARKAN HEWAN KE ANTRIAN               |" << endl;
    cout << "   +========================================================+" << endl;

    if (jumlahHewan == 0) {
        cout << "\n   [!] Belum ada data hewan terdaftar. Tambahkan hewan terlebih dahulu." << endl;
        tekanEnter();
        return;
    }

    // Tampilkan daftar hewan yang bisa didaftarkan
    cout << "\n   Daftar Hewan Terdaftar:\n" << endl;
    for (int i = 0; i < jumlahHewan; i++) {
        Hewan* ptr = daftarHewan + i;
        cout << "   [" << i + 1 << "] " << ptr->nama
             << " (ID: " << ptr->id << ", " << ptr->jenis << ")" << endl;
    }

    int nomor = inputInt("\n   Pilih nomor hewan untuk didaftarkan ke antrian: ");

    if (nomor < 1 || nomor > jumlahHewan) {
        cout << "\n   [!] Nomor tidak valid." << endl;
        tekanEnter();
        return;
    }

    Hewan* sumber = &daftarHewan[nomor - 1];

    // Cek duplikat di antrian (traversal linked list)
    AntrianNode* cek = queueFront;
    while (cek != nullptr) {
        if (cek->id == sumber->id) {
            cout << "\n   [!] Hewan " << sumber->nama << " sudah ada di antrian!" << endl;
            tekanEnter();
            return;
        }
        cek = cek->next;
    }

    // Buat node baru
    AntrianNode* nodeBaru = new AntrianNode;
    nodeBaru->id = sumber->id;
    nodeBaru->nama = sumber->nama;
    nodeBaru->jenis = sumber->jenis;
    nodeBaru->kondisi = sumber->kondisi;
    nodeBaru->harga = sumber->harga;
    nodeBaru->next = nullptr;

    if (isQueueEmpty()) {
        queueFront = nodeBaru;   // jika kosong, front = rear = node baru
        queueRear = nodeBaru;
    } else {
        queueRear->next = nodeBaru;  
        queueRear = nodeBaru;       
    }
    jumlahAntrian++;

    cout << "\n   [OK] Hewan " << sumber->nama << " (ID: " << sumber->id
         << ") berhasil masuk antrian!" << endl;
    cout << "   Posisi dalam antrian: " << jumlahAntrian << endl;
    cout << "   Jumlah antrian saat ini: " << jumlahAntrian << endl;
    tekanEnter();
}

void dequeueAntrian() {
    CLEAR;
    cout << "\n   +========================================================+" << endl;
    cout << "   |     DEQUEUE - PANGGIL PASIEN TERDEPAN                  |" << endl;
    cout << "   +========================================================+" << endl;

    // Underflow: jika queue kosong
    if (isQueueEmpty()) {
        cout << "\n   [!] Queue underflow! Antrian kosong! Tidak ada pasien untuk dipanggil." << endl;
        tekanEnter();
        return;
    }

    AntrianNode* pasienDipanggil = queueFront;

    // Tampilkan data pasien yang dipanggil
    cout << "\n   ============================================" << endl;
    cout << "   PASIEN DIPANGGIL UNTUK PEMERIKSAAN" << endl;
    cout << "   ============================================" << endl;
    cout << "   ID    : " << pasienDipanggil->id << endl;
    cout << "   Nama  : " << pasienDipanggil->nama << endl;
    cout << "   Jenis : " << pasienDipanggil->jenis << endl;
    cout << "   Kondisi: " << pasienDipanggil->kondisi << endl;
    cout << "   ============================================" << endl;

    queueFront = queueFront->next;  
    if (queueFront == nullptr) {
        queueRear = nullptr;        
    }
    delete pasienDipanggil;        
    jumlahAntrian--;

    cout << "\n   Sisa antrian: " << jumlahAntrian << " pasien" << endl;
    tekanEnter();
}


void tampilSemuaAntrian() {
    CLEAR;
    cout << "\n   +========================================================+" << endl;
    cout << "   |     TAMPIL SEMUA ANTRIAN (SINGLE LINKED LIST)           |" << endl;
    cout << "   +========================================================+" << endl;

    if (isQueueEmpty()) {
        cout << "\n   [!] Antrian kosong." << endl;
        tekanEnter();
        return;
    }

    cout << "\n   Antrian dari FRONT ke REAR (" << jumlahAntrian << " pasien):\n" << endl;

    const int WIDE = 83;
    cout << "   " << string(WIDE, '=') << endl;
    cout << left;
    cout << "   | " << setw(4)  << "No"
         << "| " << setw(6)  << "ID"
         << "| " << setw(20) << "Nama Hewan"
         << "| " << setw(12) << "Jenis"
         << "| " << setw(18) << "Kondisi"
         << "| " << setw(10) << "Status"
         << "|" << endl;
    cout << "   " << string(WIDE, '-') << endl;

    // Traversal linked list dari front ke rear
    AntrianNode* current = queueFront;
    int nomor = 1;
    while (current != nullptr) {
        string status = "";
        if (current == queueFront) status = "[FRONT]";
        if (current == queueRear) {
            if (current == queueFront) status = "[F & R]";
            else status = "[REAR]";
        }

        cout << "   | " << setw(4)  << nomor
             << "| " << setw(6)  << current->id
             << "| " << setw(20) << current->nama
             << "| " << setw(12) << current->jenis
             << "| " << setw(18) << current->kondisi
             << "| " << setw(10) << status
             << "|" << endl;
        current = current->next;  
        nomor++;
    }
    cout << "   " << string(WIDE, '=') << endl;

    tekanEnter();
}


bool isStackEmpty() {
    return stackTop == nullptr;
}

string getWaktuSekarang() {
    static int counter = 1;
    return "Tindakan-" + to_string(counter++);
}

void pushRiwayat(RiwayatNode** top, int* jumlah) {
    CLEAR;
    cout << "\n   +========================================================+" << endl;
    cout << "   |     PUSH - CATAT TINDAKAN KE RIWAYAT                   |" << endl;
    cout << "   +========================================================+" << endl;

    if (jumlahHewan == 0) {
        cout << "\n   [!] Belum ada data hewan terdaftar." << endl;
        tekanEnter();
        return;
    }

    // Tampilkan daftar hewan
    cout << "\n   Daftar Hewan:\n" << endl;
    for (int i = 0; i < jumlahHewan; i++) {
        Hewan* ptr = daftarHewan + i;
        cout << "   [" << i + 1 << "] " << ptr->nama
             << " (ID: " << ptr->id << ", " << ptr->jenis << ")" << endl;
    }

    int nomor = inputInt("\n   Pilih nomor hewan yang diperiksa: ");
    if (nomor < 1 || nomor > jumlahHewan) {
        cout << "\n   [!] Nomor tidak valid." << endl;
        tekanEnter();
        return;
    }

    Hewan* hewanPtr = &daftarHewan[nomor - 1];

    cout << "\n   Pilih tindakan medis:" << endl;
    cout << "   [1] Vaksinasi" << endl;
    cout << "   [2] Pemeriksaan Umum" << endl;
    cout << "   [3] Operasi" << endl;
    cout << "   [4] Rawat Inap" << endl;
    cout << "   [5] Pemberian Obat" << endl;
    cout << "   [6] Grooming" << endl;
    cout << "   [7] Tindakan Lainnya" << endl;

    int pilihanTindakan = inputMenu(1, 7);
    string tindakan;
    switch (pilihanTindakan) {
        case 1: tindakan = "Vaksinasi"; break;
        case 2: tindakan = "Pemeriksaan Umum"; break;
        case 3: tindakan = "Operasi"; break;
        case 4: tindakan = "Rawat Inap"; break;
        case 5: tindakan = "Pemberian Obat"; break;
        case 6: tindakan = "Grooming"; break;
        case 7:
            cout << "   Masukkan tindakan: ";
            getline(cin, tindakan);
            break;
    }

    RiwayatNode* nodeBaru = new RiwayatNode;
    nodeBaru->idHewan = hewanPtr->id;
    nodeBaru->namaHewan = hewanPtr->nama;
    nodeBaru->jenisHewan = hewanPtr->jenis;
    nodeBaru->tindakan = tindakan;
    nodeBaru->waktu = getWaktuSekarang();
    nodeBaru->next = *top;   
    *top = nodeBaru;         
    (*jumlah)++;            

    cout << "\n   [OK] Tindakan berhasil dicatat ke riwayat!" << endl;
    cout << "   ============================================" << endl;
    cout << "   Hewan    : " << nodeBaru->namaHewan << " (ID: " << nodeBaru->idHewan << ")" << endl;
    cout << "   Tindakan : " << nodeBaru->tindakan << endl;
    cout << "   Catatan  : " << nodeBaru->waktu << endl;
    cout << "   Total Riwayat: " << *jumlah << endl;
    cout << "   ============================================" << endl;
    tekanEnter();
}

void popRiwayat() {
    CLEAR;
    cout << "\n   +========================================================+" << endl;
    cout << "   |     POP - BATALKAN TINDAKAN TERAKHIR                   |" << endl;
    cout << "   +========================================================+" << endl;

    // Underflow: jika stack kosong
    if (isStackEmpty()) {
        cout << "\n   [!] UNDERFLOW: Riwayat kosong! Tidak ada tindakan untuk dibatalkan." << endl;
        tekanEnter();
        return;
    }

    // Ambil data tindakan terakhir (top) — simpan ke variabel sementara
    RiwayatNode* nodeDihapus = stackTop;

    cout << "\n   Tindakan yang akan dibatalkan:" << endl;
    cout << "   ============================================" << endl;
    cout << "   Hewan    : " << nodeDihapus->namaHewan << " (ID: " << nodeDihapus->idHewan << ")" << endl;
    cout << "   Tindakan : " << nodeDihapus->tindakan << endl;
    cout << "   Catatan  : " << nodeDihapus->waktu << endl;
    cout << "   ============================================" << endl;

    // Pop: geser top ke node berikutnya, hapus node lama — seperti deleteFirst di SLL
    stackTop = stackTop->next;  
    delete nodeDihapus;         
    jumlahRiwayat--;

    cout << "\n   [OK] Tindakan terakhir berhasil dibatalkan (pop)!" << endl;
    if (!isStackEmpty())
        cout << "   Sisa riwayat: " << jumlahRiwayat << " tindakan" << endl;
    else
        cout << "   Riwayat sekarang kosong." << endl;

    tekanEnter();
}


void peekAntrianDanRiwayat() {
    CLEAR;
    cout << "\n   +========================================================+" << endl;
    cout << "   |     PEEK - LIHAT DEPAN ANTRIAN & ATAS RIWAYAT          |" << endl;
    cout << "   +========================================================+" << endl;

    // Peek Queue (front) — hanya baca, tidak geser
    cout << "\n   --- ANTRIAN (FRONT) ---" << endl;
    if (isQueueEmpty()) {
        cout << "   [!] Queue underflow! Antrian kosong, tidak ada data untuk di-peek." << endl;
    } else {
        AntrianNode* ptrFront = queueFront; 
        cout << "   ID    : " << ptrFront->id << endl;
        cout << "   Nama  : " << ptrFront->nama << endl;
        cout << "   Jenis : " << ptrFront->jenis << endl;
        cout << "   Kondisi: " << ptrFront->kondisi << endl;
    }

    // Peek Stack (top) — hanya baca, tidak geser
    cout << "\n   --- RIWAYAT (TOP) ---" << endl;
    if (isStackEmpty()) {
        cout << "   [!] Stack underflow! Riwayat kosong, tidak ada data untuk di-peek." << endl;
    } else {
        RiwayatNode* ptrTop = stackTop; 
        cout << "   Hewan    : " << ptrTop->namaHewan << " (ID: " << ptrTop->idHewan << ")" << endl;
        cout << "   Tindakan : " << ptrTop->tindakan << endl;
        cout << "   Catatan  : " << ptrTop->waktu << endl;
    }

    cout << "\n   (Data tidak dihapus - hanya ditampilkan)" << endl;
    tekanEnter();
}


void tampilSemuaRiwayat() {
    CLEAR;
    cout << "\n   +========================================================+" << endl;
    cout << "   |     TAMPIL SEMUA RIWAYAT (SINGLE LINKED LIST)           |" << endl;
    cout << "   +========================================================+" << endl;

    if (isStackEmpty()) {
        cout << "\n   [!] Riwayat kosong." << endl;
        tekanEnter();
        return;
    }

    cout << "\n   Riwayat dari TOP ke BOTTOM (" << jumlahRiwayat << " tindakan):\n" << endl;

    const int WIDE = 92;
    cout << "   " << string(WIDE, '=') << endl;
    cout << left;
    cout << "   | " << setw(4)  << "No"
         << "| " << setw(6)  << "ID"
         << "| " << setw(16) << "Nama Hewan"
         << "| " << setw(12) << "Jenis"
         << "| " << setw(20) << "Tindakan"
         << "| " << setw(15) << "Catatan"
         << "| " << setw(4)  << "Pos"
         << "|" << endl;
    cout << "   " << string(WIDE, '-') << endl;

    // Traversal linked list dari top ke bottom
    RiwayatNode* current = stackTop;
    int nomor = 1;
    while (current != nullptr) {
        string posisi = "";
        if (current == stackTop && current->next == nullptr) posisi = "T&B";
        else if (current == stackTop) posisi = "TOP";
        else if (current->next == nullptr) posisi = "BTM";

        cout << "   | " << setw(4)  << nomor
             << "| " << setw(6)  << current->idHewan
             << "| " << setw(16) << current->namaHewan
             << "| " << setw(12) << current->jenisHewan
             << "| " << setw(20) << current->tindakan
             << "| " << setw(15) << current->waktu
             << "| " << setw(4)  << posisi
             << "|" << endl;
        current = current->next;  
        nomor++;
    }
    cout << "   " << string(WIDE, '=') << endl;

    tekanEnter();
}


void dataDummy() {
    daftarHewan[0] = {1, "Garfield", "Kucing", "Sehat", 2500000};
    daftarHewan[1] = {2, "Scooby-Doo", "Anjing", "Sehat",3000000};
    daftarHewan[2] = {3, "Rango", "bunglon", "Sakit", 6000000};
    
    jumlahHewan = 3;
}

int main() {

    #ifdef _WIN32
    SetConsoleOutputCP(65001); 
    #endif

    // init data dummy
    dataDummy();

    while (true) {
        CLEAR;
        header();
        menuUtama();

        int pilihan = inputMenu(1, 16);

        switch (pilihan) {
            case 1: tampilSemuaHewan(daftarHewan, jumlahHewan); break;
            case 2: tambahHewan(); break;
            case 3: updateHewan(); break;
            case 4: hapusHewan(); break;
            case 5: linearSearchNama(); break;
            case 6: fibonacciSearchId(); break;
            case 7: bubbleSortNama(); break;
            case 8: selectionSortHarga(); break;
            case 9: enqueueAntrian(); break;
            case 10: dequeueAntrian(); break;
            case 11: pushRiwayat(&stackTop, &jumlahRiwayat); break;
            case 12: popRiwayat(); break;
            case 13: peekAntrianDanRiwayat(); break;
            case 14: tampilSemuaAntrian(); break;
            case 15: tampilSemuaRiwayat(); break;
            case 16:
                CLEAR;
                cout << "\n   Terima kasih telah menggunakan Pawcare Petshop!" << endl;
                cout << "   Sampai jumpa!\n\n" << endl;
                return 0;
        }
    }
  return 0;
}
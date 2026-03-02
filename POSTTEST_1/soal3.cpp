#include <iostream>

using namespace std;

void tampilkanArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nilai : " << *(arr + i) << " | Alamat : " << (arr + i) << endl;
    }
}

void reverseArray(int* arr, int n) {
    int* awal = arr;
    int* akhir = arr + (n - 1);

    while (awal < akhir) {
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;

        awal++;
        akhir--;
    }
}

int main() {

    const int n = 7;

    int AngkaPrima[n] = {
        2, 3, 5, 7, 11, 13, 17
    };

    cout << "Array Sebelum Dibalik: " << endl;
    tampilkanArray(AngkaPrima, n);


    reverseArray(AngkaPrima, n);


    cout << "\n\n";

    cout << "Array Sesudah Dibalik: " << endl;
    tampilkanArray(AngkaPrima, n);

    return 0;
}
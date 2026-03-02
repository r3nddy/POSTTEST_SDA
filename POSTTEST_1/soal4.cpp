#include <iostream>

using namespace std;


void tukarData(int* nilai_a, int* nilai_b) {
    int temp = *nilai_a;
    *nilai_a = *nilai_b;
    *nilai_b = temp;
}

int main() {
    int nilai_a, nilai_b;

    cout << "Masukkan Nilai A : ";
    cin >> nilai_a;
    cout << "Masukkan Nilai B : ";
    cin >> nilai_b;

    cout << "\nSebelum Pertukaran" << endl;
    cout << "Nilai A : " << nilai_a << " | " << "Nilai B : " << nilai_b << endl;

    tukarData(&nilai_a, &nilai_b);

    cout << "\nSetelah Pertukaran" << endl;
    cout << "Nilai A : " << nilai_a << " | " << "Nilai B : " << nilai_b << endl;

    return 0;
}
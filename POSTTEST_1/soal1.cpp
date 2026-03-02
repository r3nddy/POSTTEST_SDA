#include <iostream>

using namespace std;

void FindMin(int angkaFibonacci[], int jumlah) {
    int min = angkaFibonacci[0];
    int minIdx = 0;

    for (int i = 1; i < jumlah; i++) {
        if (angkaFibonacci[i] < min) {
            min = angkaFibonacci[i];
            minIdx = i;
        }
    }

    cout << "\nHasil Pencarian:" << endl;
    cout << "Nilai minimum    : " << min << endl;
    cout << "Terletak di index: " << minIdx << endl;
}


int main() {

    const int jumlah = 8;

    int angkaFibonacci[] = {
        1, 1, 2, 3, 5, 8, 13, 21
    };

    cout << "Array Fibonacci : ";
    for (int i = 0; i < jumlah; i++) {
        cout << angkaFibonacci[i] << " ";
    }

    cout << endl;

    FindMin(angkaFibonacci, jumlah);

    return 0;
}

/**
 * ANALISIS KOMPLEKSITAS ALGORITMA
 * ==================================================================
 * |       Pseudocode        | Cost |   Tmin   |   Tmax             |
 * ==================================================================
 * | procedure FindMin       |  c1  |    1     |    1               |
 * | min <- A[0]             |  c2  |    1     |    1               |
 * | for i <- 1 to n - 1     |  c3  |    n     |    n               |
 * | if A[i] < min           |  c4  |  (n - 1) |  (n - 1)           |
 * | min <- A[i]             |  c5  |    0     |  (n - 1)           |
 * | end if                  |  c6  |  (n - 1) |  (n - 1)           |
 * | end for                 |  c7  |    n     |    n               |
 * | return min              |  c8  |    1     |    1               |
 * | end procedure           |  c9  |    1     |    1               |
 * ==================================================================
 * 1. Best Case Analysis (Tmin)
 * Terjadi jika elemen pertama A[0] adalah nilai terkecil.
 * Tmin(n) = c1 + c2 + c3(n) + c4(n-1) + c5(0) + c6(n-1) + c7(n) + c8 + c9
 * Notasi Big-O: O(n)
 *
 * 2. Worst Case Analysis (Tmax)
 * Terjadi jika array terurut menurun, memicu update 'min' (c5) terus menerus.
 * Tmax(n) = c1 + c2 + c3(n) + c4(n-1) + c5(n-1) + c6(n-1) + c7(n) + c8 + c9
 * Notasi Big-O: O(n)
 *
 * Kesimpulan:
 * Algoritma FindMin memiliki kompleksitas waktu linear O(n).
 */
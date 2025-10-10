#include <iostream>
#include <vector>
using namespace std;

// =======================
// Fungsi untuk menggabungkan dua subarray terurut (proses merge)
// =======================
void merge(vector<int>& arr, int left, int mid, int right) {
    // Hitung ukuran dua subarray yang akan digabung
    int n1 = mid - left + 1;  // Banyak elemen di sisi kiri
    int n2 = right - mid;     // Banyak elemen di sisi kanan

    // Buat dua array sementara untuk menyimpan data kiri dan kanan
    vector<int> L(n1), R(n2);

    // Salin elemen ke array kiri (L)
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    // Salin elemen ke array kanan (R)
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Inisialisasi indeks awal untuk tiap array
    int i = 0;       // Indeks untuk L
    int j = 0;       // Indeks untuk R
    int k = left;    // Indeks untuk posisi gabungan di arr

    // Proses penggabungan dua array (L dan R) secara terurut
    while (i < n1 && j < n2) {
        // Bandingkan elemen dari L dan R, ambil yang lebih kecil dulu
        if (L[i] <= R[j]) {
            arr[k] = L[i];  // Masukkan elemen dari L ke arr
            i++;            // Geser indeks L ke elemen berikutnya
        } else {
            arr[k] = R[j];  // Masukkan elemen dari R ke arr
            j++;            // Geser indeks R ke elemen berikutnya
        }
        k++; // Geser posisi pada arr
    }

    // Jika masih ada sisa elemen di L, salin semuanya ke arr
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Jika masih ada sisa elemen di R, salin semuanya ke arr
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// =======================
// Fungsi rekursif utama untuk Merge Sort
// =======================
void mergeSort(vector<int>& arr, int left, int right) {
    // Base case: jika hanya ada satu elemen atau tidak ada sama sekali
    if (left >= right)
        return; // Tidak perlu diurutkan

    // Cari titik tengah dari array
    int mid = left + (right - left) / 2;

    // Rekursif: urutkan bagian kiri dan kanan
    mergeSort(arr, left, mid);       // Urutkan sisi kiri
    mergeSort(arr, mid + 1, right);  // Urutkan sisi kanan

    // Gabungkan kedua sisi yang sudah terurut
    merge(arr, left, mid, right);
}

// =======================
// Fungsi untuk mencetak isi array
// =======================
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";  // Cetak elemen diikuti spasi
    }
    cout << endl;
}

// =======================
// Fungsi utama program
// =======================
int main() {
    int n;  // Menyimpan jumlah elemen array
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;  // Input jumlah elemen dari user

    // Buat vector dengan ukuran n
    vector<int> data(n);

    cout << "Masukkan elemen-elemen data: ";
    // Input setiap elemen array
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    // Tampilkan data sebelum diurutkan
    cout << "Array sebelum diurutkan: ";
    printArray(data);

    // Proses pengurutan dengan Merge Sort
    mergeSort(data, 0, n - 1);

    // Tampilkan data setelah diurutkan
    cout << "Array setelah diurutkan: ";
    printArray(data);

    return 0;  // Program selesai
}

/*
Nama: Mutia Elshaday sidabutar
NIM: 241401133
*/

#include <iostream>
#include <vector>

using namespace std;

// Fungsi untuk mencetak papan Sudoku
void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
            if ((j + 1) % 3 == 0) {
                cout << " ";// jarak tiap 3 kolom
            }
        }
        cout << endl;
        if ((i + 1) % 3 == 0) {
            cout << endl;//jarak tiap 3 baris
        }
    }
}

// Fungsi untuk memeriksa apakah sebuah angka valid di posisi tertentu
bool isValid(const vector<vector<int>>& board, int row, int col, int num) {
    // Periksa baris dan kolom
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }

    // Periksa sub-kotak 3x3
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;//valid, kalau ga ada angka yang sama.
}

// Fungsi utama pemecah Sudoku menggunakan rekursif DFS
bool solveSudoku(vector<vector<int>>& board) { 
   
    // Cari sel kosong
     for(int row =0; row<9; row++){
        for(int col=0;col<9; col++){
            // Ketemu sel kosong
            if (board[row][col]==0){
             // Coba masukkan angka dari 1 - 9
             for(int num=1;num<=9; num++){
                // Jika valid (gunakan fungsi isValid):
                  if (isValid(board, row, col, num)) { 
                    // Masukkan angka
                    board[row][col] = num; 
                    // Rekursi
                     if (solveSudoku(board)) return true;
                // Jika gagal:
                   board[row][col] = 0;
                    // kosongkan sel

             }
                
            } return false;// Jika tidak ada angka yg valid, backtrack (return false)->jika semua angka gagal

        }
     }
    }  return true;       // Jika tidak ada lagi sel kosong (solusi telah ditemukan), return true  (semua sel terisi-> selesai)
            
}

int main() {
    //angka papan sudoku (0 artinya sel yang masih kosong)
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    

    cout << "Papan Sudoku awal:" << endl;
    printBoard(board);
// jalankan solver(bagian akhir sudoku)
    if (solveSudoku(board)) {
        cout << "Papan Sudoku terpecahkan:" << endl;
        printBoard(board);
    } else {
        cout << "Tidak ada solusi yang ditemukan." << endl;
    }

    return 0;
}
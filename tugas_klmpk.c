/*
    Tugas Kelompok PMC Kelas 01 EL2008
    Anggota kelompok:
    1. Muhammad Fauzan
    2. Bayu Aji Nugroho
    3. Deovie Lentera
    
*/

// Inisiasi library yang digunakan
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Prosedur untuk mengalikan matriks berdasarkan ukurannya
void kaliMatriks(int size, int mat_A[size][size], int mat_B[size][size]) {
    // Inisiasi variabel
    int hasil[size][size];

    // Pengisian matriks hasil dengan 0 terlebih dahulu
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            hasil[i][j] = 0;
        }        
    }

    // Pengisian matriks hasil dengan hasil perkalian mat_A dan mat_B
    printf("\nHasil kali matrix\n");
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            for (int k = 0; k < size; k++){
                hasil[i][j] += mat_A[i][k] * mat_B[k][j];
            }
            printf("%d ",hasil[i][j]);
        }
        printf("\n");
    }
}
int main(){
    // Inisiasi variabel
    int pil; // Variabel untuk pilihan
    int size; // Variabel ukuran matriks

    printf("=============================================\n");
    printf("Selamat datang di program perkalian matriks\n");
    printf("Silakan pilih ukuran matriks: \n");
    printf("1. 10 x 10\n");
    printf("2. 100 x 100\n");
    printf("3. 1000 x 1000\n");
    printf("4. 10000 x 10000\n");
    printf("Masukkan ukuran matriks yang diinginkan [1-4]: ");
    scanf("%d",&pil);

    while (pil < 0 || pil > 5) {
        printf("Masukkan salah, silakan masukkan kembali: ");
        scanf("%d", &pil);
    }

    if (pil == 1){
        size = 1;
    }
    else if (pil == 2){
        size = 2;
    }
    else if (pil == 3){
        size = 3;
    }
    else if (pil == 4){
        size = 4;
    }

    // Inisialisasi ukuran matriks berdasarkan pilihan
    int mat_A[size][size];
    int mat_B[size][size];

    // Memasukkan data untuk matriks 1
    printf("\nSilakan masukkan data Matrix 1\n");
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            mat_A[i][j] = rand() % 11;
            printf("%d ",mat_A[i][j]);
        }
        printf("\n");
    }

    // Memasukkan data untuk matriks 2
    printf("\nSilakan masukkan data Matrix 2\n");
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            mat_B[i][j] = rand() % 11;
            printf("%d ",mat_B[i][j]);
        }
        printf("\n");
    }

    // Proses perkalian berdasarkan ukuran matriks dengan pemanggilan prosedur
    // kaliMatriks
    if (pil == 1){
        kaliMatriks(1, mat_A, mat_B);
    }
    else if (pil == 2){
        kaliMatriks(2, mat_A, mat_B);
    }
    else if (pil == 3){
        kaliMatriks(3, mat_A, mat_B);
    }
    else if (pil == 4){
        kaliMatriks(4, mat_A, mat_B);
    }
    return 0;
}
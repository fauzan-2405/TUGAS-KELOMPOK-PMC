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

// Prosedur untuk menampilkan matriks hasil perkalian
void display(int size, int hasil[size][size]);

// Prosedur perkalian matriks dengan Metode Iterative
void kaliMatriksIterative(int size, int mat_A[size][size], int mat_B[size][size]);

// Prosedur perkalian matriks dengan Metode Recursive
void kaliMatriksRecursive(int size, int mat_A[size][size], int mat_B[size][size], int hasil[size][size]);

// Prosedur perkalian matriks dengan Metode Stransens's
void kaliMatriksStrassens(int mat_A[2][2], int mat_B[2][2]);


int main(){
    // Inisiasi variabel
    int method; // Variabel untuk menyimpan pilihan metode mana yang akan digunakan
    int pil; // Variabel untuk pilihan size
    int size; // Variabel ukuran matriks

    printf("=============================================\n");
    printf("Selamat datang di program perkalian matriks\n");
    printf("Program ini dapat melakukan operasi perkalian matriks dengan 3 cara\n");
    printf("Silakan pilih metode perkalian matriks yang dilakukan: \n");
    printf("1. Iterative\n");
    printf("2. Recursive\n");
    printf("3. Strassen's\n");
    printf("Masukkan metode yang diinginkan [1-3]: ");
    scanf("%d", &method);
    while (method < 0 || method > 3) {
        printf("Masukkan salah, silakan masukkan kembali: ");
        scanf("%d", &method);
    }

    // Pilihan 1 & 2 : Metode Iterative dan Recursive
    if (method == 1 || method == 2) {
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

        // Proses perkalian berdasarkan ukuran matriks dengan pemanggilan
        // prosedur kaliMatriksIterative atau kaliMatriksRecursive
        if (method == 1) {
            if (pil == 1){
                kaliMatriksIterative(1, mat_A, mat_B);
            }
            else if (pil == 2){
                kaliMatriksIterative(2, mat_A, mat_B);
            }
            else if (pil == 3){
                kaliMatriksIterative(3, mat_A, mat_B);
            }
            else if (pil == 4){
                kaliMatriksIterative(4, mat_A, mat_B);
            }
        }

        else {
            int hasil[size][size];
            if (pil == 1){
                kaliMatriksRecursive(1, mat_A, mat_B, hasil);
                display(1, hasil);
            }
            else if (pil == 2){
                kaliMatriksRecursive(2, mat_A, mat_B, hasil);
                display(2, hasil);
            }
            else if (pil == 3){
                kaliMatriksRecursive(3, mat_A, mat_B, hasil);
                display(3, hasil);
            }
            else if (pil == 4){
                kaliMatriksRecursive(4, mat_A, mat_B, hasil);
                display(4, hasil);
            }
        }
    }

    // Pilihan 3 : Metode Strassen's
    /* Untuk metode strassens, ukuran matriks yang diperbolehkan hanya matriks
       yang memiliki dimensi n x n dengan n merupakan angka perpangkatan dari 2
       atau 2^k.
       Kali ini untuk mempermudah perhitungan, kita akan memakai matriks berukuran
       2 x 2.
    */ 
    else {
        // Inisialisasi matriks
        size = 2;
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

        kaliMatriksStrassens(mat_A, mat_B);
    }
    return 0;
}

// REALISASI FUNGSI
// Prosedur display
void display (int size, int hasil[size][size]) {
    printf("\nHasil kali matrix\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", hasil[i][j]);
        }
        printf("\n");
    }
}

// 1. Metode Iterative
void kaliMatriksIterative(int size, int mat_A[size][size], int mat_B[size][size]) {
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

// 2. Metode Recursive
void kaliMatriksRecursive(int size, int mat_A[size][size], int mat_B[size][size], int hasil[size][size])
{
    // Inisiasi variabel
    int row1 = size;
    int col1 = size;
    int row2 = size;
    int col2 = size;
    static int i = 0, j = 0, k = 0;

    if (i >= row1)
    {
        return;
    }
    else if (i < row1)
    {
        if (j < col2)
        {
            if (k < col1)
            {
                hasil[i][j] += (mat_A[i][k]) * (mat_B[k][j]);
                k++;
                kaliMatriksRecursive(col1, mat_A, mat_B, hasil);
            }
            k = 0;
            j++;
            kaliMatriksRecursive(col2, mat_A, mat_B, hasil);
        }
        j = 0;
        i++;
        kaliMatriksRecursive(row1, mat_A, mat_B, hasil);
    }
}

// 3. Metode Strassens's
void kaliMatriksStrassens(int mat_A[2][2], int mat_B[2][2]) {
    // Inisiasi variabel
    int i, j;
    int hasil[2][2];
    int row1, row2, m3, m4 , m5, m6, m7;

    // Algoritma Strassens's
    row1= (mat_A[0][0] + mat_A[1][1]) * (mat_B[0][0] + mat_B[1][1]);
    row2= (mat_A[1][0] + mat_A[1][1]) * mat_B[0][0];
    m3= mat_A[0][0] * (mat_B[0][1] - mat_B[1][1]);
    m4= mat_A[1][1] * (mat_B[1][0] - mat_B[0][0]);
    m5= (mat_A[0][0] + mat_A[0][1]) * mat_B[1][1];
    m6= (mat_A[1][0] - mat_A[0][0]) * (mat_B[0][0]+mat_B[0][1]);
    m7= (mat_A[0][1] - mat_A[1][1]) * (mat_B[1][0]+mat_B[1][1]);

    hasil[0][0] = row1 + m4- m5 + m7;
    hasil[0][1] = m3 + m5;
    hasil[1][0] = row2 + m4;
    hasil[1][1] = row1 - row2 + m3 + m6;

    // Print hasil perkalian matriks
    printf("\nHasil kali matrix \n");
    for(i = 0; i < 2 ; i++){
        for(j = 0;j < 2; j++) {
            printf("%d ", hasil[i][j]);
        }
        printf("\n");
    }
}


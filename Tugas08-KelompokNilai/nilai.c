#include <stdio.h>
#include <string.h>

// Fungsi untuk menghitung nilai akhir
int calcnilai(int tugas, int quiz, int UTS, int UAS) {
    return (10 * tugas / 100) + (20 * quiz / 100) + (30 * UTS / 100) + (40 * UAS / 100);
}

// Fungsi untuk menampilkan nilai akhir, huruf mutu, dan keterangan
void displaynilaiakhir(char *nama, char *nim, int nilaiakhir) {
    char *hurufmutu;
    char *keterangan;

    if (nilaiakhir > 90) {
       strcpy (hurufmutu, "A");
        keterangan = "Lulus";
    } else if (81 <= nilaiakhir <= 90) {
        strcpy (hurufmutu, "AB");
        keterangan = "Lulus";
    } else if (71 <= nilaiakhir <= 80) {
        strcpy (hurufmutu, "B");
        keterangan = "Lulus";
    } else if (61 <= nilaiakhir <= 70) {
        strcpy (hurufmutu, "BC");
        keterangan = "Lulus";
    } else if (51 <= nilaiakhir <= 60) {
        strcpy (hurufmutu, "C");
        keterangan = "Lulus";
    } else if (45 <= nilaiakhir <= 50) {
        strcpy (hurufmutu, "D");
        keterangan = "Tidak Lulus";
    } else if (nilaiakhir < 45) {
        strcpy (hurufmutu, "E");
        keterangan = "Tidak Lulus";
    }

    printf("Nama Mahasiswa : %s\n", nama);
    printf("NIM : %s\n", nim);
    printf("Nilai Akhir : %d\n", nilaiakhir);
    printf("Huruf Mutu : %s\n", hurufmutu);
    printf("Keterangan : %s\n", keterangan);
}

int main() {
    char nama[50];
    char nim[20];
    int tugas, quiz, UTS, UAS;

    // Input data mahasiswa
    printf("Nama Mahasiswa : "); scanf("%s", nama);
    printf("NIM : "); scanf("%s", nim);
    printf("Nilai Tugas : "); scanf("%d", &tugas);
    printf("Nilai Quiz : "); scanf("%d", &quiz);
    printf("Nilai UTS : "); scanf("%d", &UTS);
    printf("Nilai UAS  : "); scanf("%d", &UAS);
    printf("\n");

    // Hitung nilai akhir menggunakan fungsi calcnilai
    int nilaiakhir = calcnilai(tugas, quiz, UTS, UAS);

    // Tampilkan hasil menggunakan fungsi displaynilaiakhir
    displaynilaiakhir(nama, nim, nilaiakhir);

    return 0;
}
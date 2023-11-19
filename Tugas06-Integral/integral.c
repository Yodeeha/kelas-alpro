#include <stdio.h>

// Fungsi yang akan diintegralkan (fungsi kelompok kami (x+2)^2)
double fungsi(double x) {
    return (x+2)*(x+2);
}

// Metode trapesium untuk menghitung integral
double trapesium(double a, double b, int n) {
    double h = (b - a) / n;
    double integral = (fungsi(a) + fungsi(b)) / 4.0;

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        integral += fungsi(x);
    }

    return integral * h;
}

int main() {
    double batas_bawah = 0; 
    double batas_atas = 4;  
    int N;

    printf("Masukkan jumlah sub-interval: ");
    scanf("%d", &N);

    double hasil_integral = (batas_atas * batas_atas * batas_atas / 3) - (batas_bawah * batas_bawah * batas_bawah / 3);

    // Perhitungan integral secara analitik 
    double hasil_analitik = trapesium(batas_bawah, batas_atas, N);
    

    printf("Hasil hitung integral : %lf\n", hasil_integral);
    printf("Hasil integral analitik : %lf\n", hasil_analitik);

    return 0;
}
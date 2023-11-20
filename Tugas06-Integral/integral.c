#include <stdio.h>

//(fungsi kelompok kami (x+2)^2)
double fungsi(double x) {
    return (x+2)*(x+2);
}

<<<<<<< HEAD
// Metode trapesium untuk menghitung integral
double trapesium(double a, double b, int n) {
    double h = (b - a) / n;
    double integral = (fungsi(a) + fungsi(b)) / 4.0;
=======

double trapesium(double a, double b, int n) {
    double h = (b - a) / n;
    double integral = (fungsi(a) + fungsi(b)) / 4;
>>>>>>> efe8621d3fdef131d094640a9cded94548c57fa1

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

    printf("Masukkan nilai intervalnya: ");
    scanf("%d", &N);

<<<<<<< HEAD
    double hasil_integral = (batas_atas * batas_atas * batas_atas / 3) - (batas_bawah * batas_bawah * batas_bawah / 3);

    // Perhitungan integral secara analitik 
    double hasil_analitik = trapesium(batas_bawah, batas_atas, N);
    

    printf("Hasil hitung integral : %lf\n", hasil_integral);
    printf("Hasil integral analitik : %lf\n", hasil_analitik);
=======
    double hasil = trapesium(batas_bawah, batas_atas, N);


    printf("Hasil integral: %lf\n", hasil);
>>>>>>> efe8621d3fdef131d094640a9cded94548c57fa1

    return 0;
}

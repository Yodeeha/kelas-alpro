#include <stdio.h>
#define phi 3.14//(A)tentukan variabel

int main () {
    float v, r, t;//(B)Tentukan tipe data

    //Input
    printf("Jari jari kerucut : "); 
    scanf ("%f",&r);//(C)Tentukan variabel
    printf("Tinggi kerucut : ");
    scanf("%f",&t);

    //Oprasi hitung
    v = phi*1/3*r*r*t;

    //Output
    printf("Volume Kerucut = %.2f cm^3",&v);//(D)Tentukan format sehingga 2 angka belakang koma
    return 0;
}
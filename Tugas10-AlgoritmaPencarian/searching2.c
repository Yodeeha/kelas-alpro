#include <stdio.h>
#define MAX_ELEMEN 100

int main (){
    int BIL[MAX_ELEMEN];
    int N,X;

    printf("Masukkan Banyaknya elemen yang diinginkan :");
    scanf("%d",&N);

    for (int j=0; j<N; j++){
        printf("BIL[%d] = ", j); scanf("%d",&BIL[j]);
    }
    printf ("Masukkan nilai yang akan dicari : "); scanf("%d",&X);

    int k=0;
    while ((k<N) && (BIL[k] != X))
    {
        k++;
    }
    if (BIL[k] == X )
    {
        printf("%d Ditemukan dalam Array ,Yaitu pada indeks ke-%d",X,k);    
    } else
    {
        printf("%d tidak ditemukan dalam array ",X);
    }
    return 0;   
}
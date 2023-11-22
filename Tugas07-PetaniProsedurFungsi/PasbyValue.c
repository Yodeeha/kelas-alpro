#include <stdio.h>

void main(){
    int x,y,i,j,cari;
    int a[100][100];
    printf("Masukan banyak baris : ");
    scanf("%d", &x);
    printf("Masukan banyak kolom : ");
    scanf("%d", &y);
    for(i=0;i<x;i++){
        for(j=0;j<y;j++){
            printf("Masukan angka array[%d][%d] : ",i+1,j+1);
            scanf("%d", &a[i][j]);
        }
    }
    printf("Masukan angka yang akan di cari : ");
    scanf("%d", &cari);
    for(i=0;i<x;i++){
        for(j=0;j<y;j++){
            if(cari == a[i][j]){
                printf("angka %d terdapat pada array[%d][%d]", cari,i+1,j+1);
            }
        }
    }
}
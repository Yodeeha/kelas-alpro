#include <stdio.h>
void main (){
    int x,y,i,j,cari;
    int a[100][100];

    printf("Masukkan Jumlah Baris :");
    scanf("%d",&x);
    printf("Masukkan Jumlah Kolom : ");
    scanf("%d",&y);
    for ( i = 0; i < x ; i++)
    {
        for (
             j = 0; j < y ; j++)
        {
            printf("Masukkan Angka array [%d][%d] :",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
        
    }
    printf("Masukkan angka yang dicari :");
    scanf("%d",&cari);
    for ( i = 0; i < x ; i++)
    {
        for (
             j = 0; j < y ; j++)
        {
            if (cari == a[i][j])
            {
                printf("angka %d tersebut pada array [%d][%d] : ",cari,i+1,j+1);
            }
        }
    }
            

}
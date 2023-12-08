#include <stdio.h>

int main (){
    int  i;
    float data[25], total, ratarata;
    float max, min;

    for(i=0;i<3;i++){
        scanf("%f", &data[i]);
       total += data[i];  
    }
    ratarata = total/3;

    for(i=0;i<3;i++){
        if (i == 0) {
            max = min = data[i];
        } else {
        if(max<data[i]){
        max = data[i];
        }

        if(min>data[i]){
        min = data[i];
        }
    }
    }
    
    printf("Rata rata data : %.0f\n", ratarata);
    printf("Nilai max : %.0f\n", max);
    printf("Nilai min : %.0f\n\n", min);

}
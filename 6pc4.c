#include <stdio.h>
int main(){
     char name[50], web_adress [50];

     printf("Nama :");
     gets(name);

     printf("Web_address ");
     gets(web_adress);

     printf("You enteres: %s\n", name);
     printf("Web address: %s\n", web_adress);

     return(0);
}

#include <stdio.h>
int main(){
     char name[50], email [50];

     printf("Nama :");
     fgets(name,sizeof(name),stdin);

     printf("Email_address: ");
     fgets(email,sizeof(email),stdin);

     printf("\n-------------------------\n");

     printf("Nama anda : %s\n", name);
     printf("Email address: %s\n",email);

     return 0;
}

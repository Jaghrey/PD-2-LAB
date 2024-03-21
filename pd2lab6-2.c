#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *name_surname;

   
    name_surname = (char *)malloc(50 * sizeof(char));

    
    printf("Adinizi ve soyadinizi giriniz: ");
    scanf("%[^\n]", name_surname);

    
    while(getchar() != '\n');

   
    if(strlen(name_surname) >= 50) {
        name_surname[49] = '\0';
    }

    printf("Adiniz ve soyadiniz: %s\n", name_surname);


    free(name_surname);

    return 0;
}


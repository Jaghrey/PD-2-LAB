#include <stdio.h>

int main() {
    char str[100]; 
    char *ptr;

    
    printf("Bir string girin: ");
    scanf("%s", str);

    
    ptr = str;
    while (*ptr != '\0') {
        ptr++;
    }
    ptr--; 

    
    printf("Tersine cevrilmis string: ");

   
    while (ptr >= str) {
        printf("%c", *ptr);
        ptr--;
    }
    printf("\n");

    return 0;
}


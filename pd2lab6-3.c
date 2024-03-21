#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *name; 
    name = (char *)malloc(20 * sizeof(char));
    strcpy(name, "Cagri");
    printf("Adiniz: %s\n", name);
    name = (char *)realloc(name, 30 * sizeof(char));
    strcat(name, " Zengin");
    printf("Adiniz ve soyadiniz: %s\n", name);
    free(name);

    return 0;
}


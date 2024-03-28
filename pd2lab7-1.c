#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *kelime1, *kelime2;
    int uzunluk1, uzunluk2;


    kelime1 = (char *)malloc(100 * sizeof(char)); // 100 karakterlik bir alan ayýrýyoruz, isteðe göre deðiþtirilebilir
    kelime2 = (char *)malloc(100 * sizeof(char));


    printf("Iki kelime giriniz:\n");
    scanf("%s %s", kelime1, kelime2);


    uzunluk1 = strlen(kelime1);
    uzunluk2 = strlen(kelime2);


    if (uzunluk1 == uzunluk2) {
        printf("Iki kelime de ayni uzunlukta.\n");
    } else if (uzunluk1 > uzunluk2) {
        printf("Ilk kelime daha uzun.\n");
    } else {
        printf("Ikinci kelime daha uzun.\n");
    }


    free(kelime1);
    free(kelime2);

    return 0;
}

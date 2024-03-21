#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tek_cift_ayir(char *ogrenci_no, int **tek_sayilar, char **cift_sayilar) {
    int tek_sayi_sayisi = 0;
    int cift_sayi_sayisi = 0;
    int length = strlen(ogrenci_no);

    for (int i = 0; i < length; i++) {
        int digit = ogrenci_no[i] - '0';
        if (digit % 2 == 0) {
            cift_sayi_sayisi++;
        } else {
            tek_sayi_sayisi++;
        }
    }

    *tek_sayilar = (int *)malloc(tek_sayi_sayisi * sizeof(int));
    *cift_sayilar = (char *)malloc(cift_sayi_sayisi * sizeof(char));

    int tek_index = 0;
    int cift_index = 0;
    for (int i = 0; i < length; i++) {
        int digit = ogrenci_no[i] - '0';
        if (digit % 2 == 0) {
            (*cift_sayilar)[cift_index++] = ogrenci_no[i];
        } else {
            (*tek_sayilar)[tek_index++] = digit;
        }
    }
}

int main() {
    char ogrenci_no[20]; // Öðrenci numarasý için geniþletilebilir bir boyut
    printf("Lütfen öðrenci numaranýzý girin: ");
    scanf("%s", ogrenci_no);

    int *tek_sayilar;
    char *cift_sayilar;

    tek_cift_ayir(ogrenci_no, &tek_sayilar, &cift_sayilar);

    printf("Tek Sayýlar: ");
    for (int i = 0; i < strlen(ogrenci_no); i++) {
        printf("%d ", tek_sayilar[i]);
    }
    printf("\n");

    printf("Çift Sayýlar: %s\n", cift_sayilar);

    free(tek_sayilar);
    free(cift_sayilar);

    return 0;
}


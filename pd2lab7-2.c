#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *kelimeyi_bul(char *cumle, char *kelime, int *bulunan_sayisi) {
    int *baslangic_indisleri = NULL;
    int max_bulunan = 10;
    int bulunan = 0;
    int kelime_uzunlugu = strlen(kelime);
    int cumle_uzunlugu = strlen(cumle);


    baslangic_indisleri = (int *)malloc(max_bulunan * sizeof(int));


    for (int i = 0; i <= cumle_uzunlugu - kelime_uzunlugu; i++) {

        if (strncmp(&cumle[i], kelime, kelime_uzunlugu) == 0) {

            baslangic_indisleri[bulunan] = i;
            bulunan++;


            if (bulunan >= max_bulunan) {
                max_bulunan *= 2;
                baslangic_indisleri = realloc(baslangic_indisleri, max_bulunan * sizeof(int));
            }
        }
    }


    *bulunan_sayisi = bulunan;
    return baslangic_indisleri;
}

int main() {
    char cumle[1000];
    char kelime[100];
    int *baslangic_indisleri;
    int bulunan_sayisi;


    printf("Cumleyi giriniz: ");
    fgets(cumle, sizeof(cumle), stdin);
    printf("Aranacak kelimeyi giriniz: ");
    scanf("%s", kelime);


    baslangic_indisleri = kelimeyi_bul(cumle, kelime, &bulunan_sayisi);


    if (bulunan_sayisi > 0) {
        printf("Kelime \"%s\" cumle icinde bulundu:\n", kelime);
        for (int i = 0; i < bulunan_sayisi; i++) {
            printf("Baslangic Indisi: %d\n", baslangic_indisleri[i]);
        }
    } else {
        printf("Kelime \"%s\" cumle icinde bulunamadi.\n", kelime);
    }


    free(baslangic_indisleri);

    return 0;
}

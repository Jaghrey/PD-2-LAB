#include <stdio.h>
#include <stdlib.h>

int main() {
    int eleman_sayisi;
    printf("Eleman sayýsýný giriniz: ");
    scanf("%d", &eleman_sayisi);

    int *dizi = (int *)calloc(eleman_sayisi, sizeof(int));

    printf("%d adet elemaný giriniz:\n", eleman_sayisi);

    for (int i = 0; i < eleman_sayisi; i++) {
        scanf("%d", &dizi[i]);
    }

    if (eleman_sayisi > 0) {
        int max_deger = dizi[0];
        for (int i = 1; i < eleman_sayisi; i++) {
            if (dizi[i] > max_deger) {
                max_deger = dizi[i];
            }
        }
        printf("En büyük deðer: %d\n", max_deger);
    } else {
        printf("Dizi boþ!\n");
    }

    free(dizi);

    return 0;
}


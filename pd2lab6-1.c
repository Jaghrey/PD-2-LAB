#include <stdio.h>
#include <stdlib.h>

int main() {
    int eleman_sayisi;
    printf("Eleman say�s�n� giriniz: ");
    scanf("%d", &eleman_sayisi);

    int *dizi = (int *)calloc(eleman_sayisi, sizeof(int));

    printf("%d adet eleman� giriniz:\n", eleman_sayisi);

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
        printf("En b�y�k de�er: %d\n", max_deger);
    } else {
        printf("Dizi bo�!\n");
    }

    free(dizi);

    return 0;
}


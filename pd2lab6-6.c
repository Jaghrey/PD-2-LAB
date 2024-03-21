#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void kelime_ters_yaz(const char *cumle) {
    int uzunluk = strlen(cumle);

    char *cumle_kopyasi = (char *)malloc((uzunluk + 1) * sizeof(char));
    if (cumle_kopyasi == NULL) {
        printf("Bellek ayýrma basarisiz oldu. Program sonlandiriliyor...");
        return;
    }

    strcpy(cumle_kopyasi, cumle);

    int kelime_baslangic = uzunluk - 1;
    int kelime_sonu = uzunluk - 1;


    for (int i = uzunluk - 1; i >= 0; i--) {
        if (cumle_kopyasi[i] == ' ' || i == 0) {

            if (i == 0) {
                kelime_baslangic = 0;
            } else {
                kelime_baslangic = i + 1;
            }

            for (int j = kelime_baslangic; j <= kelime_sonu; j++) {
                printf("%c", cumle_kopyasi[j]);
            }

            if (i != 0) {
                printf(" ");
            }

            kelime_sonu = i - 1;
        }
    }

    printf("\n");

    free(cumle_kopyasi);
}

int main() {
    char cumle[100];

    printf("Bir cumle giriniz: ");
    fgets(cumle, sizeof(cumle), stdin);
    cumle[strcspn(cumle, "\n")] = '\0';


    printf("Cumlenin sondan basa yazilmis hali: ");
    kelime_ters_yaz(cumle);

    return 0;
}


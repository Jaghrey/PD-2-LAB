#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *cumle;
    int kelime_sayisi = 0;
    int i, uzunluk;

    cumle = (char *)malloc(100 * sizeof(char));
    printf("Metni giriniz: ");
    scanf("%[^\n]%*c", cumle);

    uzunluk = strlen(cumle);


    for (i = 0; i < uzunluk; i++) {

        if ((i == 0 || cumle[i - 1] == ' ') && cumle[i] != ' ') {
            kelime_sayisi++;
        }
    }

    printf("Metinde %d adet kelime bulunmaktadir.\n", kelime_sayisi);

    free(cumle);

    return 0;
}

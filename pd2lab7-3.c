#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char *text;
    int *harf_sayilari;

    text = (char *)malloc(100 * sizeof(char));
    harf_sayilari = (int *)calloc(26, sizeof(int));
    printf("Texti giriniz: ");
    scanf("%[^\n]%*c", text);


    for (int i = 0; text[i] != '\0'; i++) {
        text[i] = toupper(text[i]);
    }


    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            harf_sayilari[text[i] - 'A']++;
        }
    }


    for (int i = 0; i < 26; i++) {
        if (harf_sayilari[i] > 0) {
            printf("%d adet %c\n", harf_sayilari[i], 'A' + i);
        }
    }

    free(text);
    free(harf_sayilari);

    return 0;
}

#include <stdio.h>

int i(int *dizi, int eleman_sayisi) {
   
    if (eleman_sayisi == 0) {
        return 0;
    } else {
        
        int tek_sayi = dizi[eleman_sayisi - 1] % 2;
        return tek_sayi + i (dizi, eleman_sayisi - 1);
    }
}

int main() {
    
    int dizi[] = {1, 2, 3, 4, 5, 6, 7, 8, 9,10};
    int eleman_sayisi = sizeof(dizi) / sizeof(dizi[0]);
    int sonuc = i(dizi, eleman_sayisi);

    printf("Dizideki tek sayi adedi: %d\n", sonuc);

    return 0;
}



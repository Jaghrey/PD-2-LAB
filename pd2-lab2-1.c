#include <stdio.h>

int toplamHesapla(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n + toplamHesapla(n - 1);
    }
}

int main() {
    int sayi = 15;
    int sonuc = toplamHesapla(sayi);
    printf("1'den %d'e kadar olan sayilarin toplami: %d\n", sayi, sonuc);

    return 0;
}


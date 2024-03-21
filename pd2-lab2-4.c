#include <stdio.h>


int i(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return i(b, a % b);
    }
}

int main() {
    int sayi1, sayi2;


    printf("Iki pozitif sayi giriniz:\n");
    scanf("%d %d", &sayi1, &sayi2);


    printf("En buyuk ortak bolen: %d\n", i(sayi1, sayi2));

    return 0;
}


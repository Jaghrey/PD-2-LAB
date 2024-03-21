#include <stdio.h>

int basamaklariTopla(int sayi) {
    if (sayi < 10) {
        return sayi;
    } else {
        return sayi % 10 + basamaklariTopla(sayi / 10);
    }
}

int main() {
	int i ;
	printf("Basamaklarinin toplamini istediginiz sayiyi yaziniz:");
	scanf("%d,i");
    int verilenSayi = i;
    int sonuc = basamaklariTopla(verilenSayi);
    printf("%d sayisinin basamaklari toplami: %d\n", verilenSayi, sonuc);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>

void hesapla(int sayi1, int sayi2){
	int sonuc;
	sonuc = sayi1 * sayi2;
	printf("%d", sonuc);
}

int main () {
	
	int a,b;
	
	printf("sayi1 girin:");
scanf("%d", &a);
	printf("sayi2 girin:");
scanf("%d", &b);

hesapla(a,b);
	
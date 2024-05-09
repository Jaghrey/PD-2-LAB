#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int numara;
    char ad[50];
    float vize_notu;
    float final_notu;
} Ogrenci;


void menuGoster();
void kayitEkle(Ogrenci **ogrenciler, int *ogrenci_sayisi);
void kayitListele(const Ogrenci *ogrenciler, int ogrenci_sayisi);
void kayitGuncelle(Ogrenci *ogrenciler, int ogrenci_sayisi);
float sinifOrtalamasiHesapla(const Ogrenci *ogrenciler, int ogrenci_sayisi);
void enBasariliOgrenci(const Ogrenci *ogrenciler, int ogrenci_sayisi);

int main() {
    Ogrenci *ogrenciler = NULL;
    int ogrenci_sayisi = 0;
    int secim;

    do {
        menuGoster();
        printf("Seciminizi yapiniz: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                kayitEkle(&ogrenciler, &ogrenci_sayisi);
                break;
            case 2:
                kayitListele(ogrenciler, ogrenci_sayisi);
                break;
            case 3:
                kayitGuncelle(ogrenciler, ogrenci_sayisi);
                break;
            case 4:
                printf("Sinif Ortalamasi: %.2f\n", sinifOrtalamasiHesapla(ogrenciler, ogrenci_sayisi));
                break;
            case 5:
                enBasariliOgrenci(ogrenciler, ogrenci_sayisi);
                break;
            case 0:
                printf("Programdan cikiliyor...\n");
                break;
            default:
                printf("Gecersiz secim!\n");
        }
    } while (secim != 0);

    free(ogrenciler);
    return 0;
}


void menuGoster() {
    printf("\n--- MENU ---\n");
    printf("1- Yeni Kayit Ekleme\n");
    printf("2- Kayit Listeleme\n");
    printf("3- Kayit Guncelleme\n");
    printf("4- Sinif Ortalamasi Hesapla\n");
    printf("5- Ortalamaya Gore En Basarili Ogrenci Bilgisini Goster\n");
    printf("0- Cikis\n");
}


void kayitEkle(Ogrenci **ogrenciler, int *ogrenci_sayisi) {
    (*ogrenci_sayisi)++;
    *ogrenciler = (Ogrenci *)realloc(*ogrenciler, (*ogrenci_sayisi) * sizeof(Ogrenci));

    printf("Ogrenci numarasi: ");
    scanf("%d", &((*ogrenciler)[(*ogrenci_sayisi) - 1].numara));
    printf("Ogrenci adi: ");
    scanf("%s", (*ogrenciler)[(*ogrenci_sayisi) - 1].ad);
    printf("Ogrenci vize notu   --> ");
    scanf("%f", &((*ogrenciler)[(*ogrenci_sayisi) - 1].vize_notu));
    printf("Ogrenci final notu  --> ");
    scanf("%f", &((*ogrenciler)[(*ogrenci_sayisi) - 1].final_notu));
}


void kayitListele(const Ogrenci *ogrenciler, int ogrenci_sayisi) {
    int secim;
    printf("Listeleme Secenegini Seciniz:\n");
    printf("1- Numaraya Gore\n");
    printf("2- Nota Gore\n");
    scanf("%d", &secim);

    if (secim == 1) {
        printf("Numara\tAd\tVize Notu\tFinal Notu\n");
        for (int i = 0; i < ogrenci_sayisi; i++) {
            printf("%d\t%s\t%.2f\t\t%.2f\n", ogrenciler[i].numara, ogrenciler[i].ad, ogrenciler[i].vize_notu, ogrenciler[i].final_notu);
        }
    } else if (secim == 2) {
        float limit;
        printf("Not Limitini Giriniz: ");
        scanf("%f", &limit);
        printf("Numara\tAd\tVize Notu\tFinal Notu\n");
        for (int i = 0; i < ogrenci_sayisi; i++) {
            if ((ogrenciler[i].vize_notu + ogrenciler[i].final_notu) >= limit) {
                printf("%d\t%s\t%.2f\t\t%.2f\n", ogrenciler[i].numara, ogrenciler[i].ad, ogrenciler[i].vize_notu, ogrenciler[i].final_notu);
            }
        }
    } else {
        printf("Gecersiz secim!\n");
    }
}


void kayitGuncelle(Ogrenci *ogrenciler, int ogrenci_sayisi) {
    int numara;
    printf("Guncellenecek ogrencinin numarasini giriniz: ");
    scanf("%d", &numara);

    int bulundu = 0;
    for (int i = 0; i < ogrenci_sayisi; i++) {
        if (ogrenciler[i].numara == numara) {
            printf("Yeni vize notu: ");
            scanf("%f", &(ogrenciler[i].vize_notu));
            printf("Yeni final notu: ");
            scanf("%f", &(ogrenciler[i].final_notu));
            bulundu = 1;
            printf("Kayit guncellendi.\n");
            break;
        }
    }
    if (!bulundu) {
        printf("Ogrenci bulunamadi!\n");
    }
}


float sinifOrtalamasiHesapla(const Ogrenci *ogrenciler, int ogrenci_sayisi) {
    float toplam = 0;
    for (int i = 0; i < ogrenci_sayisi; i++) {
        toplam += ogrenciler[i].vize_notu + ogrenciler[i].final_notu;
    }
    return toplam / (ogrenci_sayisi * 2);
}


void enBasariliOgrenci(const Ogrenci *ogrenciler, int ogrenci_sayisi) {
    int en_iyi = 0;
    float en_yuksek_not = (ogrenciler[0].vize_notu + ogrenciler[0].final_notu) / 2;

    for (int i = 1; i < ogrenci_sayisi; i++) {
        float not_ortalamasi = (ogrenciler[i].vize_notu + ogrenciler[i].final_notu) / 2;
        if (not_ortalamasi > en_yuksek_not) {
            en_iyi = i;
            en_yuksek_not = not_ortalamasi;
        }
    }

    printf("En Basarili Ogrenci:\n");
    printf("Numara: %d\n", ogrenciler[en_iyi].numara);
    printf("Ad: %s\n", ogrenciler[en_iyi].ad);
    printf("Not Ortalamasi: %.2f\n", en_yuksek_not);
}

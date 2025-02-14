#include <stdio.h>
#include <math.h>
#include <string.h>
#define KRITER_SAYISI 5
#define MAHALLE_SAYISI 3

typedef struct {
    char* ad;
    double kriterler[KRITER_SAYISI];
    double agirliklar[KRITER_SAYISI];
    double maliyet_fayda;
} Mahalle;

void softmax(double girdi[], double cikti[], int boyut) {
    double toplam = 0.0;
    for (int i = 0; i < boyut; i++) {
        cikti[i] = exp(girdi[i]);
        toplam += cikti[i];
    }
    for (int i = 0; i < boyut; i++) {
        cikti[i] /= toplam;
    }
}

int main() {
    Mahalle mahalleler[MAHALLE_SAYISI] = {
        {"Karakas Mahallesi", {1200, 3, 500000, 80, 90}},
        {"Bademlik Mahallesi", {800, 5, 400000, 70, 85}},
        {"Istasyon Mahallesi", {1500, 2, 600000, 60, 95}}
    };
    
    char girdi[50];
    for (int i = 0; i < MAHALLE_SAYISI; i++) {
        printf("%s icin verileri giriniz (Nufus yogunlugu, Ulasim altyapisi, Maliyet, Cevresel etki, Sosyal fayda) [Varsayilan: %.0f, %.0f, %.0f, %.0f, %.0f]:\n", 
               mahalleler[i].ad,
               mahalleler[i].kriterler[0],
               mahalleler[i].kriterler[1],
               mahalleler[i].kriterler[2],
               mahalleler[i].kriterler[3],
               mahalleler[i].kriterler[4]);
        
        for (int j = 0; j < KRITER_SAYISI; j++) {
            fgets(girdi, sizeof(girdi), stdin);
            if (strcmp(girdi, "\n") != 0) {
                sscanf(girdi, "%lf", &mahalleler[i].kriterler[j]);
            }
        }
    }
    
    for (int i = 0; i < MAHALLE_SAYISI; i++) {
        softmax(mahalleler[i].kriterler, mahalleler[i].agirliklar, KRITER_SAYISI);
    }
    
    for (int i = 0; i < MAHALLE_SAYISI; i++) {
        mahalleler[i].maliyet_fayda = mahalleler[i].kriterler[4] - (mahalleler[i].kriterler[2] / 10000);
    }
    
    int en_iyi = 0;
    for (int i = 1; i < MAHALLE_SAYISI; i++) {
        if (mahalleler[i].maliyet_fayda > mahalleler[en_iyi].maliyet_fayda) {
            en_iyi = i;
        }
    }
    
    printf("Mahalle Analizi Sonuclar:\n");
    for (int i = 0; i < MAHALLE_SAYISI; i++) {
        printf("%s -> Maliyet-Fayda: %.2f\n", mahalleler[i].ad, mahalleler[i].maliyet_fayda);
    }
    
    printf("\nEn uygun toplu tasima guzergahi: %s\n", mahalleler[en_iyi].ad);
    
    return 0;
}


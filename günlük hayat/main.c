#include <stdio.h>
#include <time.h>

typedef struct {
    int yil, ay, gun, saat, dakika, saniye;
} TarihSaat;

time_t tarihSaatToEpoch(TarihSaat ts) {
    struct tm t = {0};
    t.tm_year = ts.yil - 1900;
    t.tm_mon = ts.ay - 1;
    t.tm_mday = ts.gun;
    t.tm_hour = ts.saat;
    t.tm_min = ts.dakika;
    t.tm_sec = ts.saniye;
    return mktime(&t);
}

// Kullanýcýdan tarih ve saat bilgilerini tek tek alma fonksiyonu
TarihSaat kullanicidanTarihSaatAl(const char* mesaj) {
    TarihSaat ts;
    printf("\n%s\n", mesaj);
    printf("Yil: ");
    scanf("%d", &ts.yil);
    printf("Ay: ");
    scanf("%d", &ts.ay);
    printf("Gun: ");
    scanf("%d", &ts.gun);
    printf("Saat: ");
    scanf("%d", &ts.saat);
    printf("Dakika: ");
    scanf("%d", &ts.dakika);
    printf("Saniye: ");
    scanf("%d", &ts.saniye);
    return ts;
}

int main() {
    double saatlikUcret = 20.0; // Otopark saatlik ücreti

    // Araç giriþ ve çýkýþ saatlerini kullanýcýdan al
    TarihSaat giris = kullanicidanTarihSaatAl("Aracin giris saatini giriniz:");
    TarihSaat cikis = kullanicidanTarihSaatAl("Aracin cikis saatini giriniz:");

    // Epoch zamanlarýný hesapla
    time_t epochGiris = tarihSaatToEpoch(giris);
    time_t epochCikis = tarihSaatToEpoch(cikis);

    // Park süresini hesapla
    double parkSuresi = difftime(epochCikis, epochGiris) / 3600; // Saat cinsinden
    double toplamUcret = parkSuresi * saatlikUcret;

    printf("\nToplam park suresi: %.2f saat\n", parkSuresi);
    printf("Odenecek ucret: %.2f TL\n", toplamUcret);

    return 0;
}

#include <stdio.h>
#include <time.h>

// Tarih ve saat bilgisini saklamak i�in struct tan�ml�yoruz.
typedef struct {
    int yil, ay, gun;
    int saat, dakika, saniye;
} TarihSaat;

// Epoch zaman�n� farkl� formatlarda saklamak i�in union kullan�yoruz.
typedef union {
    time_t epoch;
    struct tm zamanBilgisi;
} EpochZaman;

// Kullan�c�n�n girdi�i tarih ve saat bilgisini epoch format�na �eviren fonksiyon
time_t tariheDonustur(TarihSaat ts) {
    struct tm zamanBilgisi = {0};
    zamanBilgisi.tm_year = ts.yil - 1900;
    zamanBilgisi.tm_mon = ts.ay - 1;
    zamanBilgisi.tm_mday = ts.gun;
    zamanBilgisi.tm_hour = ts.saat;
    zamanBilgisi.tm_min = ts.dakika;
    zamanBilgisi.tm_sec = ts.saniye;
    return mktime(&zamanBilgisi);
}

// Kullan�c�dan tarih ve saat bilgisini ayr� ayr� alan fonksiyon
void tarihiAl(TarihSaat *ts, const char *mesaj) {
    printf("%s\n", mesaj);
    printf("Yil: ");
    scanf("%d", &ts->yil);
    printf("Ay: ");
    scanf("%d", &ts->ay);
    printf("Gun: ");
    scanf("%d", &ts->gun);
    printf("Saat: ");
    scanf("%d", &ts->saat);
    printf("Dakika: ");
    scanf("%d", &ts->dakika);
    printf("Saniye: ");
    scanf("%d", &ts->saniye);
}

int main() {
    TarihSaat ts1, ts2;
    EpochZaman e1, e2;
    
    tarihiAl(&ts1, "Birinci tarihi giriniz:");
    tarihiAl(&ts2, "Ikinci tarihi giriniz:");
    
    // Epoch zamanlar�n� hesapla
    e1.epoch = tariheDonustur(ts1);
    e2.epoch = tariheDonustur(ts2);
    
    // Zaman fark�n� hesapla
    double fark = difftime(e2.epoch, e1.epoch);
    
    printf("\nBirinci tarihin Epoch zamani: %ld", e1.epoch);
    printf("\nIkinci tarihin Epoch zamani: %ld", e2.epoch);
    printf("\nZaman fark�: %.0f saniye (%.2f saat)\n", fark, fark / 3600);
    
    return 0;
}


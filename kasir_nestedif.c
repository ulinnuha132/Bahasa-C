#include <stdio.h>

int main() {
    int jumlahBarang;
    float hargaBarang, totalHarga, diskon, totalBayar;

    printf("Masukkan jumlah barang yang dibeli: ");
    scanf("%d", &jumlahBarang);

    printf("Masukkan harga barang per item: ");
    scanf("%f", &hargaBarang);

    totalHarga = jumlahBarang * hargaBarang;

    if (totalHarga >= 1000) {
        diskon = 0.1 * totalHarga;
        totalBayar = totalHarga - diskon;
        printf("Anda mendapatkan diskon 10%%.\n");
    } else {
        diskon = 0;
        totalBayar = totalHarga;
        printf("Maaf, Anda tidak mendapatkan diskon.\n");
    }

    printf("Total harga: %.2f\n", totalHarga);
    printf("Diskon: %.2f\n", diskon);
    printf("Total yang harus dibayar: %.2f\n", totalBayar);

    return 0;
}

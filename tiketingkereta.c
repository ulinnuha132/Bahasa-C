#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ticket {
    char nama[50];
    char tujuan[50];
    int jumlahTiket;
};

void pesanTiket(struct Ticket* tiket) {
    printf("Masukkan Nama: ");
    fgets(tiket->nama, sizeof(tiket->nama), stdin);
    tiket->nama[strcspn(tiket->nama, "\n")] = '\0'; 

    printf("Masukkan Tujuan: ");
    fgets(tiket->tujuan, sizeof(tiket->tujuan), stdin);
    tiket->tujuan[strcspn(tiket->tujuan, "\n")] = '\0';  

    printf("Masukkan Jumlah Tiket: ");
    scanf("%d", &(tiket->jumlahTiket));
    getchar();  

    printf("\nPemesanan Tiket Berhasil!\n");
}

void tampilkanTiket(const struct Ticket* tiket) {
    printf("\nDetail Pemesanan Tiket:\n");
    printf("Nama: %s\n", tiket->nama);
    printf("Tujuan: %s\n", tiket->tujuan);
    printf("Jumlah Tiket: %d\n", tiket->jumlahTiket);
}

int main() {
    struct Ticket tiket;

    printf("== Pemesanan Tiket Kereta ==\n\n");

    pesanTiket(&tiket);

    tampilkanTiket(&tiket);

    return 0;
}

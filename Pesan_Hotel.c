#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Hotel {
    int nomorKamar;
    char nama[50];
    struct Hotel* prev;
    struct Hotel* next;
};

struct Hotel* createNode(int nomorKamar, const char* nama) {
    struct Hotel* newNode = (struct Hotel*)malloc(sizeof(struct Hotel));
    newNode->nomorKamar = nomorKamar;
    strncpy(newNode->nama, nama, sizeof(newNode->nama));
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Hotel** head, int nomorKamar, const char* nama) {
    struct Hotel* newNode = createNode(nomorKamar, nama);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Hotel* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
    printf("Pemesanan kamar dengan nomor %d untuk %s berhasil!\n", nomorKamar, nama);
}

struct Hotel* searchNode(struct Hotel* head, int nomorKamar) {
    struct Hotel* current = head;
    while (current != NULL) {
        if (current->nomorKamar == nomorKamar) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void displayAll(struct Hotel* head) {
    if (head == NULL) {
        printf("Tidak ada pemesanan kamar.\n");
        return;
    }
    printf("Daftar pemesanan kamar:\n");
    struct Hotel* current = head;
    while (current != NULL) {
        printf("Nomor Kamar: %d, Nama: %s\n", current->nomorKamar, current->nama);
        current = current->next;
    }
}

int main() {
    struct Hotel* head = NULL;

    insertNode(&head, 101, "John Doe");
    insertNode(&head, 102, "Jane Smith");
    insertNode(&head, 103, "Michael Johnson");

    displayAll(head);

    int nomorKamar;
    printf("Masukkan nomor kamar yang ingin dicari: ");
    scanf("%d", &nomorKamar);
    struct Hotel* result = searchNode(head, nomorKamar);
    if (result != NULL) {
        printf("Pemesanan kamar dengan nomor %d ditemukan untuk %s.\n", result->nomorKamar, result->nama);
    } else {
        printf("Pemesanan kamar dengan nomor %d tidak ditemukan.\n", nomorKamar);
    }

    return 0;
}

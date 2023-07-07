#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
    printf("Simpul dengan data %d ditambahkan di awal linked list.\n", data);
}

void displayForward(struct Node* head) {
    if (head == NULL) {
        printf("Linked list kosong.\n");
        return;
    }
    printf("Isi linked list dari depan ke belakang: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void displayBackward(struct Node* head) {
    if (head == NULL) {
        printf("Linked list kosong.\n");
        return;
    }
    while (head->next != NULL) {
        head = head->next;
    }
    printf("Isi linked list dari belakang ke depan: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->prev;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 7);
    insertAtBeginning(&head, 9);

    displayForward(head);

    displayBackward(head);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("Failed to allocate memory for a new node");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

struct Node* mergeSortedLinkedList(struct Node* head1, struct Node* head2) {
    struct Node* mergedSortedList = NULL;
    struct Node* current1 = head1;
    struct Node* current2 = head2;
    while (current1 != NULL || current2 != NULL) {
        // pending to check for which is greater and add in ascending order
        if (current1->data <= current2->data) {
            insertAtEnd(&mergedSortedList, current1->data);
            current1 = current1->next;
        } else {
            insertAtEnd(&mergedSortedList, current2->data);
            current2 = current2->next;
        }
    }
    return mergedSortedList;
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void clearMemory(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    int value;

    printf("Enter numbers to add to the first linked list (-1 to exit):\n ");
    while (scanf("%d", &value) == 1 && value != -1) {
        insertAtEnd(&head1, value);
    }

    printf("Enter numbers to add to the second linked list (-1 to exit):\n ");
    while (scanf("%d", &value) == 1 && value != -1) {
        insertAtEnd(&head2, value);
    }

    printf("The first linked-list is:\n");
    printList(head1);
    printf("The second linked-list is:\n");
    printList(head2);

    struct Node* mergedSortedList = mergeSortedLinkedList(head1, head2);
    printf("The merged sorted linked-list is:\n");
    printList(mergedSortedList);

    clearMemory(mergedSortedList); // Free memory of the merged list
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertNode(struct Node** headRef, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *headRef;
    *headRef = newNode;
}

int isSorted(struct Node* head) {
    struct Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->data > current->next->data) {
            return 0; // Not sorted
        }
        current = current->next;
    }
    return 1; // Sorted
}

int main() {
    struct Node* list = NULL;
    int value;

    // Get values from the user
    printf("Enter values for the linked list (enter -1 to end):\n");
    while (1) {
        scanf("%d", &value);
        if (value == -1) {
            break;
        }
        insertNode(&list, value);
    }

    // Check if the linked list is sorted
    if (isSorted(list)) {
        printf("The linked list is sorted.\n");
    } else {
        printf("The linked list is not sorted.\n");
    }

    // Free memory 

    return 0;
}

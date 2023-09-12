#include <stdio.h>
#include <stdlib.h>

// Define a Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a value at the end of the linked list
void insertAtEnd(struct Node** headRef, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // If the list is empty, make the new node the head
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    // Traverse to the last node
    struct Node* current = *headRef;
    while (current->next != NULL) {
        current = current->next;
    }

    // Insert the new node at the end
    current->next = newNode;
}

// Function to delete the last node of the linked list
void deleteAtEnd(struct Node** headRef) {
    if (*headRef == NULL || (*headRef)->next == NULL) {
        // If the list is empty or has only one node, delete the node
        free(*headRef);
        *headRef = NULL;
        return;
    }

    struct Node* current = *headRef;
    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
}

// Function to print the linked list
void printLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL; // Initialize an empty linked list

    // Insert some values at the end
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 7);
    insertAtEnd(&head, 11);

    // Print the linked list
    printf("Linked List after insertions: ");
    printLinkedList(head);

    // Delete the last node
    deleteAtEnd(&head);

    // Print the linked list after deletion
    printf("Linked List after deletion: ");
    printLinkedList(head);

    // Free the allocated memory (not shown in this simple example for brevity)

    return 0;
}

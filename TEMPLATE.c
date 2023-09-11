//header
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//struct for singly linked list.
struct Node {
    int data;
    struct Node* next;
};

//struct for doubly linked list.
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

//createNode for singly linked list
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
// INT MAIN:
int main() {
    struct Node* head = NULL;
    int value;

    printf("Enter numbers to add to the linked list (-1 to exit):\n");
    while (scanf("%d", &value) == 1 && value != -1) {
        head = insertAtEnd(head, value);
    }


//createNode for doubly linked list
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

//INT MAIN:
int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    int n, data;

    // Getting user input for the first list
    printf("Enter the number of elements for list 1: ");
    scanf("%d", &n);
    printf("Enter the elements for list 1: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertEnd(&list1, data);
    }

    // Getting user input for the second list
    printf("Enter the number of elements for list 2: ");
    scanf("%d", &n);
    printf("Enter the elements for list 2: ");
        for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertEnd(&list2, data);
    }
}

//printlist
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

//freememory
void clearMemory(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

// Function to calculate the sum and mean of the linked list
void calculateSumAndMean(struct Node* head) {
    int sum = 0;
    int count = 0;
    struct Node* current = head;

    while (current != NULL) {
        sum += current->data;
        count++;
        current = current->next;
    }

    if (count == 0) {
        printf("The linked list is empty.\n");
    } else {
        float mean = (float)sum / count;
        printf("Sum of the nodes: %d\n", sum);
        printf("Mean of the nodes: %.2f\n", mean);
    }
}
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
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

// Function to insert a node at the end of the linked list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        return head; // Return the head after insertion
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

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free the memory of the linked list
void clearMemory(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int value;

    printf("Enter numbers to add to the linked list (-1 to finish):\n");
    while (scanf("%d", &value) == 1 && value != -1) {
        head = insertAtEnd(head, value);
    }

    printf("The linked-list is:\n");
    printList(head);

    calculateSumAndMean(head);

    clearMemory(head); // Free memory of the list
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int value;
    struct Node* next;
};

int main() {
    // Initialize nodes
    struct Node* head = NULL;
    struct Node* one = NULL;
    struct Node* two = NULL;
    struct Node* three = NULL;

    // Allocate memory
    one = (struct Node*)malloc(sizeof(struct Node));
    two = (struct Node*)malloc(sizeof(struct Node));
    three = (struct Node*)malloc(sizeof(struct Node));

    // Assign value values
    one->value = 1;
    two->value = 2;
    three->value = 3;

    // Connect nodes
    one->next = two;
    two->next = three;
    three->next = NULL;

    // Set head to point to the first node
    head = one;

    // Traverse and print the linked list
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");

    // Free memory (don't forget to do this when you're done with the list)
    free(one);
    free(two);
    free(three);

    return 0;
}

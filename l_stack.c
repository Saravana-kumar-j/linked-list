#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void initialize(struct Stack* stack) {
    stack->top = NULL;
}

int is_empty(struct Stack* stack) {
    return stack->top == NULL;
}

void push(struct Stack* stack, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(struct Stack* stack) {
    if (is_empty(stack)) {
        printf("Stack underflow!\n");
        return -1;
    }
    struct Node* temp = stack->top;
    int value = temp->data;
    stack->top = temp->next;
    free(temp);
    return value;
}

int peek(struct Stack* stack) {
    if (is_empty(stack)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->top->data;
}

void print_stack(struct Stack* stack) {
    if (is_empty(stack)) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack Contents:\n");
    struct Node* current = stack->top;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int main() {
    struct Stack my_stack;
    initialize(&my_stack);

    int choice, value;

    do {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Print Stack\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&my_stack, value);
                break;
            case 2:
                printf("Popped element: %d\n", pop(&my_stack));
                break;
            case 3:
                printf("Top element: %d\n", peek(&my_stack));
                break;
            case 4:
                print_stack(&my_stack);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    // Free allocated memory
    while (my_stack.top != NULL) {
        struct Node* temp = my_stack.top;
        my_stack.top = temp->next;
        free(temp);
    }

    return 0;
}

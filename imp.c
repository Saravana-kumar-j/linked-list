#include <stdio.h>
#define MAX_SIZE 10

struct Stack {
    int items[MAX_SIZE];
    int top;
};

void initialize(struct Stack* stack) {
    stack->top = -1;
}

int is_empty(struct Stack* stack) {
    return stack->top == -1;
}

int is_full(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack* stack, int value) {
    if (!is_full(stack)) {
        stack->items[++stack->top] = value;
    } else {
        printf("Stack overflow!\n");
    }
}

int pop(struct Stack* stack) {
    if (!is_empty(stack)) {
        return stack->items[stack->top--];
    } else {
        printf("Stack underflow!\n");
        return -1;
    }
}

int peek(struct Stack* stack) {
    if (!is_empty(stack)) {
        return stack->items[stack->top];
    } else {
        printf("Stack is empty!\n");
        return -1;
    }
}

void print_stack(struct Stack* stack) {
    if (is_empty(stack)) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack Contents:\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->items[i]);
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

    return 0;
}

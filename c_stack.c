#include <stdio.h>
#include <stdlib.h>

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

int compare_stacks(struct Stack* stack1, struct Stack* stack2) {
    if (stack1->top != stack2->top) {
        return 0;
    }

    for (int i = 0; i <= stack1->top; i++) {
        if (stack1->items[i] != stack2->items[i]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    struct Stack stack1, stack2;
    initialize(&stack1);
    initialize(&stack2);

    int value, num_elements;

    printf("Enter the number of elements for Stack 1: ");
    scanf("%d", &num_elements);
    printf("Enter the elements for Stack 1:\n");
    for (int i = 0; i < num_elements; i++) {
        scanf("%d", &value);
        push(&stack1, value);
    }

    printf("Enter the number of elements for Stack 2: ");
    scanf("%d", &num_elements);
    printf("Enter the elements for Stack 2:\n");
    for (int i = 0; i < num_elements; i++) {
        scanf("%d", &value);
        push(&stack2, value);
    }

    printf("Stack 1:\n");
    print_stack(&stack1);
    printf("\nStack 2:\n");
    print_stack(&stack2);

    if (compare_stacks(&stack1, &stack2)) {
        printf("\nBoth stacks are equal.\n");
    } else {
        printf("\nThe stacks are not equal.\n");
    }

    return 0;
}

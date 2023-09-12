#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node* mergeLists(struct Node* list1, struct Node* list2) {
    struct Node* mergedList = NULL;
    
    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            insertEnd(&mergedList, list1->data);
            list1 = list1->next;
        } else {
            insertEnd(&mergedList, list2->data);
            list2 = list2->next;
        }
    }
    
    while (list1 != NULL) {
        insertEnd(&mergedList, list1->data);
        list1 = list1->next;
    }
    
    while (list2 != NULL) {
        insertEnd(&mergedList, list2->data);
        list2 = list2->next;
    }
    
    return mergedList;
}

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

    struct Node* mergedList = mergeLists(list1, list2);

    printf("Merged List: ");
    printList(mergedList);

    // Free allocated memory
    while (mergedList != NULL) {
        struct Node* temp = mergedList;
        mergedList = mergedList->next;
        free(temp);
    }

    return 0;
}

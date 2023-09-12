#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

//function to print the linked list
void printlinkedlist(struct Node* head){
    printf("List: ");
    struct Node*runner= head;
    while (runner != NULL)
    {
        printf("%d ", runner->data);
        runner = runner->next;
    }
    printf("NULL\n");
}

//function to free the memory.
void freememory(struct Node* head){
    struct Node*current = head;
    while(current != NULL){
        struct Node* next = current->next;
        free(current);
        current= next;
    }
    printf("Memory Freed \n");
    }

int main(){
    struct Node* head = NULL;
    struct Node* temp = NULL;
    int value;

    while (1)
    {
        printf("Enter value (enter -1 as the end value) : ");
        scanf("%d", &value);

        if (value==-1){
            break;
        }

        struct Node* newNode= createNode(value);

        if (head == NULL){
            head = newNode;
            temp = head;
        }else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    //printing linked list

    printlinkedlist(head);

    //Free the allocated mem.
    freememory(head);


    return 0;
    
}

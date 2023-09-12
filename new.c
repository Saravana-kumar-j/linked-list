#include<stdio.h>
#include<stdlib.h>

struct Node{
    int value;
    struct Node* next;
};

int main(){
    struct Node* start = NULL;
    struct Node* a = NULL;
    struct Node* b = NULL;
    struct Node* c = NULL;
    struct Node* d = NULL;
    //memory allocation:
    a= (struct Node*)malloc(sizeof(struct Node));
    b= (struct Node*)malloc(sizeof(struct Node));
    c= (struct Node*)malloc(sizeof(struct Node));
    d= (struct Node*)malloc(sizeof(struct Node));
    //assign values
    a->value = 1;
    b->value = 2;
    c->value = 3;
    d->value = 4;
    //connect nodes
    a->next = (struct Node*)b;
    b->next = (struct Node*)c;
    c->next = (struct Node*)d;
    d->next = NULL;

    //set start to poin the first node.
    start = a;
    //traverse and print the linked list
    struct Node* i = start;
    while(i != NULL){
        printf("%d ", i->value);
        i=i->next;}
    
    //Free the memory
    free(a);
    free(b);
    free(c);
    free(d);

    return 0;
}
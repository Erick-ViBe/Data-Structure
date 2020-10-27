#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct node;

bool is_empty(struct node *n);
void push(struct node **n, int data);
void pop(struct node **n);
void show_stack(struct node *n);
int top(struct node *n);
int stack_size(struct node *n);

int main(void){
	struct node* stack=NULL;

	push(&stack, 1);
	push(&stack, 2);

	pop(&stack);

    printf("Stack Top: %d\n", top(stack));

	push(&stack, 3);

	show_stack(stack);

    printf("Stack Length: %d\n", stack_size(stack));

	return 0;
}

struct node{
    int data;
    struct node *next;
};

bool is_empty(struct node *n){
    return (n == NULL);
}

void push(struct node **n, int data){
    struct node* new = malloc(sizeof(struct node));

    new->data = data;
    new->next = *n;

    *n = new;
}

void pop(struct node **n){
    if(!is_empty(*n)){
        struct node* deleted_node = *n;
        *n = (*n)->next; 
        free(deleted_node);
    }else{
        printf("The Stack is already empty\n");
    }
}

void show_stack(struct node *n){
    printf("-\n");
    while(n != NULL){
        printf("%d\n", n->data);

        n = n->next;
    }
    printf("-\n");
}

int top(struct node *n){

    if(!is_empty(n)){
		return n->data;
    }else{
        printf("The Stack is already empty\n");
		return 0;
    }
}

int stack_size(struct node *n){
    int l=0;

    while(n != NULL){
        l++;
        n = n->next;
    }

    return l;
}

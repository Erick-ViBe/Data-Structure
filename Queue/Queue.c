#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct node;

bool is_empty(struct node *n);
void push(struct node **n, int data);
void pop(struct node **n);
void show_queue(struct node *n);
int front(struct node *n);
int back(struct node *n);
int queue_size(struct node *n);

int main(void){
	struct node* queue=NULL;

	push(&queue, 66);
	push(&queue, 11);
	push(&queue, 22);
	push(&queue, 33);
	push(&queue, 44);
	push(&queue, 55);

	pop(&queue);

	printf("-\n");
	show_queue(queue);
	printf("-\n");

    printf("Queue Front: %d\n", front(queue));

    printf("Queue Back: %d\n", back(queue));

    printf("Queue Length: %d\n", queue_size(queue));

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
        if((*n)->next == NULL){
			struct node* deleted_node = *n;
			*n = (*n)->next; 
			free(deleted_node);
        }else{
            struct node* previous;
            struct node* linked_list = *n;

            while(linked_list->next != NULL){
                previous = linked_list;
                linked_list = linked_list->next;
            }

            previous->next = NULL;

            free(linked_list);
        }
    }else{
        printf("The Linked List is already empty\n");
    }
}

void show_queue(struct node *n){
    if(n != NULL){
        if(n->next != NULL){
            show_queue(n->next);
            printf("%d\n", n->data);
        }else{
            printf("%d\n", n->data);
        }
    }
}

int front(struct node *n){
    if(!is_empty(n)){
		while(n->next != NULL){
			n = n->next;
		}
		return n->data;
    }else{
        printf("The Linked List is already empty\n");
		return 0;
    }
}

int back(struct node *n){
    if(!is_empty(n)){
		return n->data;
    }else{
        printf("The Linked List is already empty\n");
		return 0;
    }
}

int queue_size(struct node *n){
    int l=0;

    while(n != NULL){
        l++;
        n = n->next;
    }

    return l;
}

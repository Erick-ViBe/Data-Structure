#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct node;
bool is_empty(struct node *n);
void insert_at_start(struct node **n, int data);
void delete_data(struct node *n, int data_to_delete);
void delete_front(struct node **n);
void show_linked_list(struct node *n);
int length_listed_list(struct node *n);

int main(void){
    struct node* linked_list=NULL;

    insert_at_start(&linked_list, 5);
    insert_at_start(&linked_list, 4);
    insert_at_start(&linked_list, 3);
    insert_at_start(&linked_list, 2);
    insert_at_start(&linked_list, 1);

    delete_front(&linked_list);
    delete_data(linked_list, 5);

    show_linked_list(linked_list);

    delete_data(linked_list, 5);

    show_linked_list(linked_list);

    printf("Linked List Length: %d\n", length_listed_list(linked_list));

    return 0;
}

struct node{
    int data;
    struct node *next;
};

bool is_empty(struct node *n){
    return (n == NULL);
}

void insert_at_start(struct node **n, int data){
    struct node* new = malloc(sizeof(struct node));

    new->data = data;
    new->next = *n;

    *n = new;
}

void delete_front(struct node **n){
    struct node* deleted_node = *n;
    if(!is_empty(*n)){
        *n = (*n)->next; 
        free(deleted_node);
    }else{
        printf("The Linked List is already empty\n");
    }
}

void delete_data(struct node *n, int data_to_delete){
    struct node* previous;
    struct node* linked_list = n;
    
    while(n->data != data_to_delete && n->next != NULL){
        previous = n;
        n = n->next;
    }

    if(n->data == data_to_delete){
        if(linked_list == n){
            *n = *n->next;
        }else{
            previous->next = n->next;
            free(n);
        }
    }else{
        printf("The data provided not already exist in the linked list\n");
    }
}

void show_linked_list(struct node *n){
    printf("-\n");
    while(n != NULL){
        printf("%d\n", n->data);

        n = n->next;
    }
    printf("-\n");
}

int length_listed_list(struct node *n){
    int l=0;

    while(n != NULL){
        l++;
        n = n->next;
    }

    return l;
}

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct node;

bool is_empty(struct node *n);
void insert_at_start(struct node **n, int data);
void insert_at_the_end(struct node **n, int data);
void delete_front(struct node **n);
void delete_end(struct node **n);
void delete_data(struct node **n, int data_to_delete);
void show_linked_list(struct node *n);
void recursion_reverse_show_linked_list(struct node *n);
void reverse_show_linked_list(struct node *n);
int length_listed_list(struct node *n);

int main(void){
    struct node* linked_list=NULL;

    insert_at_start(&linked_list, 4);
    insert_at_start(&linked_list, 3);
    insert_at_start(&linked_list, 2);
    insert_at_start(&linked_list, 1);

    insert_at_the_end(&linked_list, 5);

    delete_front(&linked_list);

    delete_end(&linked_list);

    delete_data(&linked_list, 3);

    show_linked_list(linked_list);

    reverse_show_linked_list(linked_list);

    printf("Double Linked List Length: %d\n", length_listed_list(linked_list));

    return 0;
}

struct node{
    int data;
    struct node *next;
    struct node *previous;
};

bool is_empty(struct node *n){
    return (n == NULL);
}

void insert_at_start(struct node **n, int data){
    struct node* new = malloc(sizeof(struct node));

    new->data = data;
    new->previous = NULL;
    new->next = *n;

    if(*n != NULL){
        (*n)->previous = new;
    }

    *n = new;
}

void insert_at_the_end(struct node **n, int data){
    struct node* linked_list = *n;
    struct node* new = malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;

    if(!is_empty(linked_list)){
        struct node* previous;

        while(linked_list != NULL){
            previous = linked_list;
            linked_list = linked_list->next;
        }

        previous->next = new;
        new->previous = previous;
    }else{
        new->previous = NULL;
        *n = new;
    }
}

void delete_front(struct node **n){
    if(!is_empty(*n)){
        struct node* deleted_node = *n;
        *n = (*n)->next;
        if(*n != NULL){
            (*n)->previous = NULL;
        }
        free(deleted_node);
    }else{
        printf("The Double Linked List is already empty\n");
    }
}

void delete_end(struct node **n){
    if(!is_empty(*n)){
        if((*n)->next == NULL){
            delete_front(n);
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
        printf("The Double Linked List is already empty\n");
    }
}

void delete_data(struct node **n, int data_to_delete){
    if(!is_empty(*n)){
        if((*n)->data == data_to_delete){
            delete_front(n);
        }else{
            struct node* linked_list = *n;

            while(linked_list->next !=NULL && linked_list->data != data_to_delete){
                linked_list = linked_list->next;
            }

            if(linked_list->data == data_to_delete){
                if(linked_list->previous != NULL){
                    linked_list->previous->next = linked_list->next;
                }
                if(linked_list->next != NULL){
                    linked_list->next->previous = linked_list->previous;
                }
                free(linked_list);
            }else{
                printf("The data provided not already exist in the double linked list\n");
            }
        } 
    }else{
        printf("The Double Linked List is already empty\n");
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

void recursion_reverse_show_linked_list(struct node *n){
    if(n != NULL){
        if(n->next != NULL){
            recursion_reverse_show_linked_list(n->next);
            printf("%d\n", n->data);
        }else{
            printf("%d\n", n->data);
        }
    }
}

void reverse_show_linked_list(struct node *n){
    struct node* previous;

    while(n != NULL){
        previous = n;
        n = n->next;
    }

    n = previous;

    printf("-\n");
    while(n != NULL){
        printf("%d\n", n->data);
        n = n->previous;
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

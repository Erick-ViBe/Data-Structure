#include <cstddef>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node;

void insert(struct node **root, int data);
bool elementIn(struct node *root, int data_to_search);
/*void delete(struct node **root, int data_to_delete);*/
void show(struct node *root);

int main(void){
	struct node *bst = NULL;

	insert(&bst, 4);
	insert(&bst, 8);
	insert(&bst, 5);

	insert(&bst, 6);
	insert(&bst, 2);
	insert(&bst, 7);

	insert(&bst, 1);
	insert(&bst, 3);
	insert(&bst, 9);

	printf("+\n");
	printf("%d\n", elementIn(bst, 5));
	printf("+\n");

	printf("+\n");
	printf("%d\n", elementIn(bst, 111));
	printf("+\n");

	printf("-\n");
	show(bst);
	printf("-\n");

	return 0;
}

struct node{
	int data;
	struct node *rigth_child;
	struct node *left_child;
};

void insert(struct node **root, int data){
	if(*root == NULL){
		struct node* new = malloc(sizeof(struct node));
		new->data = data;
		new->rigth_child = NULL;
		new->left_child = NULL;

		*root = new;
	}else{
		if((*root)->data == data){
			printf("%d is already in the tree\n", data);
		}else{
			if(data > (*root)->data){
				insert(&(*root)->rigth_child, data);
			}else{
				insert(&(*root)->left_child, data);
			}
		}
	}
}

bool elementIn(struct node *root, int data_to_search){
	if(root == NULL){
		return false;
	}else if(root->data == data_to_search){
		return true;
	}else if(data_to_search < root->data){
		return elementIn(root->left_child, data_to_search);
	}else{
		return elementIn(root->rigth_child, data_to_search);
	}
}

void delete(struct node **root, int data_to_delete){
	struct node *bst = *root;
	struct node *previous = NULL;
	struct node *tmp = NULL;

	int data_temp;
	
	while(bst != NULL){
		if(bst->data == data_to_delete){
			if(previous == NULL){
				if(bst->rigth_child != NULL){
					if(bst->rigth_child->left_child != NULL){
						data_temp = bst->rigth_child->left_child->data;
					}
					bst->rigth_child->left_child = bst->left_child;
					*root = bst->rigth_child;
					if(tmp != NULL){
						insert(root, data_temp);
					}
					free(bst);
				}else if(bst->left_child != NULL){
					tmp = bst;
					*root = bst->left_child;
					free(tmp);
				}else{
					tmp = bst;
					*root = NULL;
					free(tmp);
				}
			}
		}
	}
}

void show(struct node *root){
	if(root == NULL){
		return;
	}

	show(root->left_child);
	printf("%d\n", root->data);
	show(root->rigth_child);
}

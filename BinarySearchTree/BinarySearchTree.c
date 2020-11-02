#include <stdio.h>
#include <stdlib.h>

struct node;

void insert(struct node **root, int data);
void insert(struct node **root, int data);
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

void show(struct node *root){
	if(root == NULL){
		return;
	}

	show(root->left_child);
	printf("%d\n", root->data);
	show(root->rigth_child);
}

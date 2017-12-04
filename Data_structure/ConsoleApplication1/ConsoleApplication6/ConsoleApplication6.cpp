#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node
{
	struct node *left;
	struct node *right;
	char data;
};

struct node *tree(int);
void inorder(struct node *);

char array[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', '\0', '\0', 'H' };
int leftcount[] = { 1,   3,   5,   -1,   9,  -1,  -1,   -1,   -1,  -1 };
int rightcount[] = { 2,   4,   6,   -1,  -1,  -1,  -1,   -1,   -1,  -1 };

void main()
{
	struct node *root;
	root = tree(0);
	printf("in order travarsal : \n");
	inorder(root);
	_getch();
}

struct  node *tree(int index)
{
	struct node *temp = NULL;
	if (index != -1)
	{
		temp = (struct node *)malloc(sizeof(struct node));
		temp->left = tree(leftcount[index]);
		temp->data = array[index];
		temp->right = tree(rightcount[index]);
	}
	return temp;
}
void inorder(struct node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%c\t",root->data);
		inorder(root->right);
	}
}

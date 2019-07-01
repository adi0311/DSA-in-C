#include<stdio.h>
#include<stdlib.h>
#define True 1
#define False 0

struct Node* insert(struct Node*, int);
int balanceFactor(struct Node*);
int max(int, int);
void inorder(struct Node*);

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
	int height;
};

int main()
{
	int choice, value, condition = True;
	struct Node* root = (struct Node*)malloc(sizeof(struct Node));
	root = NULL;
	while(condition)
	{
		printf("Enter :-\n1. To insert a node.\n2. To print the content of the AVL tree in inorder.\n3. To exit.\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Enter the value you want to enter.\n");
				scanf("%d", &value);
				root = insert(root, value);
				break;
			case 2:
				printf("Inorder Traversal:\n");
				inorder(root);
				break;
			case 3:
				condition = False;
				break;
			default:
				printf("Enter a valid number between 1 and 3.\n");
				break;
		}
	}
	return 0;
}

int max(int a, int b)
{
	if(a > b)
		return a;
	else
		return b;
}

int height(struct Node*);

int height(struct Node* root)
{
	if(root == NULL)
		return 0;
	return root -> height;
}

struct Node* newNode(int value)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp -> data = value;
	temp -> left = NULL;
	temp -> right = NULL;
	temp -> height = 1;
}

struct Node* rightrotate(struct Node* x)
{
	struct Node* y = x -> right;
	struct Node* T3 = y -> left;

	y -> left = x;
	x -> right = T3;

	x -> height = max(height(x -> left), height(x -> right));
	y -> height = max(height(y -> left), height(y -> right));

	return y;
}

struct Node* leftrotate(struct Node* x)
{
	struct Node* y = x -> left;
	struct Node* T2 = y -> right;

	y -> right = x;
	x -> left = T2;

	x -> height = max(height(x -> left), height(x -> right));
	y -> height = max(height(y -> left), height(y -> right));

	return y;
}

int balancefactor(struct Node* root)
{
	return height(root -> left)-height(root -> right);
}

struct Node* insert(struct Node* root, int value)
{
	if(root == NULL)
	{
		root = newNode(value);
		return root;
	}
	if(value > root -> data)
		root -> right = insert(root -> right, value);
	if(value < root -> data)
		root -> left = insert(root -> left, value);
	else
		return root;
	root -> height = 1 + max(height(root -> left), height(root -> right));
	int bf = balancefactor(root);
	if(bf > 1 && value < root -> left -> data)
		root = leftrotate(root);
	if(bf > 1 && value > root -> left -> data)
	{
		root -> left = rightrotate(root -> left);
		root = leftrotate(root);
	}
	if(bf < -1 && value > root -> right -> data)
		root = rightrotate(root);
	if(bf < -1 && value < root -> right -> data)
	{
		root -> right = leftrotate(root -> right);
		root = rightrotate(root);
	}
	return root;
}

void inorder(struct Node* root)
{
	if(root != NULL)
	{
		inorder(root -> left);
		printf("%d\n", root -> data);
		inorder(root -> right);
	}
}

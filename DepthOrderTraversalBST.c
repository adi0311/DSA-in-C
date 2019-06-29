#include<stdio.h>
#include<stdlib.h>
#define True 1
#define False 0

struct Node* newNode(int);
struct Node* insert(struct Node*, int);
void levelorder(struct Node*);
struct Queue* pop(struct Queue*);
struct Queue* push(struct Queue*, struct Node*);
int empty(struct Queue*);
struct Node* top(struct Queue*);

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Queue
{
	struct Node* key;
	struct Queue* next;
};
int main()
{
	struct Node* root = (struct Node*)malloc(sizeof(struct Node));
	root = NULL;
	int value, condition = True, choice;
	while(condition)
	{
		printf("Enter :-\n1. To insert a new node.\n2. To print the level order traversal of the tree.\n3. To exit.\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Enter the node you want to insert.\n");
				scanf("%d", &value);
				root = insert(root, value);
				break;
			case 2:
				printf("The levelorder traversal is:\n");
				levelorder(root);
				break;
			case 3:
				condition = False;
				break;
			default:
				printf("Enter a vaid number between 1 and 3.\n");
				break;
		}
	}
	return 0;
}
struct Node* newNode(int value)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp -> data = value;
	temp -> left = NULL;
	temp -> right = NULL;
	return temp;
}
struct Node* insert(struct Node* root, int value)
{
	if(root == NULL)
		return newNode(value);
	if(value > root -> data)
		root -> right = insert(root -> right, value);
	else if(value < root -> data)
		root -> left = insert(root -> left, value);
	else
		printf("The value is already exists!\n");
	return root;
}
void levelorder(struct Node* root)
{
	if(root != NULL)
	{
		struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
		queue = NULL;
		queue = push(queue, root);
		while(!empty(queue))
		{
			struct Node* k = top(queue);
			printf("%d\n", k -> data);
			if(k -> left != NULL)
				queue = push(queue, k -> left);
			if(k -> right != NULL)
				queue = push(queue, k -> right);
			queue = pop(queue);
		}
	}
	else
		printf("The tree is empty.\n");
}
struct Queue* push(struct Queue* queue, struct Node* value)
{
	struct Queue* temp = (struct Queue*)malloc(sizeof(struct Queue));
	temp -> key = value;
	temp -> next = NULL;
	if(queue == NULL)
		queue = temp;
	else
	{
		struct Queue* pre = (struct Queue*)malloc(sizeof(struct Queue*));
		pre = queue;
		while(pre -> next != NULL)
			pre = pre -> next;
		pre -> next = temp;
	}
	return queue;
}
int empty(struct Queue* queue)
{
	if(queue == NULL)
		return True;
	else
		return False;
}

struct Node* top(struct Queue* queue)
{
	return queue -> key;
}
struct Queue* pop(struct Queue* queue)
{
	if(queue == NULL)
		return queue;
	else
	{
		struct Node* value = queue -> key;
		struct Queue* temp = (struct Queue*)malloc(sizeof(struct Queue));
		temp = queue;
		queue = queue -> next;
		free(temp);
		return queue;
	}
}

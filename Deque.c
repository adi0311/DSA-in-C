#include<stdio.h>
#include<stdlib.h>
#define True 1
#define False 0

struct Node* newNode(int);
void pushFront(int);
void pushBack(int);
void popFront();
void popBack();
int size();
void print();
int isEmpty();

struct Node
{
	int data;
	struct Node* next;
} *head;

int main()
{
	head = NULL;
	int value, choice, condition = True;
	while(condition)
	{
		printf("Enter :-\n1. To insert at the beginning.\n2. To insert at the end.\n3. To delete the first node.\n4. To delete the last node.\n5. To print the size.\n6.To print the content of dequeue.\n7. To exit.\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Enter the node you want to insert.\n");
				scanf("%d", &value);
				pushFront(value);
				break;
			case 2:
				printf("Enter the node you want to insert.\n");
				scanf("%d", &value);
				pushBack(value);
				break;
			case 3:
				popFront();
				break;
			case 4:
				popBack();
				break;
			case 5:
				printf("%d\n", size());
				break;
			case 6:
				print();
				break;
			case 7:
				condition = False;
				break;
			default:
				printf("Invalid Choice!!\n");
				break;
		}
	}
	return 0;
}
struct Node* newNode(int value)
{
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n -> data = value;
	n -> next = NULL;
	return n;
}
void pushFront(int value)
{
	if(head == NULL)
		head = newNode(value);
	else
	{
		struct Node* n = (struct Node*)malloc(sizeof(struct Node));
		n -> data = value;
		n -> next = head;
		head = n;
	}
}
void pushBack(int value)
{
	if(head == NULL)
		head = newNode(value);
	else
	{
		struct Node* n = (struct Node*)malloc(sizeof(struct Node));
		n -> data = value;
		struct Node* pre = head;
		for(int i = 1; i < size(); i++)
		{
			pre = pre -> next;
		}
		pre -> next = n;
		n -> next = NULL;
	}
}
int isEmpty()
{
	if(size() == 0)
		return True;
	else
		return False;
}
void popFront()
{
	if(isEmpty())
		printf("Dequeue is already empty.\n");
	else if(size() == 1)
		head = NULL;
	else
	{
		struct Node* temp = head;
		head = head -> next;
		temp = NULL;
		free(temp);
	}
}
void popBack()
{
	if(size() == 0)
		printf("Dequeue is already empty.\n");
	else if(size() == 1)
		head = NULL;
	else
	{
		struct Node* temp = head;
		struct Node* pre = (struct Node*)malloc(sizeof(struct Node));
		for(int i = 1; i < size(); i++)
		{
			pre = temp;
			temp = temp -> next;
		}
		pre -> next = NULL;
		free(temp);
	}
}
int size()
{
	struct Node* temp = head;
	int ctr = 0;
	while(temp)
	{
		ctr++;
		temp = temp -> next;
	}
	return ctr;
}
void print()
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp = head;
	while(temp)
	{
		printf("%d ", temp -> data);
		temp = temp -> next;
	}
	printf("\n");
}

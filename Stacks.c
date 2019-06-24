#include<stdio.h>
#include<stdlib.h>
#define True 1
#define False 0

struct Node* newNode(int);
void push(int);
void pop();
int top();
int size();
int isEmpty();
void print();

struct Node
{
	int data;
	struct Node* next;
} *head;

int main()
{
	head = NULL;
	int choice, condition = True, value;
	while(condition)
	{
		printf("Enter :-\n1. To push an element to the stack\n2. To pop an element from the stack.\n3. To print the size of the stack.\n4. To get the top element.\n5. To print the stack content.\n6. To exit.\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Enter the number you want to push.\n");
				scanf("%d", &value);
				push(value);
				break;
			case 2:
				pop();
				break;
			case 3:
				printf("%d\n", size());
				break;
			case 4:
				printf("%d\n", top());
				break;
			case 5:
				printf("The content of stack is: \n");
				print();
				break;
			case 6:
				condition = False;
				break;
			default:
				printf("Wrong choice :-(.\nChoose something between 1 and 6 :-)\n");
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
void push(int value)
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
int size()
{
	struct Node* temp = head;
	int ctr = 0;
	while(temp)
	{
		temp = temp -> next;
		ctr++;
	}
	return ctr;
}
int isEmpty()
{
	if(size() == 0)
		return True;
	else
		return False;
}
void pop()
{
	if(isEmpty())
		printf("Stack is Empty\n");
	else if(size() == 1)
		head = NULL;
	else
	{
		struct Node* temp = head;
		head = temp -> next;
		temp = NULL;
		free(temp);
	}
}
int top()
{
	return head -> data;
}
void print()
{
	struct Node* temp = head;
	while(temp)
	{
		printf("%d -> ", temp -> data);
		temp = temp -> next;
	}
	printf("\n");
}

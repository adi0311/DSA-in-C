#include<stdio.h>
#include<stdlib.h>
#define True 1
#define False 0

struct Node* newNode(int);
int size();
int top();
void push(int);
void pop();
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
	int value, choice, condition = True;
	while(condition)
	{
		printf("Enter:-\n1. To push a node.\n2. To pop a node.\n3. To get the top element.\n4. To get size of queue.\n5. To print the queue.\n6. To exit.\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Enter the value you want to insert\n");
				scanf("%d", &value);
				push(value);
				break;
			case 2:
			    	pop();
				break;
			case 3:
				printf("%d   \n", top());
				break;
			case 4:
				printf("%d   \n", size());
				break;
			case 5:
				print();
				break;
			case 6:
				condition = False;
				break;
			default:
				printf("You made a wrong choice!!\n");
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
	{
		head = newNode(value);
	}
	else
	{
        	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
        	n -> data = value;
        	n -> next = head;
        	head = n;
	}
}
int top()
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp = head;
    for(int i = 1; i < size(); i++)
    {
        temp = temp -> next;
    }
    return temp -> data;
}
void pop()
{
    if(isEmpty())
        printf("The queue is empty.\n");
    else if(size() == 1)
	    head = NULL;
    else
    {
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp = head;
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
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp = head;
    int ctr = 0;
    while(temp)
    {
        ctr++;
        temp = temp -> next;
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
void print()
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp = head;
	while(temp)
	{
		printf("%d <- ", temp -> data);
		temp = temp -> next;
	}
	printf("\n");
}

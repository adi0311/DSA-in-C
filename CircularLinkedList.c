#include<stdio.h>
#include<stdlib.h>
#define True 1
#define False 0

struct Node* newNode(int);
void insertFirst(int);
void insertLast(int);
void insertParticular(int, int);
void deleteFirst();
void deleteLast();
void deleteParticular(int);
int size();
void print();

struct Node
{
	int data;
	struct Node* next;
} *rear, *head;

int main()
{
	int value, position, condition = True, choice;
	rear = NULL;
	head = NULL;
	while(condition)
	{
		printf("Enter :-\n1. To insert at the beginning of the list.\n2. To insert at the end of the list.\n3. To insert at a particular position.\n4. To delete the first node.\n5. To delete the last node.\n6. To delete a node from a particular position.\n7. To print the size of the list.\n8. To print the list.\n9. To exit.\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Enter the node you want to insert:\n");
				scanf("%d", &value);
				insertFirst(value);
				break;
			case 2:
				printf("Enter the node you want to insert: \n");
				scanf("%d", &value);
				insertLast(value);
				break;
			case 3:
				printf("Enter the node you want to insert:\n");
				scanf("%d", &value);
				printf("Enter a valid position between %d and %d(included).\n", 1, size()+1);
				scanf("%d", &position);
				insertParticular(value, position);
				break;
			case 4:
				deleteFirst();
				break;
			case 5:
				deleteLast();
				break;
			case 6:
				printf("Entee a valid position between %d and %d(included).\n", 1, size());
				scanf("%d", &position);
				break;
			case 7:
				printf("%d\n", size());
				break;
			case 8:
				print();
				break;
			case 9:
				condition = False;
				break;
			default:
				printf("Try Again!!\nEnter a valid position between 1 and 9.\n");
				break;
		}
	}
	return 0;
}
struct Node* newNode(int value)
{
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n -> data = value;
	n -> next = n;
}
void insertFirst(int value)
{
	if(rear == NULL)
	{
		rear = newNode(value);
	}
	else
	{
		struct Node* n = (struct Node*)malloc(sizeof(struct Node));
		n -> data = value;
		struct Node* temp = rear;
		n -> next = temp -> next;
		rear -> next = n;
	}
}
void insertLast(int value)
{
	if(rear == NULL)
	{
		rear = newNode(value);
	}
	else
	{
		struct Node* n = (struct Node*)malloc(sizeof(struct Node));
		n -> data = value;
		n -> next = rear -> next;
		rear -> next = n;
		rear = n;
	}
}
void insertParticular(int value, int position)
{
	if(position == 1)
		insertFirst(value);
	else if(position == size()+1)
		insertLast(value);
	else if(position > size()+1)
		printf("Invalid Position\n");
	else
	{
		struct Node* n = (struct Node*)malloc(sizeof(struct Node));
		n -> data = value;
		struct Node* temp = rear;
		for(int i = 1; i < position; i++)
		{
			temp = temp -> next;
		}
		n -> next = temp -> next;
		temp -> next = n;
	}
}
void deleteFirst()
{
	if(size() == 0)
		printf("Empty List.\n");
	else if(size() == 1)
		rear = NULL;
	else
	{
		struct Node* temp = rear;
		temp = temp -> next;
		rear -> next = rear -> next -> next;
		free(temp);
	}
}
void deleteLast()
{
	if(size() == 0)
		printf("Empty List!!\n");
	else if(size() == 1)
		rear = NULL;
	else
	{
		struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
		temp = rear;
		for(int i = 1; i < size(); i++)
		{
			temp = temp -> next;
		}
		temp -> next = rear -> next;
		rear = NULL;
		free(rear);
		rear = temp;
	}
}
void deletParticular(int position)
{
	if(position == 1)
		deleteFirst();
	else if(position == size())
		deleteLast();
	else if(position > size())
		printf("Invalid Position.\n");
	else
	{
		struct Node* temp = rear;
		struct Node* pre = (struct Node*)malloc(sizeof(struct Node));
		for(int i = 0; i < position; i++)
		{
			temp = temp -> next;
		}
		pre = temp -> next;
		temp -> next = pre -> next;
		free(pre);
	}
}
int size()
{
	if(rear == NULL)
		return 0;
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp = rear -> next;
	int ctr = 1;
	while(temp != rear)
	{
		temp = temp -> next;
		ctr++;
	}
	return ctr;
}
void print()
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp = rear -> next;
	while(temp != rear)
	{
		printf("%d ", temp -> data);
		temp = temp -> next;
	}
	printf("%d \n", rear -> data);
}

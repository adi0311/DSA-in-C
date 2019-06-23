#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
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
void printForward();
void printBackward();

struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;
} *head, *tail;

int main()
{
	head = NULL;
	tail = NULL;
	int choice, value, position, condition = True;
	while(condition)
	{
		printf("Enter:\n1. To insert a node at the beginning of list\n2. To insert a node at the end of list\n3. To insert a node at a particular position\n4. To delete a node from the beginning of the list\n5. To delete a node from the end of list.\n6. To delete from a particular position\n7. To display the size of list.\n8. To print the list forward.\n9. To print the list backward.\n 10. To exit.\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Enter the value you want to insert.\n");
				scanf("%d", &value);
				insertFirst(value);
				break;
			case 2:
				printf("Enter the value you want to insert.\n");
				scanf("%d", &value);
				insertLast(value);
				break;
			case 3:
				printf("Enter the value you want to insert.\n");
				scanf("%d", &value);
				printf("Enter the position, a number between %d and %d (included)the position where you want to insert %d\n", 1, size(), value);
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
				printf("Enter the position, a number between %d and %d(included) where you want to delete a node\n", 1, size());
				scanf("%d", &position);
				deleteParticular(position);
				break;
			case 7:
				printf("The size of the list is: %d\n", size());
				break;
			case 8:
				printForward();
				break;
			case 9:
				printBackward();
				break;
			case 10:
				condition = False;
				break;
			default:
				printf("You made a wrong choice\n");
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
	n -> prev = NULL;
	return n;
}
void insertFirst(int value)
{
	if(head == NULL)
	{
		head = newNode(value);
		tail = newNode(value);
		head -> next = tail;
		tail -> prev = head;
		deleteFirst();
	}
	else
	{
		struct Node* n = (struct Node*)malloc(sizeof(struct Node));
		n -> data = value;
		n -> prev = NULL;
		n -> next = head;
		head -> prev = n;
		head = n;
	}
}
void insertLast(int value)
{
	if(head == NULL)
	{
		head = newNode(value);
		tail = newNode(value);
		head -> next = tail;
		tail -> prev = head;
		deleteFirst();
	}
	else
	{
		struct Node* n = (struct Node*)malloc(sizeof(struct Node));
		n -> data = value;
		n -> next = NULL;
		tail -> next = n;
		n -> prev = tail;
		tail = n;
	}
}
void insertParticular(int value, int position)
{
	if(position > size())
		printf("Invalid position\n");
	else
	{
		struct Node* n = (struct Node*)malloc(sizeof(struct Node));
		n -> data = value;
		struct Node* temp = head;
		for(int i = 1; i < position; i++)
		{
			temp = temp -> next;
		}
		struct Node* pre = temp -> prev;
		pre -> next = n;
		n -> prev = pre;
		n -> next = temp;
		temp -> prev = n;
	}
}
void deleteFirst()
{
	if(head == NULL)
		printf("List is empty\n");
	else
	{
		struct Node* temp = head;
		head = temp -> next;
		head -> prev = NULL;
		free(temp);
		if(size() == 0)
			tail = NULL;
	}
}
void deleteLast()
{
	if(head == NULL)
		printf("List is empty\n");
	else
	{
		struct Node* temp = tail;
		tail = temp -> prev;
		tail -> next = NULL;
		free(temp);
		if(size() == 0)
			head = NULL;
	}
}
void deleteParticular(int position)
{
	if(position > size())
		printf("Invalid choice.\n");
	else if(head == NULL)
		printf("List is already empty!\n");
	else if(position == 1)
		deleteFirst();
	else if(position == size())
		deleteLast();
	else
	{
		struct Node* temp = head;
		for(int i = 1; i < position; i++)
			temp = temp -> next;
		struct Node* pre = temp -> prev;
		pre -> next = temp -> next;
		temp -> next -> prev = pre;
		free(temp);
	}
}
void printForward()
{
	struct Node* temp = head;
	while(temp)
	{
		printf("%d ", temp -> data);
		temp = temp -> next;
	}
	printf("\n");
}
void printBackward()
{
	struct Node* temp = tail;
	while(temp)
	{
		printf("%d ", temp -> data);
		temp = temp -> prev;
	}
	printf("\n");
}
int size()
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp = head;
	int ctr = 0;
	while(temp)
	{
		temp = temp -> next;
		ctr++;
	}
	return ctr;
}

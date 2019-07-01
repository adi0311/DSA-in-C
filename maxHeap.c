#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define True 1
#define False 0

int parent(int);
int leftChild(int);
int rightChild(int);
void insert(int*, int, int);
void deleteKey(int*, int);
void Heapify(int*, int);
int maxElement(int*);
int extractMax(int*);
void swap(int*, int*);
void increaseKey(int*, int, int);

int heapSize = 0;

int main()
{
	int choice, condition = True, value, i, capacity;
	printf("Enter the capacity of the heap.\n");
	scanf("%d", &capacity);
	int* heap = (int*)malloc(sizeof(int));
	while(condition)
	{
		printf("Enter :-\n1. To insert an element.\n2. To delete a element.\n3. To get the largest element.\n4. To delete the largest element.\n5. To print the heap content.\n6. To exit.\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Enter the element you want to insert.\n");
				scanf("%d", &value);
				insert(heap, value, capacity);
				break;
			case 2:
				printf("Enter the index of the element you want to delete\n");
				scanf("%d", &value);
				deleteKey(heap, value);
				break;
			case 3:
				printf("Maximum element: %d\n", maxElement(heap));
				break;
			case 4:
				extractMax(heap);
				break;
			case 5:
				for(i = 0; i < heapSize; i++)
					printf("%d\n", heap[i]);
				break;
			case 6:
				condition = False;
				break;
			default:
				printf("Enter a valid choice between 1 and 6.\n");
				break;
		}
	}
	return 0;
}

int parent(int i)
{
	return (i-1)/2;
}

int leftChild(int i)
{
	return 2*i+1;
}

int rightChild(int i)
{
	return 2*i+2;
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void insert(int* arr, int value, int capacity)
{
	if(heapSize == capacity)
	{
		printf("Heap Overflow.\n");
		return;
	}
	heapSize++;
	int i = heapSize - 1;
	arr[i] = value;
	while(i != 0 && arr[parent(i)] < arr[i])
	{
		swap(&arr[parent(i)], &arr[i]);
		i = parent(i);
	}
}

int maxElement(int* arr)
{
	return arr[0];
}

void increaseKey(int* arr, int i, int value)
{
	arr[i] = value;
	while(i != 0 && arr[parent(i)] < arr[i])
	{
		swap(&arr[parent(i)], &arr[i]);
		i = parent(i);
	}
}

void Heapify(int* arr, int i)
{
	int l = leftChild(i);
	int r = rightChild(i);
	int largest = i;
	if(l < heapSize && arr[l] > arr[largest])
		largest = l;
	if(r < heapSize && arr[r] > arr[largest])
		largest = r;
	if(i != largest)
	{
		swap(&arr[i], &arr[largest]);
		Heapify(arr, largest);
	}
}

int extractMax(int* arr)
{
	if(heapSize == 0)
		return INT_MIN;
	if(heapSize == 1)
	{
		heapSize--;
		return arr[0];
	}
	arr[0] = arr[heapSize-1];
	heapSize--;
	Heapify(arr, 0);
}

void deleteKey(int* arr, int i)
{
	if(heapSize == 0)
	{
		printf("Heap is Empty\n");
		return;
	}
	if(i >= heapSize)
	{
		printf("Invalid index.\n");
	}
	increaseKey(arr, i, INT_MAX);
	extractMax(arr);
}

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define True 1
#define False 0

int parent(int);
int leftChild(int);
int rightChild(int);
void insert(int*, int, int);
void decreaseKey(int*, int, int);
void MinHeapify(int*, int);
int extractMin(int*);
int MinElement(int*);
void swap(int*, int*);
void deleteKey(int*, int);

int heap_size = 0;

int main()
{
	int capacity, i, choice, condition = True, value;
	printf("Enter the size of heap\n");
	scanf("%d", &capacity);
	int* heap = (int*)malloc(capacity * sizeof(int));
	while(condition)
	{
		printf("Enter :-\n1. To insert an element.\n2. To delete a key.\n3. To get the Minimum Element.\n4. To delete the minimum element.\n5. To print the content of heap.\n6. To exit.\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Enter the number you want to insert.\n");
				scanf("%d", &value);
				insert(heap, value, capacity);
				break;
			case 2:
				printf("Enter the index where you want to delete a value.\n");
				scanf("%d", &value);
				deleteKey(heap, value);
				break;
			case 3:
				printf("Minimum element is:%d\n", MinElement(heap));
				break;
			case 4:
				extractMin(heap);
				break;
			case 5:
				for(i = 0; i < heap_size; i++)
					printf("%d\n", heap[i]);
				break;
			case 6:
				condition = False;
				break;
			default:
				printf("Enter a valid choice between 1 and 5.\n");
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
	if(heap_size == capacity)
	{
		printf("Heap Overflow\n");
		return;
	}
	heap_size++;
	arr[heap_size-1] = value;
	int i = heap_size-1;
	while(i != 0 && arr[parent(i)] > arr[i])
	{
		swap(&arr[parent(i)], &arr[i]);
		i = parent(i);
	}
}

void decreaseKey(int* arr, int i, int k)
{
	arr[i] = k;
	while(i != 0 && arr[parent(i)] > arr[i])
	{
		swap(&arr[parent(i)], &arr[i]);
		i = parent(i);
	}
}

void Heapify(int* arr, int i)
{
	int l = leftChild(i);
	int r = rightChild(i);
	int smallest = i;
	if(l < heap_size && arr[l] < arr[i])
		smallest = l;
	if(r < heap_size && arr[r] < arr[i])
		smallest = r;
	if(smallest != i)
	{
		swap(&arr[i], &arr[smallest]);
		Heapify(arr, smallest);
	}
}

int extractMin(int* arr)
{
	if(heap_size == 0)
		return INT_MAX;
	if(heap_size == 1)
	{
		heap_size--;
		return arr[0];
	}
	int root = arr[0];
	arr[0] = arr[heap_size-1];
	heap_size--;
	Heapify(arr, 0);
	return root;
}

int MinElement(int* arr)
{
	return arr[0];
}

void deleteKey(int* arr, int i)
{
	decreaseKey(arr, i, INT_MIN);
	extractMin(arr);
}


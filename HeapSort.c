#include<stdio.h>
#include<stdlib.h>

void Heapify(int*, int, int);
void HeapSort(int*, int);
void swap(int*, int*);

int main()
{
	int size, i;
	printf("Enter the size of the array.\n");
	scanf("%d", &size);
	int* arr = (int *)malloc(size * sizeof(int));
	printf("Enter the elements of the heap one by one.\n");
	for(i = 0; i < size; i++)
		scanf("%d", &arr[i]);
	HeapSort(arr, size);
	printf("Sorted array:\n");
	for(i = 0; i < size; i++)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}

void Heapify(int* arr, int size, int i)
{
	int l = 2*i+1;
	int r = 2*i+2;
	int largest = i;
	if(l < size && arr[l] > arr[largest])
		largest = l;
	if(r < size && arr[r] > arr[largest])
		largest = r;
	if(i != largest)
	{
		swap(&arr[i], &arr[largest]);
		Heapify(arr, size, largest);
	}
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void HeapSort(int* arr, int size)
{
	int i;
	for(i = size/2-1; i >= 0; i--)
		Heapify(arr, size, i);
	for(i = size-1; i >= 0; i--)
	{
		swap(&arr[0], &arr[i]);
		Heapify(arr, i, 0);
	}
}

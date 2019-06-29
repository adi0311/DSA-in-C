#include<stdio.h>
#include<stdlib.h>
#define True 1
#define False 0

struct Node* insert(int, struct Node*, struct Node*);
void inorder(struct Node*);

struct Node
{
	int data;
	struct Node* leftTree;
	struct Node* rightTree;
};

int main()
{
	int value, condition = True, choice;
	// We can insert any node and make a binary tree accordingly.
	struct Node* t1 = insert(1, NULL, NULL);
	/*
	 	1
	       / \
	      N   N 
	 */
	struct Node* t2 = insert(2, NULL, NULL);
	/*
		2
	       / \
	      N   N
	 */
	struct Node* t4 = insert(4, NULL, NULL);
	/*
	 	4
	       / \
	      N   N
	 */
	struct Node* t5 = insert(5, NULL, NULL);
	/*
	 	5
	       / \
	      N   N
	 */
	struct Node* t3 = insert(3, t1, t2);
	/*
	 	3
	       / \
	      /   \
	     /     \
	    1       2
	   / \     / \
	  /   \   /   \
         N    N   N    N
	 */
	struct Node* t6 = insert(6, t4, t5);
	 /*
	  	6
	       / \
	      /   \
	     /     \
	    4       5
	   / \     / \
	  /   \   /   \
         N    N  N     N
	  */	
	struct Node* t7 = insert(7, t3, t6);
	/*
	 	7
	       / \
	      /   \
	     /     \
	    /       \
	   3         6
	  / \        / \
	 /   \      /   \
	/     \    /     \
	1     2    4      5
       / \   / \  / \    / \
      N   N  N  N N N   N   N
	*/
	printf("Inorder Traversal of the BinaryTree we formed is :\n");
	/* 1
	   3
	   2
	   7
	   4
	   6
	   5 */
	inorder(t7);
	return 0;
}
struct Node* insert(int value, struct Node* lefttree, struct Node* righttree)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp -> data = value;
	temp -> leftTree = lefttree;
	temp -> rightTree = righttree;
	return temp;
}
void inorder(struct Node* root)
{
	if(root != NULL)
	{
		inorder(root -> leftTree);
		printf("%d\n", root -> data);
		inorder(root -> rightTree);
	}
}

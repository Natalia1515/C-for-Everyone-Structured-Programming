/*
 * Week_4 This program opens and reads a file of integer into an array and places
 * the values into a binary tree structure. Walks the tree "inorder" and prints
 * the values to the screen.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct intNumber
{
	int data;
	struct intNumber * left;
	struct intNumber * right;
}intNumber;

//Read number of Elements from the file
void getNumOfElements(FILE * ifp, int * numOfElements)
{
	if(ifp == NULL)
	{
		printf("Error opening file\n");
		exit(1);
	}
		if(fscanf(ifp, "%d", numOfElements) != EOF)

		   printf("Number of Elements: %d\n", *numOfElements);
}
//Read the integers from the file
void readInts(FILE * ifp, int * nums, int size)
{
	int i=0, j=0;

	while (fscanf(ifp, "%d", &nums[i]) !=EOF && i<size)
		i++;

	for(j=0; j<size; j++ )
		printf("%d ", nums[j]);
	printf("\n\n");
}
//Create and insert a new element
void insert(intNumber** head, int data)
{
	intNumber* newEl = (intNumber*) malloc(sizeof(intNumber));
	newEl->data = data;
	newEl->left = NULL;
	newEl->right = NULL;
	intNumber* i;
	if(*head == NULL)
	{
		*head = newEl;
		return;
	}

	for(i= *head; i!=NULL;)
	{
		//printf("left %p , right %p \n", i->left, i->right );
		if(newEl->data > i->data)
		{
			if(i->right == NULL)
			{
				i->right = newEl;
				return;
			}
			else
				i = i->right;
		}
		else
		{
			if(i->left == NULL)
			{
				i->left = newEl;
				return;
			}
			else
				i= i->left;
		}
	}
}
//Print elements from the binary tree structure
void printInOrder(intNumber* head)
{
	if(head == NULL)
		return;
	if(head->left != NULL)
	{
		printInOrder(head->left);
		printf("%d ", head->data);
		printInOrder(head->right);
	}
	else
	{
		printf("%d ", head->data);
		printInOrder(head->right);
	}
}
int main()
{
	FILE *ifp;
	int numOfElements=0, i;
	intNumber* head = NULL;
	ifp = fopen("listOfInts.txt", "r");
	getNumOfElements(ifp, &numOfElements);

	int nums[numOfElements];
	readInts(ifp, nums, numOfElements);

	//create new elements
	for(i=0; i<numOfElements; i++)
	{
		insert(&head, nums[i]);
	}
	printf("Print in order: \n");

	printInOrder(head);

	return 0;
}

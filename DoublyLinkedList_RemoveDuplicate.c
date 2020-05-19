/*
 * Week_3 This program removes all duplicate data in the doubly linked list.
 * The list is sorted and adjacent elements with the same value are removed.
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define NUM_OF_ELEMENTS 100

typedef struct dLinkedList
{
	int data;
	struct dLinkedList* next;
	struct dLinkedList* previous;

}dLinkedList;

void insert(dLinkedList* newElement, dLinkedList** listHead )
{
	// link a new element

	newElement->next = *listHead;
	*listHead = newElement;
	if(newElement->next)
		newElement->next->previous = newElement;
	newElement->previous = NULL;
}
void printList(dLinkedList* listHead)
{
	dLinkedList* el;
	for(el=listHead; el!=NULL; el=el->next)
		printf("%d ", el ->data);
	printf("\n");
}
void inputElements(dLinkedList** listHead)
{
	int i;
	for (i=0; i < NUM_OF_ELEMENTS; i++)
	{
		// create a new element
		dLinkedList* newEl = (dLinkedList*) malloc(sizeof(dLinkedList));
		newEl ->data = rand() % 50;
		insert(newEl, listHead); //add element to the list
	}
}
void removeElement(dLinkedList* removeEl, dLinkedList** listHead)
{
	// printf("removeElement value %d\n", removeEl->data);
	if(*listHead == NULL)
		return;
	else if (removeEl == *listHead)
		*listHead = removeEl->next;
	if(removeEl->previous)
		removeEl->previous->next = removeEl ->next;
	if(removeEl->next)
		removeEl->next->previous= removeEl ->previous;
}
void swap (int * num1, int * num2)
{
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
// Sort the list by the data field
void sortLL(dLinkedList* listHead)
{
	dLinkedList * i;
	dLinkedList * j;

	for(i= listHead; i != NULL && i->next != NULL; i= i->next)
	{
		for(j= i->next; j != NULL; j= j->next)
			if(i->data > j->data )
				swap(& i->data, & j->data); // find the smallest number and swap
	}
}
void findAndRemoveDuplicate(dLinkedList* listHead)
{
		dLinkedList * i;
		dLinkedList * j;

		for(i= listHead; i != NULL && i->next != NULL; i= i->next)
		{
			for(j= i->next; j != NULL; j= j->next)
				if(i->data == j->data)
					removeElement(j, & listHead);// remove element with duplicate value
		}
}
int main()
{
	srand(time(NULL));
	dLinkedList* head = NULL;
	inputElements(&head);
	printf("Original list \n");
	printList(head);
	sortLL(head);
	printf("\nSorted list \n");
	printList(head);
	findAndRemoveDuplicate(head);
	printf("\nDuplicates removed list \n ");
	printList(head);
	return 0;
}

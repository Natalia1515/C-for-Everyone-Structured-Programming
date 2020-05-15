/*
 * Week_3 This program can store an input from the terminal as a linked list,
 * and prints out the information to the screen.
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

typedef struct atomicElement
{
	char elName[20];
	char elSymbol[5];
	double atomicWeight;
	struct atomicElement* next;

}atomicElement;

void insert(atomicElement* newElement, atomicElement** listHead )
{
	// link a new element
	newElement->next = *listHead;
	*listHead = newElement;
}
void printList(atomicElement* listHead)
{
	atomicElement* el;
	for(el=listHead; el!=NULL; el=el->next)
		printf("Element Name: %-15s Symbol: %-10s Atomic Weight: %lf \n", el->elName, el->elSymbol, el ->atomicWeight);
}
atomicElement* inputElement()
{
	// create a new element
	atomicElement* newEl = (atomicElement*) malloc(sizeof(atomicElement));
	printf("Enter Element Name:\n");
	scanf("%s", newEl->elName);
	printf("Enter Element Symbol:\n");
	scanf("%s", newEl->elSymbol);
	printf("Enter Atomic Weight:\n");
	scanf("%lf", &newEl->atomicWeight );
	return newEl;
}
int main()
{
	atomicElement* head = NULL;
	atomicElement* newEl;
	char c[2];
	//collect the data while 'Y' is entered
	do
	{
		newEl = inputElement();
		insert(newEl, &head);
		printf("Press 'Y' if you want to continue\n");
		scanf("%s", c);
	}while (c[0] == 'Y' || c[0] =='y');
	printList(head);

	return 0;
}

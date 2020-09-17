// RasterGraphic.cpp
#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC	// need this to get the line identification
//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF); // in main, after local declarations
//NB must be in debug build

#include <crtdbg.h>
#include <iostream>
#include <time.h>
#include "GraphicElement.h"
#include "RasterGraphic.h"
using namespace std;

bool running = true;

int main(void)
{
	char selection;
	bool running = true;
	RasterGraphic A;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	while (running)
	{
		cout << "MENU\n 1. Insert a GraphicElement\n 2. Delete a GraphicElement\n 3. Report the RasterGraphic\n 4. Quit\n" << endl;
		cin >> selection;

		switch (selection)
		{
		case '1':
			A.InsertGraphicElement();
			break;
		case '2':
			A.DeleteGraphicElement();
			break;
		case '3':
			A.ReportRasterGraphic();
			break;
		case '4':
			running = false;
			break;
		default:
			break;
		}
	}
	return 0;
}

/******************
Function name: RasterGraphic
Purpose: Allocate memory for the GraphicElements structure of size struct GraphicElement
Function In parameters: None
Function Out parameters: None
Version: 1.00
******************/
RasterGraphic::RasterGraphic() {
	GraphicElements = nullptr;
}

/******************
Function name: InsertGraphicElement
Purpose: Inserts a node at a position chosen by the user.
A new node is created temporarily to avoid directly altering the real node.
Cycle through every node until user's position reached, append fileName, point to the next node, and have the previous node point to the user's node.
Function In parameters: None
Function Out parameters: None
Version: 1.00
******************/
void RasterGraphic::InsertGraphicElement() {
	/*
		RasterGraphic.h
			GraphicElement* GraphicElements;
	*/
	/* static array pointer to char. Stores file name by user input for the GraphicElement */
	char fileName[100];
	/* stores the position where the node will be inserted. Default: 0, because conditional statement throws error at compilation */
	int pos = 0;
	/* temporary/new node for the GraphicElement that is used to store the fileName of the GraphicElement, and the pointer to the next node */
	GraphicElement* newNode = new GraphicElement();
	/* temporary node holding the real GraphicElement node.head of the RasterGraphic */
	GraphicElement* tempNode = GraphicElements;
	/* a counter that holds the number of nodes there are in the linked list */
	int numOfNodes = 0;
	/* holds node of the current index of the GraphicElement list */
	GraphicElement* currentNode;
	/* holds the previous node of the GraphicElement list */
	GraphicElement* prevNode;
	/* node index begins from the head */
	int currentIndex = 0;

	cout << "Insert a GraphicElement in the RasterGraphic" << endl;
	/* get and store user input for fileName */
	cout << "Please enter the GraphicElement filename: ";
	cin.ignore();
	cin.getline(fileName, 100);
	/* dynamic memory allocation for newNode, string length of user input */
	newNode->GetfileName() = new char[(strlen(fileName) + 1)];
	/* copy pointer of char in fileName into newNode->fileName as a string */
	strcpy(newNode->GetfileName(), fileName);

	/* check if any nodes exist, if nodes exist count them, else numOfNodes is still = 0*/
	if (tempNode) {
		/* cycle through the linked list to determine the length of the linked list */
		while (tempNode) {
			numOfNodes++;
			tempNode = tempNode->GetpNext();
		}
	}
	/* set current to head/first node to start insertion where the iteration begins from the head of pA->GraphicElements*/
	currentNode = GraphicElements;

	/* check the length of the linked list to determine which node number is currently being appended to the linked list */
	if (numOfNodes > 0) {
		/* print the number of nodes in the list */
		cout << "There are "<< numOfNodes <<" GraphicElement(s) in the list. Please specify the position (<= " << numOfNodes <<") to insert at : ";
		/* get node insertion position from user input */
		cin >> pos;

		/* insertion is before the head */
		if (pos == 0) {
			/* new node is before head of linked list, so point next of 'newNode' to full linked list */
			newNode->GetpNext() = currentNode;
			/* 'newNode' contains user input + rest of linked list. Assign that to pointer to GraphicElement */
			GraphicElements = newNode;
			return;
		}
		/* insertion is in between the head and tail of the linked list */
		else {

			/* cycle through linked list from head (currentIndex = 0) to index pos (pos = scanf... get user input) */
			for (currentIndex; currentIndex < pos; currentIndex++) {
				/* assign the current node as the previous node before the current node increases its index*/
				prevNode = currentNode;

				/* here, between the previous node and the current node is where the insertion would happen  */

				/* the current node is the next node after that */
				currentNode = currentNode->GetpNext();
			}
			prevNode->GetpNext() = newNode;
			newNode->GetpNext() = currentNode;
			return;
		}
	}
	else if (numOfNodes == 0) {
		/* print that there are no other nodes in the list before this node */
		printf("This is the first GraphicElement in the list.\n");
		/* next node is a nullptr until a graphic is entered after this node */
		newNode->GetpNext() = GraphicElements;
		GraphicElements = newNode;
		return;
	}
}
/******************
Function name: DeleteGraphicElement
Purpose: Deletes the first node in the linked list.
Creates a temporary linked list, reassigns head of temporary linked list to next node.
Assigns temporary linked list with deleted first node to original linked list.
Function In parameters: None
Function Out parameters: None
Version: 1.0
******************/
void RasterGraphic::DeleteGraphicElement() {
	/* assign real linked list to temporary linked list */
	GraphicElement* tempNode = GraphicElements;
	/* check if linked list is empty */
	if (tempNode) {

		tempNode = tempNode->GetpNext();
		/* assign temp list of nodes to original node list */
		/*
		delete GraphicElements->GetfileName();
		delete GraphicElements->GetpNext();
		GraphicElements->GetfileName() = nullptr;
		GraphicElements->GetpNext() = nullptr;
		*/
		GraphicElements = tempNode;
		return;
	}
	/* if empty do nothing */
	else {
		return;
	}
}

/******************
	Function name: ReportRasterGraphic
	Purpose: Prints the GraphicElements
	Version: 1.0
******************/
void RasterGraphic::ReportRasterGraphic() {
	int counter = 0;
	time_t startsec, oldsec, newsec;
	GraphicElement* iterator = GraphicElements;

	if (GraphicElements == 0)
	{
		printf("No GraphicElements in the RasterGraphic\n");
		return;
	}

	printf("Report the RasterGraphic\n");
	startsec = oldsec = time(NULL);
	while (iterator)
	{
		newsec = time(NULL);
		if (newsec > oldsec)
		{
			printf("GraphicElement #%d, time = %I64d sec\n", counter++, newsec - startsec);
			printf("Image file name = %s\n", iterator->GetfileName());
			iterator = iterator->GetpNext();
			oldsec = newsec;
		}
	}
}
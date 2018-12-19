#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node* head; // pointer to head of doubly linked list

struct Node* createNewNode(int x) {
	struct Node* newNode
		= (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
} // kreira novi Node i vrati pointer na njega,odma alocira onoliko memorije koliko zauzima Node struktura,pošto je prvi node previous node i next node pointer su null

void insAtHead(int x) {
	struct Node* newNode = createNewNode(x);
	if (head == NULL) {
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head;
	head = newNode;
} // dodaje novi Node na head liste
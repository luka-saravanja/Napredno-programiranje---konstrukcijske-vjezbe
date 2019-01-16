#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node* head; // pointer to head of doubly linked list

struct Node* createNewNode(int x)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
} // kreira novi Node i vrati pointer na njega,odma alocira onoliko memorije koliko zauzima Node struktura,pošto je prvi node previous node i next node pointer su null

void insAtHead(int x) 
{
	struct Node* newNode = createNewNode(x);
	if (head == NULL)
	{
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head;
	head = newNode;
}// dodaje novi Node na head liste

void printList() {
	struct Node* temp = head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void deleteNode(struct Node** head_ref, struct Node* del)
{

	if (*head_ref == NULL || del == NULL)
		return;

	//ako je node za brisanje head
	if (*head_ref == del)
		*head_ref = del->next;
	// mjenjanj next samo ako node za brisanje nije zadnji node
	if (del->next != NULL)
		del->next->prev = del->prev;
	// mjenjanj previous samo ako node za brisanje nije prvi node
	if (del->prev != NULL)
		del->prev->next = del->next;
	// free memory koja je zauzeta sa del
	free(del);
}

void deleteNodeAtPosition(struct Node** head_ref, int n)
{
	if (*head_ref == NULL || n <= 0)
		return;

	struct Node* current = *head_ref;
	int i;
	// odlazak na n-tu poziciju od pocetka 
	for (int i = 1; current != NULL && i < n; i++)
		current = current->next;
	// ako je n veci od broja nodova
	if (current == NULL)
		return;
	//brise node koji je current
	deleteNode(head_ref, current);
}

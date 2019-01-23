/*
 ============================================================================
 Name        : SaravanjaKonstr2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node* head;/* pointer to head of doubly linked list*/
struct Node* last; /* pointer to tail of doubly linked list*/

void newDoubleLinkedList (int n);
void printList();
void insAtHead(int x);
void DlListDeleteAnyNode(int n);


int main()
{
    int n, user_function=1;


    while(user_function != 0)
    {

        printf("1. Kreiranje dvostruko povezanog popisa\n");
        printf("2. Brisanje n-tog Node-a\n");
        printf("3. Ispis liste \n");
        printf("4. Dodavanje novog nodea na head \n");
        printf("0. Izlaz\n");
        printf("==================================================\n");
        printf("Odaberite funkciju : ");

        scanf("%d", &user_function);

        if( user_function == 0)
        {
         exit(0);
        }
        else if(user_function == 1)
        { printf("Odaberite broj elemenata liste: ");
        scanf("%d", &n);
        newDoubleLinkedList(n);

        }
        else if(user_function == 2)
        {
         printf("Odaberite element koji želite obrisati: ");
         scanf("%d", &n);
         DlListDeleteAnyNode(n);
        }
        else if(user_function == 3)
        {
         printList();
        }
        else if(user_function == 4)
        {
        	printf("Odaberite vrijednost novog heada : ");
        	         scanf("%d", &n);
        	         insAtHead(n);
        }

        printf("\n\n");
    }

    return 0;
}



struct Node* createNewNode(int x)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
} /* kreira novi Node i vrati pointer na njega,odma alocira onoliko memorije koliko zauzima Node struktura,
pošto je prvi node previous node i next node pointer su null*/

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
}/* dodaje novi Node na head liste*/

void printList() {
	struct Node* temp = head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void DlListDeleteAnyNode(int pos)
{
    struct Node *curNode;
    int i;

    curNode = head;
    for(i=1; i<pos && curNode!=NULL; i++)
    {
        curNode = curNode->next;
    }

    if(pos == 1)
    {
        DlListDeleteFirstNode();
    }
    else if(curNode == last)
    {
        DlListDeleteLastNode();
    }
    else if(curNode != NULL)
    {
        curNode->prev->next = curNode->next;
        curNode->next->prev = curNode->prev;

        free(curNode); //Delete the n node
    }
    else
    {
        printf(" Nepostojeca pozicija");
    }
}

void DlListDeleteFirstNode()
{
    struct Node * NodeToDel;
    if(head == NULL)
    {
        printf(" Brisanje nemoguce, nema podataka u listi\n");
    }
    else
    {
        NodeToDel = head;
        head = head->next;
        head->prev = NULL;
        free(NodeToDel);
    }
}

void DlListDeleteLastNode()
{
    struct Node * NodeToDel;

    if(head == NULL)
    {
        printf(" Nemoguce brisanje,nema podataka\n");
    }
    else
    {
        NodeToDel = last;
        last = last->prev;
        last->next = NULL;
        free(NodeToDel);
    }
}

void newDoubleLinkedList(int n)
{
    int i, data;
    struct Node* newNode;

    if(n >= 1)
    {
        head = (struct Node*)malloc(sizeof(struct Node));

        printf("vrijednost prvog node-a : ");
        scanf("%d", &data);

        head->data = data;
        head->prev = NULL;
        head->next = NULL;

        last = head;



        for(i=2; i<=n; i++)
        {
            newNode = (struct Node*)malloc(sizeof(struct Node));

            printf("vrijednost  node-a : ");
            scanf("%d", &data);

            newNode->data = data;
            newNode->prev = last;
            newNode->next = NULL;

            last->next = newNode;
            last = newNode;
        }

    }
}

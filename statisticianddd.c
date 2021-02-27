#include <stdlib.h>
#include <stdio.h>
#define bool int
#define TRUE 1
#define FALSE 0

typedef bool Boolean;
typedef struct node *nodePtr;

struct node {
	int data;
	nodePtr *next;
};
struct node *head = NULL, *tail = NULL;


typedef nodePtr Statistician, DataStore;

bool isEmpty() {
		if (head == NULL) {
			return TRUE;
		} else
			return FALSE;
}

void doesNotExist() {
	printf("\nNO EXISTING STATISTICIAN\n");
	return;
}

Statistician newStatistician() {
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	struct node *ptr;
	int x;
	Statistician s;
	//
		if (newNode == NULL) {
			printf("\nMemory cannot be allocated.");
			return;
		} else {
			printf("\nCreating new statistician...");
			printf("\nEnter data: ");
			scanf("%d", &x);
			add(s, x);
		}
	printf("\n\nNEW STATISTICIAN CREATED SUCCESSFULLY\n");
}

void destroyStatistician(Statistician *s) {
	struct node *curr = head;
	nodePtr *next = NULL;
	//
		while (curr != NULL) {
			next = curr->next;
			free(curr);
			curr = next;
		}
	head = NULL;
	printf("\nEXISTING STATISTICIAN SUCCESSFULLY DESTROYED\n");
}

void add(Statistician s, int x) {
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	struct node *ptr;
	//
	if (newNode == NULL) {
		printf("\nMemory cannot be allocated.");
		return;
	} else {
		newNode->data = x;
		newNode->next = NULL;
		if (isEmpty()) {
			head = newNode;
			tail = newNode;
		} else {
			tail->next = newNode;
			tail = newNode;
		}
	}
	
}

void removeData(Statistician s, int x) {
	struct node *curr = head, *prev = NULL;
	int count = 0;
	//
	while (curr != NULL) {
		if (curr->data == x) {
			if (prev == NULL) head = curr->next;
			else prev->next = curr->next;
		printf("\nDATA SUCCESSFULLY REMOVED\n");
		count = 1;
		free(curr);
		break;
		}
	prev = curr;
	curr = curr->next;
	}
	if (count == 0);
		printf("\nDATA NOT FOUND\n");
}

void displayData(Statistician s) {
	struct node *ptr;
		if (isEmpty()) {
			printf("\nNO EXISTING STATISTICIAN\n");
			return;
		} else {
			ptr = head;
			printf("\nData : \n");
			while (ptr != NULL) {
				printf("%d ", ptr->data);
				ptr = ptr->next;
			}
			printf("\n");	
		}
}

void selection(int sel) {
	int x;
	Statistician s;
	//
	switch(sel) {
		case 0 : printf("\nProgram closed.");
			return 0;
			
		case 1 : 
				if (isEmpty()) newStatistician();
				else printf ("\nA STATISTICIAN ALREADY EXISTS\n");
				return;
				
		case 2 :
				if (isEmpty()) doesNotExist();
				else destroyStatistician(s);
				return;
				
		case 3 : 
				if (isEmpty()) doesNotExist();
				else {
					printf("\nEnter data: ");
					scanf("%d", &x);
					add(s, x);
					printf("\nDATA SUCCESSFULLY ADDED\n");
				}
				return;
				
		case 4 :
				if (isEmpty()) doesNotExist();
				else {
					printf("\nEnter data: ");
					scanf("%d", &x);
					removeData(s, x);
				}
				return;
			
		case 5 : displayData(s);
			return;
			
		default :
			printf("\nINVALID SELECTION\n");
			return;
		}
	return;
}
int main() {
	int sel;
	//
	do {
		printf("\n[0] - Quit");
		printf("\n[1] - New Statistician");
		printf("\n[2] - Destroy Statistician");		
		printf("\n[3] - Add Data");
		printf("\n[4] - Remove Data");
		printf("\n[5] - Display Statistics");
		printf("\nSelect an operation: ");
		scanf("%d", &sel);
		//
		selection(sel);
	} while (sel != 0);
	
	return 0;
	
}



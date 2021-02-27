#include "LL.h"

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
	
	printf("\nCreating new statistician...");
	printf("\nEnter data: ");
	scanf("%d", &newNode->data);
	
	head = newNode;
	head->next = NULL;
	
	tail = newNode;
	tail->next = NULL;
	
	printf("\nNEW STATISTICIAN CREATED SUCCESSFULLY\n");
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
	if (newNode == NULL)
	{
		printf("\nMemory cannot be allocated.");
		return;
	}
	else
	{
		newNode->data = x;
		newNode->next = NULL;
		tail->next = newNode;
		tail = newNode;
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
		return;
		}
	prev = curr;
	curr = curr->next;
	}
	if (count == 0);
		printf("\nDATA NOT FOUND\n");
}

void displayData(Statistician s)
{
	struct node *ptr;
	ptr = head;
	printf("\nData : ");
		while (ptr != NULL)
		{
			printf("%d ", ptr->data);
			ptr = ptr->next;
		}
	//
	int max;
	int min;
	int range;
	float mean;
	float median;
	int mode;
	float variance;
	float stdDev;
	//
	max = maximum(s);
	min = minimum(s);
	range = getRange(s, min, max);
	mean = getMean(s);
	median = getMedian(s);
	mode = getMode(s);
	printf("\nMaximum value : %d", max);
	printf("\nMinimum value : %d", min);
	printf("\nRange : %d", range);
	printf("\nMean : %f", mean);
	printf("\nMedian : %f", median);
	printf("\nMode : %d", mode);
	printf("\n\n");		
}

int maximum(Statistician s) {
	struct node *temp = head;
	int max = INT_MIN;
		while (temp) {
			if (temp->data > max)
				max = temp->data;
			temp = temp->next;
		}
	return max;
}

int minimum(Statistician s) {
	struct node *temp = head;
	int min = INT_MAX;
		while (temp) {
			if (temp->data < min)
				min = temp->data;
			temp = temp->next;
		}
	return min;
}

int getRange(Statistician s, int min, int max) {
	int range;
	range = max - min;
	return range;
}

DataStore getMode(Statistician s) {
	struct node *curr = head;
	int mode, length;
	mode = listToArr(getLength(s));
	//
	if (0) return 0;
	else return mode;
}

int listToArr(int length) {
	struct node *curr = head;
	int mode;
	int arr[length];
	int i = 0;
	//
		while (curr != NULL) {
			arr[i++] = curr->data;
			curr = curr->next;
			}
		mode = getArrMode(arr, length);
	return mode;
}

int getArrMode(int a[], int len) {
	int max = 0, lastCount = 0;
	int i, k;
	//
		for (i = 0; i < len; i++) {
			int firstCount = 0;
			for (k = 0; k < len; k++) {
				if (a[k] == a[i])
				firstCount++;
			}
			if (firstCount > lastCount) {
				lastCount = firstCount;
				max = a[i];	
			}		
		}
	return max;
}

int getLength(Statistician s) {
	struct node *curr = head;
	int length = 0;
		while (curr != NULL) {
			length++;
			curr = curr->next;
		}
	return length;
}

float getMean(Statistician s) {
	struct node *curr = head;
	int count = 0;
	int sum = 0;
	float mean = 0.0;
		while (curr != NULL) {
			count++;
			sum += curr->data;
			curr = curr->next;
		}
		mean = (double)sum/count;
	return mean;
}

float getMedian(Statistician s) {
	struct node *ptr1 = head, *ptr2 = head, *prev = head, *ptr3;
	int sum = 0;
	float median = 0.0;
		if (head != NULL) {
			while (ptr2 != NULL && ptr2->next != NULL) {
				ptr3 = ptr2->next;
				ptr2 = ptr3->next;
				prev = ptr1;
				ptr1 = ptr1->next;
			}
		if ((getLength(s)%2) != 0) {
			median = ptr1->data;
			return median;
		}
		else {
			sum = ptr1->data + prev->data;
			median = (double)sum/2;
			return median;
		}
	}
}

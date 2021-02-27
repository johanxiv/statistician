#include <stdio.h>
#include <stdlib.h>

#define bool int
#define TRUE 1
#define FALSE 0

typedef bool Boolean;
typedef struct node *nodePtr;

struct node
{
	int data;
	nodePtr *next;
}NODE;

struct node *head, *tail;

typedef nodePtr Statistician, DataStore;


void selection(int sel);

void doesNotExist();
bool isEmpty();

Statistician newStatistician();
void destroyStatistician(Statistician *s);
void add(Statistician s, int x);
void removeData(Statistician s, int x);
void displayData(Statistician s);

int maximum(Statistician s);
int minimum(Statistician s);
int getRange(Statistician s, int min, int max);
DataStore getMode(Statistician s);
int listToArr(int length);
int getLength(Statistician s);
int getArrMode(int a[], int len);
float getMean(Statistician s);
float getMedian(Statistician s);

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define bool int
#define TRUE 1
#define FALSE 0

void selection(int sel);

typedef bool Boolean;
typedef struct node *nodePtr;

struct node
{
	int data;
	nodePtr *next;
}NODE;

struct node *head, *tail;

typedef nodePtr Statistician, DataStore;

void doesNotExist();
bool isEmpty();

Statistician newStatistician();
void destroyStatistician(Statistician *s);
void add(Statistician s, int x);
void removeData(Statistician s, int x);
void displayData(Statistician s);

int getLength(Statistician s);
int minimum(Statistician s);
int maximum(Statistician s);
int range(Statistician s, int min, int max);

float getMean(Statistician s);

DataStore getMedian(Statistician s);
void sortArrMedian(int a[], int len);
void sort(int *x, int *y);
void getArrMedian(int a[], int len);


DataStore getMode(Statistician s);
void getArrMode(int a[], int len);

float getVariance(Statistician s, int length);
float standardDeviation(Statistician s, float var);

#include "LL.h"

int getLength(Statistician s)
{
	int length = 0;
	struct node *ptr = head;
	
	while (ptr != NULL)
	{
		length++;
		ptr = ptr->next;
	}
	
	return length;
}

int minimum(Statistician s)
{
	int i;
	
	struct node *ptr = head;
	
	int min = ptr->data;
	
	while (ptr != NULL)
	{
		if (min > ptr->data)
		{
			min = ptr->data;
		}
		
		ptr = ptr->next;
	}
	
	return min;
}

int maximum(Statistician s)
{
	int i;
	
	struct node *ptr = head;
	
	int max = ptr->data;
	
	while (ptr != NULL)
	{
		if (max < ptr->data)
		{
			max = ptr->data;
		}
		
		ptr = ptr->next;
	}
	
	return max;
}

int range(Statistician s, int min, int max)
{
	int range;
	
	range = max - min;
	
	return range;
}

float getMean(Statistician s)
{
	int count = 0;
	int sum = 0;
	float mean = 0.0;
	
	struct node *currentNode = head;
	
	while (currentNode != NULL)
	{
		count++;
		sum += currentNode->data;
		currentNode = currentNode->next;
	}
	
	mean = (double)sum / count;
	
	return mean;
}

float getMedian(Statistician s)
{
	int sum = 0;
	float median = 0.0;
	
	struct node *ptr1 = head, *ptr2 = head, *prev = head, *ptr3;
	
	if (head != NULL)
	{
		while (ptr2 != NULL && ptr2->next != NULL)
		{
			ptr3 = ptr2->next;
			ptr2 = ptr3->next;
			prev = ptr1;
			ptr1 = ptr1->next;
		}
		
		if ((getLength(s) % 2) != 0)
		{
			median = ptr1->data;
			return median;
		}
		else
		{
			sum = ptr1->data + prev->data;
			median = (double)sum/2;
			return median;
		}
	}
}

DataStore getMode(Statistician s)
{
	int length = getLength(s);
	int a[length];
	int i = 0;
	
	struct node *ptr = head;
	
	while (ptr != NULL)
	{
		a[i++] = ptr->data;
		ptr = ptr->next;
	}
	
	getArrMode(a, length);
}


int getArrMode(int a[], int len)
{
	int max = 0, lastCount = 0;
	int i, j, t;
	int b[] = {0};
	
	int sum = 0, k = 0, c = 1, mode;
    float x = 0.0, y = 0.0;
    
    for (i = 0; i < len - 1; i++)
    {
        mode = 0;
        for (j = i + 1; j < len; j++)
        {
            if (a[i] == a[j]) {
                mode++;
            }
        }
        if ((mode > max) && (mode != 0)) {
            k = 0;
            max = mode;
            b[k] = a[i];
            k++;
        }
        else if (mode == max) {
            b[k] = a[i];
            k++;
        }
    }
    for (i = 0; i < len; i++)
    {
        if (a[i] == b[i]) 
            c++;
        }
        if (c == len)
            printf("There is no mode");
        else
        {
            for (i = 0; i < k; i++)
                printf("%d ",b[i]);
        }
        return;
}


float getVariance(Statistician s, int length)
{
	int i, sum, mean;
	float sumSqr, var;
	
	struct node *ptr = head;
	
	int a[length];
	
	while (ptr != NULL)
	{
		a[i++] = ptr->data;
		ptr = ptr->next;
	}
	
	mean = getMean(s);
	
	for (i = 0; i < length; i++)	
	{
		sumSqr += (a[i] - mean)*(a[i] - mean);
	}
	
	var = sumSqr / length;
	
	return var;
}

float standardDeviation(Statistician s, float var)
{
	float sdv;
	sdv = sqrtf(var);
	
	return sdv;
}

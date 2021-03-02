#include "LL.h"


int main()
{
	int sel;
	
	do
	{
		printf("\n[0] - Quit");
		printf("\n[1] - New Statistician");
		printf("\n[2] - Destroy Statistician");		
		printf("\n[3] - Add Data");
		printf("\n[4] - Remove Data");
		printf("\n[5] - Display Statistics");
		printf("\n\nSelect an operation: ");
		scanf("%d", &sel);
		
		selection(sel);
	} while (sel != 0);
	
	return 0;
}

void selection(int sel)
{
	int x;
	Statistician s;
	
	switch(sel)
	{
		case 0:
			system("cls");
			
			printf("\nShutting Down...\n");
			
			return;
		case 1:
			newStatistician();
			
			return;
		case 2:
			if (isEmpty())
			{
				doesNotExist();
			}
			else
			{
				destroyStatistician(s);
			}
			
			return;
		case 3:
			if (isEmpty())
			{
				doesNotExist();
			}
			else
			{
				system("cls");
				
				printf("\nEnter data: ");
				scanf("%d", &x);
				
				printf("\n");
				
				add(s, x);
				
				system("cls");
			}
			
			return;
		case 4:
			if (isEmpty())
			{
				doesNotExist();
			}
			else
			{
				system("cls");
				
				printf("\nEnter data: ");
				scanf("%d", &x);
				
				printf("\n");
				
				removeData(s, x);
				
				system("cls");
			}
			
			return;
		case 5:
			if (isEmpty())
			{
				doesNotExist();
			}
			else
			{
				displayData(s);
			}
			
			return;
			
		default:
			printf("\nINVALID SELECTION!\n\n");
			
			system("pause");
			system("cls");
			
			return;
	}
}


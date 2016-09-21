/*riskamillion.c by Josue Martinez 
COP3502 Dr. Elvs 03/05/2016*/

#include <stdio.h>
#include <stdlib.h>

void armiesInput(long*, long*, long);
int maxVictories(long*, long*, long);
void mergeSort(long*, long, long);
void merge(long*, long,  long, long);



int main()
{
	int cases;
	long numWins, *attacking, *defending, troops;


	scanf("%d", &cases);


	while(cases > 0)
	{
		scanf("%li", &troops);

		attacking = (long*) malloc(troops * sizeof(long));
		defending = (long*) malloc(troops * sizeof(long)); 

		if(attacking == NULL || defending == NULL)
		{
			printf("allocation error");
			return 0;
		}

		armiesInput(attacking, defending, troops);

		mergeSort(attacking, 0, troops-1);
		mergeSort(defending, 0, troops-1);

		numWins = maxVictories(attacking, defending, troops);

		printf("\n%li\n\n", numWins);/*3 \n to make the value more noticable*/

		free(attacking);
		free(defending);

		cases--;
	}
	return 0;
}
/*-------------------------------*/
/*merge sort array recursively*/
void mergeSort(long *army, long start, long end)
{
	
	if(start < end)
	{
		int mid = (end + start) / 2;
		mergeSort(army, mid + 1, end);
		mergeSort(army, start, mid);
		merge(army, start, mid + 1, end);
	}
}

/*-------------------------------*/
/*to swap two different indexes of an array*/
void merge(long *army, long start, long mid, long end)
{
	long *temp, i, len, count1, count2, mergeCount = 0;

	

	len = end- start + 1;
	count1 = start;
	count2 = mid;
	
	temp = (long*) malloc(len * sizeof(long));
	
	while(count1<mid || count2 <= end)
	{
		if(count2 > end||(count1 < mid && army[count1] < army[count2]))
		{
			temp[mergeCount] = army[count1];
			count1++;
			mergeCount++;
		}
		else
		{
			temp[mergeCount] = army[count2];
			count2++;
			mergeCount++;
		}
	}

	for(i = start; i <= end; i++)
	{
		army[i] = temp[i - start];
	}

	free(temp);

}

/*-------------------------------*/
/*function for takingin user input*/
void armiesInput(long* attck, long* defend, long num)
{
	long i;

	for(i = 0; i < num; i++)
	{
		scanf("%li", &attck[i]);
	}

	for(i = 0; i < num; i++)
	{
		scanf("%li", &defend[i]);
	}

}

/*-------------------------------*/
/*to find the maximum victories the defending player can have*/
int maxVictories(long *attck, long *defend, long num)
{
	long i = num -1, j = num -1, count = 0;

	while(i >= 0 && j >= 0)
	{
		if(attck[i] > defend[j])
		{
			i--;
		}
		else if(attck[i] <= defend[j])
		{
			i--;
			j--;
			count++;
		}
	}

	return count;
}

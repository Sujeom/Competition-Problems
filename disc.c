/*disc.c by Josue Martinez 2016*/
#include <stdio.h>
#include <stdlib.h>
 
long long int* buildArray(long long int *x, int size);
long long int waveCal(long long int *wave, int size);
long long int sortWave(long long int *wave, int size);
void swap(long long int *a, long long int *b);
long long int* selectSort(long long int *wave, int size);
void permute(long long int *wave, int l, int r, int size, long long int* val1);
 
int main()
{
	int cases, size, count; 
	long long int val1 = 0;
	long long int *wave;
	scanf("%d", &cases);
 
	count = cases;
 
	while(cases > 0)
	{
		scanf("%d", &size);
 
		wave = buildArray(wave, size);
 
		permute(wave, 0, size-1, size, &val1);
 
		printf("Wave #%d: %li\n",1 + (count - cases), val1);
 
		free(wave);
 
 		/*THIS IS IMPORTANT*/
 		val1=0;
		cases--;
	}
}
/*----------------*/
/*builds an int array*/
long long int* buildArray(long long int *x, int size)
{	
	int i;
 
	x = (long long int*) malloc(size * sizeof(long long int));
 
	for(i = 0; i < size; i++)
		scanf("%li", &x[i]);
 
	return x;
}
/*--------*/
/*this function performs the wave calculation*/
long long int waveCal(long long int *wave, int size)
{
	int i;
	long long int value = 0;
 
	for(i = 0; i < (size - 1); i++)
		if((wave[i] - wave[i + 1]) > 0)
			value += (wave[i] - wave[i + 1]);
		else
			value += (wave[i + 1] - wave[i]);
 
	return value;
}
/*--------*/
/*sorts the wave array for max difference values*/
	void permute(long long int *wave, int l, int r, int size, long long int* val1)
{
	long long int val2;
 
   int i;
 
   if (l == r)
     return;
   else
   {
       for (i = l; i <= r; i++)
       {
          swap(&wave[l], &wave[i]);
          val2 = waveCal(wave, size);
				if(val2 > *val1)
					*val1=val2;
          permute(wave, l+1, r, size, &*val1);
          swap(&wave[l], &wave[i]); 
       }
   }
 
}
/*------*/
/*this functions swaps the valuenin a with value in b*/
void swap(long long int *a, long long int *b)
{
	long long int temp;
 
	temp = *a;
 
	*a = *b;
 
	*b = temp;
 
	return;
}

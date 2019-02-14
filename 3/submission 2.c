#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int arr[100];

void insertionSort(int arr[], int n)
{
   int i,key,j;
   for (i = 1; i < n; i++)
   {
       key =arr[i];
       j = i-1;
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] =arr[j];
           j = j-1;
       }
       arr[j+1] =key;
   }
}

int binarySearch(int x, int rr[], int len)
{
	//printf("afdad %d", x);
    int n=len;
	int first=0, last=n-1;

	while(first<=last)
	{
		int mid=(last+(first))/2;
		if(rr[mid] == x)
		{
			return x;
		}
	 	if(rr[mid] < x)
		{
			first =mid+1;
		}
		if(rr[mid] > x)
		{
			last =mid -1;
		}
	}
	return -1;

}

int main(int argc, char* argv[])
{
	if(argc!=3) // Checks for the correct number of command line argument passed
	{
		printf("Pass 2 arguments \n");
		exit(1);
	}
	FILE *fread;
	fread= fopen(argv[1],"r");

	if (fread == NULL)
	{
		printf("Error opening input file!\n");
		exit(1);
	}
	int num;
	int i=0,n;
	while(fscanf(fread,"%d",&num)==1)
	{
		arr[i]=num;
		i++;

	}
	n=i;
	fclose(fread);
	insertionSort(arr, n);
	int dif=0;
	FILE *fout = fopen(argv[2], "w");
	if (fout == NULL)
	{
		printf("Error opening output file!\n");
		exit(1);
	}

	int flag=0;
	for(int a= 0;a< n; a++)
	{
		for(int x= 0;x< n; x++)
		{
			if(arr[a] != arr[x])
			{
				dif= arr[a]-arr[x];
				int diff=abs(dif);
				//printf("%d %d %d \n",arr[a], arr[x], diff);
				int f= binarySearch(dif, arr, n);
				//printf("Returns %d  \n", f);
				if(f!= -1 )
				{
					fprintf(fout,"%d %d %d\n", dif ,arr[a],arr[x]);
					flag=1;

				}
				//printf("here");
			}
		}
	}
	if (!flag)
	{
		fprintf(fout,"No Such Key exits");
	}
	printf("Output File Generated \n");
	fclose(fout);
}




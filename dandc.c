#include<stdio.h>
	#include<string.h>
	#include<stdlib.h>
	#include<unistd.h>
	#include<float.h>
	#include<math.h>
	#include<time.h>
long long findNumLines(FILE *fp);
long long n_lines, *temp_x,*temp_y, *arr;
  struct test
  {
  	int a,b;
  };


void insertion_sort(struct test arr[], int last/* arguments */)
{
  struct test temp[20]={0};
  int d= last-1;
	char data[100];

    for(int i = 0; i< last; i++)
    {
      d=i;
      while(d > 0 && arr[d].a < arr[d-1].a)
      {
        temp[i] = arr[d];
        arr[d]=arr[d-1];
        arr[d-1]=temp[i];
        d--;
        }
    }
}

void write_to_file( char argv[],float x,float y)
{

	FILE *fp;

	   fp = fopen(argv , "w+");
	   fprintf(fp, "Shortest distance is %f and %f using bruteforce\n", x,y);
	   fclose(fp);
}
void qs( struct test arrr[],int last )
{
  insertion_sort(arrr, last );
}
long long findNumLines(FILE *fp)
{
	long long numLines = 0;
  char str[100];

  while(!feof(fp))
	{
    fgets(str, 100, fp);
    numLines++;
	}

 numLines--;//the above increments count even when EOF reached

 if(fseek(fp, 0L, SEEK_SET) == EOF) {
	 perror("Error while seeking to begining of file");
	 exit(0);
 }

 return numLines;
}
float min_distance(float x, float y)
{
	if(x<=y)
	{
		return x;
	}
	else
	return y;
}
float bruteforce(char argv[])
{

	FILE *fread;
	fread= fopen(argv,"r");

	if (fread == NULL)
	{
		printf("Error opening input file!\n");
		exit(1);
	}
	clock_t begin = clock();
	int num;
	struct test *arr;
	char data[100];
	n_lines= findNumLines(fread);

	temp_x= (long long *) malloc(n_lines * sizeof(long long));
	temp_y= (long long *) malloc(n_lines * sizeof(long long));

	arr= (struct test *) malloc(n_lines * sizeof(struct test));

	for(int u=0; u<= n_lines; u++)
	{
		fgets(data, 100, fread);
		sscanf(data, "%lld %lld", &temp_x[u], &temp_y[u]);
		arr[u].a=temp_x[u];
		arr[u].b=temp_y[u];

	}
	float temp= FLT_MAX;
	float final= FLT_MAX;
	for(int x= 0 ; x< n_lines; x++)
	{
		for(int y=x+1; y< n_lines; y++)
		{
			temp=sqrt ((arr[x].a - arr[y].a)*(arr[x].a - arr[y].a) + (arr[x].b - arr[y].b)*(arr[x].b - arr[y].b));
			if(min_distance(final,temp)== temp)
			{
				final=temp;
			}
		}
	}

	clock_t end = clock();
	double time_spent = ((double)(end - begin) / CLOCKS_PER_SEC) * 1000.0;
	printf("Time taken by Brute force: %f milisec \n", time_spent );
	return final;
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
	clock_t begin = clock();
	int num;
	struct test *arr;
	char data[100];
	n_lines= findNumLines(fread);

	temp_x= (long long *) malloc(n_lines * sizeof(long long));
	temp_y= (long long *) malloc(n_lines * sizeof(long long));

	arr= (struct test *) malloc(n_lines * sizeof(struct test));

	for(int u=0; u<= n_lines; u++)
	{
		fgets(data, 100, fread);
		sscanf(data, "%lld %lld", &temp_x[u], &temp_y[u]);
		arr[u].a=temp_x[u];
		arr[u].b=temp_y[u];

	}
    int n = sizeof(arr) / sizeof(arr[0]);
    qs(arr, n_lines);

  		int mid= n_lines/2;
			float minL= FLT_MAX;
			float minR= FLT_MAX;
			float dis= FLT_MAX;
			for(int x=0; x< mid; x++)
			{
				for(int y=x+1; y< mid; y++)
				{
					dis=sqrt 	((arr[x].a - arr[y].a)*(arr[x].a - arr[y].a) + (arr[x].b - arr[y].b)*(arr[x].b - arr[y].b));
					if(min_distance(minL,dis) == dis)
					{
						minL=dis;
					}
				}
			}
			for(int x=mid+1; x<= n_lines; x++)
			{
				for(int y=x+1; y<= n_lines; y++)
				{
					dis=sqrt ((arr[x].a - arr[y].a)*(arr[x].a - arr[y].a) + (arr[x].b - arr[y].b)*(arr[x].b - arr[y].b));
					if(min_distance(minR,dis)== dis)
					{
						minR=dis;
					}
				}
			}
			float min_dis= min_distance(minL, minR);
			int midline= round(min_dis);

		 int sec_l= mid-midline;
		 int sec_r= mid+midline;

		 float final = FLT_MAX;
		 float temp= FLT_MAX;

		 for(int x= sec_l ; x<= sec_r; x++)
		 {
			 for(int y=x+1; y<= sec_r; y++)
			 {
				 temp=sqrt ((arr[x].a - arr[y].a)*(arr[x].a - arr[y].a) + (arr[x].b - arr[y].b)*(arr[x].b - arr[y].b));
				 if(min_distance(final,temp)== temp)
				 {
					 final=temp;
				 }
			 }
		 }
		 float shortest= min_distance(final, min_dis);
		 clock_t end = clock();
		 float time_spent = ((float)(end - begin) / CLOCKS_PER_SEC) * 1000.0;
		 printf("Time taken by Divide and Conquer: %f milisec \n", time_spent );
		 float shortestbrute= bruteforce(argv[1]);
		 write_to_file(argv[2],shortest,shortestbrute);
  }

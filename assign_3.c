#include <stdio.h>
#include <stdlib.h>

int findNumLines()
{
	FILE *fp;

	fp = fopen("input.txt", "r");
  int numLines = 0;
  char str[100];

  while(!feof(fp))
	{
    fgets(str, 100, fp);
    numLines++;
  }

  numLines--;
	return numLines;
}
void path_print (int p[][12], int a, int b, FILE *f)
{
		if (p[a][b] != 0)
		{
			path_print(p,a, p[a][b],f);
			fprintf(f,"node %d->", p[a][b]);

			path_print (p,p[a][b],b,f);
		}
 }
int main(int argc,  char** argv)
{
	if (argc != 3 )
  {
    perror("Insufficient number of arguments. \n");
    exit(1);
  }
	int lines= findNumLines();
	int a[lines];
	int b[lines];
	int c[lines];
	FILE *myFile;
	myFile = fopen(argv[1], "r");

	int  x = 0;
	int  y =0;
	int  z = 0;

	for (int i = 0; i < (lines * 3); i++)
	{
			if(i % 3 == 0 || i == 0)
			{
				fscanf(myFile, "%d", &a[x]);
				x++;
			}
			if(i % 3 == 1)
			{
				fscanf(myFile, "%d", &b[y]);
				y++;
			}
			if(i % 3 == 2)
			{
				fscanf(myFile, "%d", &c[z]);
				z++;
			}
		}

	int dist[12][12];
	int path[12][12];
	for (int i = 1; i <= 11; i++)
	{
					for (int j = 1; j <= 11; j++)
					{
						path[i][j] = 0;
							if (i==j)
							dist[i][j]=0;
							else
							dist[i][j]= 11111111;
					}
	}




	int o = 0 , t=0, u=0;
	for (int i = 0; i < 30; i++)
	{
			int p1 = a[i];
			int p2 = b[i];
			int di = c[i];
			dist[p1][p2] = di;

	}
	int k,i,j;

	for (k = 1; k <= 11; k++)
	{
				for (i = 1; i <= 11; i++)
				{
						for (j = 1; j <= 11; j++)
						{
								if ((dist[i][k] + dist[k][j] < dist[i][j]) && (i!=j))
								{
									path[i][j]= k;
										dist[i][j] = dist[i][k] + dist[k][j];
								}

						}
				}
		}
	FILE *f = fopen(argv[2], "w");
			if (f == NULL)
			{
    		printf("Error opening file!\n");
    		exit(1);
			}
			for (int i = 1; i <= 11; i++)
			{
			        for (int j = 1; j <= 11; j++)
			        {

								if(i != j)
								{
									fprintf(f," Node %d to node %d is %d. Path is: node %d-> " ,i,j, dist[i][j],i);
									path_print(path, i,j,f);
									fprintf(f,"node %d", j);
									fprintf(f,"\n");
								}
			        }

			}

}

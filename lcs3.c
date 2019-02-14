#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int find_max(int x,int  y, int z)
{

  if(x > y && x>z)
  {
    return x;
  }
  if(z > y && z>x )
  {
    return z;
  }
  return y;
}
int main(int argc ,  char** argv)
{
  if (argc != 4 )
  {
    perror("Insufficient number of arguments. \n");
    exit(1);
  }
  int len1= strlen(argv[1]);
  int len2= strlen(argv[2]);
  int len3= strlen(argv[3]);

  char str1[len1], str2[len2], str3[len3];
  strcpy(str1,argv[1]);
  strcpy(str2,argv[2]);
  strcpy(str3,argv[3]);
  //printf("%s\n",str1 );
  //printf("%s\n",str2 );
  //printf("%s\n",str3 );
int a, b, c;
   a = strlen(str1);
   b = strlen(str2);
   c = strlen(str3);
int z=0;
int lcs[a+1][b+1][c+1];
  for (int x=0; x<=a; x++)
    {
        for (int y=0; y<=b; y++)
        {
            for (int z=0; z<=c; z++)
            {
                if (x == 0 || y == 0|| z ==0)
                    lcs[x][y][z] = 0;

                else if (str1[x-1] == str2[y-1] && str1[x-1]==str3[z-1])
                {
                    lcs[x][y][z] = lcs[x-1][y-1][z-1] + 1;
                }
                else
                {
                  int t= find_max(lcs[x-1][y][z],lcs[x][y-1][z]);
                    lcs[x][y][z] = find_max(lcs[x-1][y][z],lcs[x][y-1][z],lcs[x][y][z-1]);
                }
            }
        }
    }
    //for (int x=0; x<=a; x++)
  //    {
        //  for (int y=0; y<=b; y++)
        //  {
            //  for (int z=0; z<=c; z++)
          //    {
          //        printf(" %d ", lcs[x][y][z]);
          //     }
        //    }
      //}
    int LCScopy[a + 1][b + 1][c+1];

    for (int x=0; x<=a; x++)
      {
          for (int y=0; y<=b; y++)
          {
              for (int z=0; z<=c; z++)
              {
                  LCScopy[x][y][z]= lcs[x][y][z];
                }
            }
      }

    int size_lcs = lcs[a][b][c];
    printf("Length of LCS is: %d \n", lcs[a][b][c]);
    char* lcsString = (char*)malloc((size_lcs + 1) * sizeof(char));
        while (LCScopy[a][b][c] != 0)
        {
              lcsString[--size_lcs] = str2[a - 1];
            a--;
            b--;
            c--;
          }

   printf("LCS is %s \n", lcsString);
}

#include <stdlib.h>
#include <stdio.h>
int vertices = 15;
int arr[15][15];
  int color[15];
int c=0;
void min_courses( int x)
{
  int y;
  c++;
  color[x]= 1;// white
  for( int z=0; z< vertices; z++)
  {
    for( y=0; y< z; y++)
    {
      if(!color[y] && arr[z][y])
      {
        min_courses(y);
      }
  }
}

}
int main()

{
  for(int x= 0; x< vertices ; x++)
  {
    for(int y=0; y< vertices; y++)
    {
      arr[x][y] = 0;
    }
  }
  arr[4][2]=1;
  arr[5][4]=1;
  arr[6][1]=1;
  arr[6][3]=1;
  arr[7][4]=1;
  arr[8][5]=1;
  arr[8][6]=1;
  arr[9][7]=1;
  arr[10][9]=1;
  arr[11][8]=1;
  arr[12][3]=1;
  arr[13][6]=1;
  arr[14][4]=1;
  arr[14][6]=1;
  arr[15][14]=1;
  /*for(int x= 0; x< vertices ; x++)
  {
    for(int y=0; y< vertices; y++)
    {
      printf("%d " ,arr[x][y]);
    }
    printf("\n" );
  }  */


  for(int y=0; y< vertices; y++)
  {
    color[y] = 0;  //black
  }


  min_courses(0);
printf("Minimum number of semesters is %d \n", c);

}

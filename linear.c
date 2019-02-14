#include <stdio.h>

int find_max(double x,double  y, double z)
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

int main()
{
  /* The 3 constraint equations are as follows:
      60x + 60y <= 300
      12x + 6y <= 36
      10x + 30y <= 90
  */

  //Finding the two points for line for eqn. 1

  //putting x=0
  double y1= (300 - (0*60)) / 60;


  // putting y=0

  double x1=(300 - (0*60)) / 60;


//Finding the two points for line for eqn. 2
    //Putting x=0
    double y2= (36-(12*0)) / 6;

    //putting y=0

    double x2= (36 - (6*0))/12;

    //Finding the two points for line for eqn. 3
        //Putting x=0
        double y3= (90-(10*0)) / 30;

        //putting y=0

        double x3= (90 - (30*0))/10;

        double cornerX=0,cornerY=0;
        //Finding the largest corner points for x axis

      cornerX = find_max(x1,x2,x3);
      cornerY = find_max(y1,y2,y3);

      //Now we have the two corner points, (cornerX,0) and (0, cornerY)

// Converting the 3 equations to the ax + by = c, we get

 int a1 = 60, b1= 60, c1=300, a2= 12, b2= 6, c2= 36, a3= 10, b3=30, c3=90;

 //Solving for the first 2 equations.

    double t = (a1 * b2) - (a2 * b1);

    double intsectionX1 = ((b2 * c1) - (b1 * c2)) / t ;
    double intsectionY1 = ((a1 * c2) - (a2 * c1)) / t ;

       //Solving for the equations 1 and 3.

          double t2 = (a1 * b3) - (a3 * b1);

          double intsectionX3 = ((b3 * c1) - (b1 * c3)) / t2 ;
          double intsectionY3 = ((a1 * c3) - (a3 * c1)) / t2 ;



          /*Now we have all the end points
              (cornerX,0)
              (0,cornerY)
              (intsectionX1, intsectionY1)
              (intsectionX2, intsectionY2)
              (intsectionX3, intsectionY3)
        */

        // Now we find the maximum value of by putting the abouve values

        double z1= (.12 * cornerX) + (.15 * 0);
        double z2= (.12 * 0) + (.15 * cornerY);
        double z3= (.12 * intsectionX1) + (.15 * intsectionY1);
        double z4= (.12 * intsectionX3) + (.15 * intsectionY3);

        //Now we find the Minimum value of z

        double arr[5];
        arr[0]= z1;
        arr[1]= z2;
        arr[2]= z3;
        arr[3]= z4;

        double smallZ = z1;
        for ( int x= 0; x< 4 ; x++)
        {
          if(arr[x] < smallZ)
          smallZ = arr[x];
        }

        if(smallZ == z1)
        {
          printf("Minimum number of Drink X = %f \n",cornerX );
          printf("Minimum number of Drink Y = %d \n",0 );
        }
        if(smallZ == z2)
        {
          printf("Minimum number of Drink X = %d \n", 0 );
          printf("Minimum number of Drink Y = %f \n",cornerY );
        }
        if(smallZ == z3)
        {
          printf("Minimum number of Drink X = %1f \n",intsectionX1 );
          printf("Minimum number of Drink Y = %f \n", intsectionY1 );
        }
        if(smallZ == z4)
        {
          printf("Minimum number of Drink X = %1f \n", intsectionX3 );
          printf("Minimum number of Drink Y = %f \n",intsectionY3 );
        }

}

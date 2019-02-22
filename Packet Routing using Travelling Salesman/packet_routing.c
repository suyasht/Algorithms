#include<stdio.h>
#include<stdlib.h>

int city_list[4][4];
int traversed[10];
int n,cost=0;

void node_visit(int node);     //used to calculate the total time taken
int smallest_distance(int c); //used to calulate the smalles distance between vertices
int main()
{
	int starting=0;
       	printf("Enter the number of hosts: ");
        scanf("%d",&n);
        printf("\nEnter the Cost Matrix\n");

        for(int x=0;x < n;x++)
        {
            printf("\nEnter Row: %d\n",x+1);

            for(int y=0;y < n;y++)
	    {
                scanf("%d",&city_list[x][y]);
	    }
            traversed[x]=0;
        }
    printf("\n\nThe Path is:\n");
    node_visit(starting);
    printf("\n\nMinimum time taken is %d\n ",cost);
    return 0;
}
int smallest_distance(int c)
{
    int new_cost=999;
    int infi_node=999,min;
    for(int i=0;i < n; i++)
    {
        if(( city_list [c][i] != 0) && ( traversed [i] == 0) && (city_list [c][i] + city_list [i][c] < infi_node))
            {
                infi_node=city_list[i][0]+city_list[c][i];
                min=city_list[c][i];
                new_cost=i;
            }
    }
    if(infi_node!=999)
     {
	cost+=min;
     }
    return new_cost;
}
void node_visit(int node)
{
    int i,visited_node;
    traversed[node]=1;
    printf("%d--->",node+1);
    visited_node=smallest_distance(node);
    if(visited_node==999)
    {
        visited_node=0;
        printf("%d",visited_node+1);
        cost = cost + city_list[node][visited_node];
        return;
    }
    node_visit(visited_node);
}


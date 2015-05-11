#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>
#define ZERO 0
#define MAX 7

int i,j;

 /*void ReadMatrix(int cost[MAX][MAX]){


           if (cost[1][1]>ZERO){
                printf("it can be");


           }

        }

*/

int nodeG (int cost[int x][int y])
{

    for (y = 0; y < MAX; y++)
    {
        if( cost[x][y]== ZERO )
        printf("The content can not be send\n");
        else
        printf("The content can be send to other nodes\n");


    }
}



int main()

{ int i,j;
    int cost[MAX][MAX]={{ZERO,4,7,ZERO,ZERO,ZERO,ZERO},
                       {4,ZERO,3,4,7,ZERO,ZERO},
                       {7,3,ZERO,4,7,ZERO,ZERO},
                       {ZERO,4,4,ZERO,5,4,ZERO},
                       {ZERO,7,7,5,ZERO,2,5},
                       {ZERO,ZERO,ZERO,4,2,ZERO,3},
                       {ZERO,ZERO,ZERO,ZERO,5,3,ZERO}};
                      // weight(node, cost[MAX][MAX]);
                    for(i=0;i<MAX;i++)
                    {
                        for(j=0;j<MAX;j++){


                            printf("x[%d] [%d]=%d \n",i,j,cost[i][j]);
                        }
                    }
                     /*if(cost[1][2]==0)
                        printf("The content can not be send \n");
                     else
                        printf("the content can be send\n");
                       */
                        nodeG(cost[1][0]);

// ReadMatrix(cost);
    return 0;
}

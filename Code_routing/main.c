#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 7
#define INFINITE 998
int current;
int allselected(int *selected)
{
  int i;
  for(i=0;i<MAX;i++)
    if(selected[i]==0)
      return 0;
  return 1;
}



void shortpath(int cost[][MAX],int *preced,int *distance)
{
  int selected[MAX]={0};
  current=0;
  int i,k,dc,smalldist,newdist;
  for(i=0;i<MAX;i++)
    distance[i]=INFINITE;
  selected[current]=1;
  distance[0]=0;
  current=0;
  while(!allselected(selected))
  {
    smalldist=INFINITE;
    dc=distance[current];
    for(i=0;i<MAX;i++)
    {
      if(selected[i]==0)
      {
        newdist=dc+cost[current][i];
        if(newdist<distance[i])
        {
          distance[i]=newdist;
          preced[i]=current;
        }
        if(distance[i]<smalldist)
        {
          smalldist=distance[i];
          k=i;
        }
      }
    }
    current=k;
    selected[current]=1;
   }
}
 int calculateWeight(int xx1, int xx2, float yy1, float yy2)
{
    int temp1=yy1-xx1;
    int temp2=yy2-xx2;
    int z= sqrt (pow(temp1,2)+pow(temp2,2));
    //printf("the value is %d", z);
   return z;
}
/*
int GetIntNodes()
{
    int minDistance = INFINITY;
    int i, node, distance[MAX];

    for(i=0;i<MAX;i++)
    {
        if((minDistance >= distance[i]))
        {
            minDistance = distance[i];
            node = i;
        }
    }
    return node;
}

*/


int main()
{


     int x = calculateWeight(0,0,2,4);
     int y = calculateWeight(0,0,3,7);
     int z = calculateWeight(7,5,3,7);
     int a = calculateWeight(2,4,6,10);
     int b = calculateWeight(6,10,11,11);
     int c = calculateWeight(8,9,11,11);
     int d = calculateWeight(7,5,8,9);
     int e = calculateWeight(6,10,8,9);
     int f = calculateWeight(7,5,3,7);
     int g = calculateWeight(2,4,6,10);
     int h = calculateWeight(7,5,6,10);
     int j = calculateWeight(2,4,3,7);
    printf("%d %d %d %d %d %d %d %d %d %d %d %d \n", x,y,z,a,b,c,d,e,f,g,h,j);


  int cost[MAX][MAX]=
     {{INFINITE,x,y,INFINITE,INFINITE,INFINITE,INFINITE},
      {x,INFINITE,j,z,g,INFINITE,INFINITE},
      {y,j,INFINITE,f,a,INFINITE,INFINITE},
      {INFINITE,z,f,INFINITE,h,d,INFINITE},
      {INFINITE,g,a,h,INFINITE,e,b},
      {INFINITE,INFINITE,INFINITE,d,e,INFINITE,c},
      {INFINITE,INFINITE,INFINITE,INFINITE,b,c,INFINITE}};

  printf("The source node is %d \n", current) ;
  int i,preced[MAX]={0},distance[MAX];
  shortpath(cost,preced,distance);
  for(i=0;i<MAX;i++)
  {
    char b= (char)(65+i);

//    printf("%d", GetIntNodes());
    printf("%c ", b);
    printf("%d\n", distance[i]);
  }

 //   printf("")

  return 0;
}

//selecting the nodes that traverse through the path

// copying & storing the content in all the nodes traversed

// cc2 wants the content, accept name of the content (string)

// send request to adjoining nodes by selecting adjoining nodes -------- logic same as discussed before using the matrix
// table

// lookup and see if the name requested for matches the same name in the adjoining nodes
//if (yes)
// take the nodes that have the registry

//if node = E, take from it

// else take from node where least path

//else(run the normal source to destination search path)

// copy the content if it does to cc2

//somewhere when required; not sure where
// mapping of alphabets to matrix


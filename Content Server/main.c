#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct contentcache{

  int content_file_size;
  int content_file_id;
  char content_file_name[10];
// if more than one searches are to be made consequently
 // int searchmore = 0;
  struct contentcache *content;
};
struct contentcache *start = NULL;
struct contentcache *finish = NULL;

void display()
{
    struct contentcache *p;
    if (start==NULL)
   {
       printf("List is Empty\n");
       return;
   }

   p=start;
   while(p!=NULL)
    {
    printf("content_file_size:%d\n", p->content_file_size);
    printf("content_file_id:%d\n",p->content_file_id);
    printf("content_file_name:%s\n", p->content_file_name);
    p=p->content;
    }

}
void add(int num, int file_id, char file_name[10])
{
    struct contentcache *temp;
    temp =(struct contentcache*)malloc(sizeof(struct contentcache));
    temp->content_file_size=num;
    temp->content_file_id=file_id;
    //temp->content_file_name[10]=file_name[10];
    strcpy(temp->content_file_name, file_name);
    temp->content=NULL;
    if (start == NULL)
    {
        start = temp;
        finish = temp;
    } else {
        finish->content = temp;
        finish = temp;
    }
    //return start
}
 void searchcontent( int num)
 {   struct contentcache *temp1;
       temp1=start;
       while(temp1!=NULL){
        if (temp1->content_file_size==num){
            printf("the content file_size %d is found \n",num);
// if more than one search is made consequently
//            searchmore++;
            return ;
       }


       temp1=finish;
       temp1=temp1->content;

          printf("the content file_size %d is not found \n", num);
 }
 }

/*
void StoreInAllNodes(int node, struct contentcache *temp1 , struct contentcache *temp2)
{



    printf("content_file_size:%d\n", p->content_file_size);
    printf("content_file_id:%d\n",p->content_file_id);
    printf("content_file_name:%s\n", p->content_file_name);
    p=p->content;



}
*/
int main(){
//struct contentcache *start=NULL;
int choice,num ;
int file_id;
char file_name[10];
while(1){
    printf("1. Display\n");
    printf("2.Add the node in List\n");
    printf("3.Search the content\n");
    scanf("%d",&choice);
    switch(choice){

case 1:
      //display(start);
      display();

      break;
case 2:
    printf("Enter the size of the file:\n");
    scanf("%d", &num);
    printf("enter the id of the file:\n");
    scanf("%d", &file_id);
    printf("enter the name of the file:\n");
    scanf("%s", &file_name);

    //start = add(start,num,file_id, file_name);
    add(num,file_id, file_name);

    break;
case 3:
    printf("Enter the number to be searched\n");
    scanf("%d", &num);
    searchcontent( num );

    break;
default:
    printf("invalid command\n");



    }

}
}

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

  struct contentcache{
  int content_file_size;
  int content_file_id;
  char content_file_name[50];
  char content_file_type[50];
  struct contentcache *content;
};


//struct contentcache *start = NULL;
//struct contentcache *finish = NULL;

void add(struct contentcache **q,int num, int file_id , char file_name[50],char file_type[50])
{
    struct contentcache *temp;
    temp = *q;
  //   printf("%p \n", );
//     break;

    if (*q = NULL)
    {
      *q = malloc ( sizeof ( struct contentcache ) ) ;
      temp = *q ;


    }

    else
    {
        while ( temp -> content != NULL )
            temp = temp -> content ;

            temp -> content = malloc ( sizeof ( struct contentcache ) ) ;
            temp = temp -> content ;

    }

//    temp =(struct contentcache*)malloc(sizeof(struct contentcache));
    temp->content_file_size=num;
    temp->content_file_id=file_id;
    strcpy(temp->content_file_name, file_name);
    strcpy(temp->content_file_type, file_type);
      temp -> content = NULL;
  /*
    if (start == NULL)
    {
        start = temp;
        finish = temp;
    } else {
        finish->content = temp;
        finish = temp;
    }
    */
    //return start
}

void StoreInAllNodes(struct contentcache *q , struct contentcache **s)
{   if (q!= NULL)
{
   *s = malloc(sizeof(struct contentcache));
    (*s)->content_file_size=q->content_file_size;
    (*s)->content_file_id=q->content_file_id;

  strcpy((*s)->content_file_name,q->content_file_name);
  strcpy((*s)->content_file_type,q->content_file_type);
    (*s)->content=NULL;
    StoreInAllNodes(q->content, &((*s)->content));
}



/*
    temp2->content_file_size = content->content_file_size;
    temp2->content_file_id = content->content_file_id;
     strcpy(temp2->content_file_name,content->content_file_name);
     strcpy(temp2->content_file_type,content->content_file_type);
   // char content_file_type[10];


    printf("content_file_size:%d\n", temp2->content_file_size);
    printf("content_file_id:%d\n",temp2->content_file_id);
    printf("content_file_name:%s\n", temp2->content_file_name);
    printf("content_file_type:%s\n", temp2->content_file_type);
    //temp2=temp2->content;
*/

}

void display(struct contentcache *t){

while(t!=NULL)
    {

 printf("%d \n", t->content_file_size);
 printf("%d \n", t->content_file_id);
 printf("%s \n", t->content_file_name);
printf("%s \n", t->content_file_type);
 t=t->content;
}
}

int main()
{
     struct contentcache *a,*b;
     a=b=NULL;


  //  printf("Hello world!\n");
    /* struct contentcache *p;
     struct contentcache *q;
     int  content_file_size =100;
     int content_file_id=150;
     char content_file_name="prath";
     char content_file_type="jpg";
     StoreInAllNodes(p, q);
     */

//int choice,num ;
//int file_id;
//char file_name[10];
//char file_type[10];


      add(&a,123,345,"Prath","jpg");
      display(a);
      StoreInAllNodes(a,&b);
      display(b);

return 0;
}

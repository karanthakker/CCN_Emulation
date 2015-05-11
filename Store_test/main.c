#include <stdio.h>
#include <conio.h>
#include <string.h>
//#include <alloc.h>

/* structure containing a data part and link part */
struct node
{
    int data ;
    int size ;
    char name [50];
    struct node *link ;
} ;

//void append ( struct node **, int, int ) ;
//void copy ( struct node *, struct node ** ) ;
//void display ( struct node * ) ;

void main( )
{
    struct node *first, *second ;
    first = second = NULL ;  /* empty linked lists */


    append ( &first, 123,345, "Karan") ;
/*    append ( &first, 2 ) ;
    append ( &first, 3 ) ;
    append ( &first, 4 ) ;
    append ( &first, 5 ) ;
    append ( &first, 6 ) ;
    append ( &first, 7 ) ;
*/
//    clrscr( ) ;
    display ( first ) ;

    copy ( first, &second ) ;

    display ( second ) ;
    return 0;
}

/* adds a node at the end of the linked list */
void append ( struct node **q, int num, int size, char name [50] )
{
    struct node *temp ;
    temp = *q ;

    if ( *q == NULL )  /* if the list is empty, create first node */

    {
        *q = malloc ( sizeof ( struct node ) ) ;
        temp = *q ;
    }
    else
    {
        /* go to last node */
while ( temp -> link != NULL )
            temp = temp -> link ;

        /* add node at the end */

        temp -> link = malloc ( sizeof ( struct node ) ) ;
        temp = temp -> link ;
    }

    /* assign data to the last node */

    temp -> data = num ;
    strcpy(temp->name, name);
    temp -> size = size ;
    temp -> link = NULL ;
}

/* copies a linked list into another */
void copy ( struct node *q, struct node **s )
{
    if ( q != NULL )
    {
        *s = malloc ( sizeof ( struct node ) ) ;

        ( *s ) -> data = q -> data ;
        ( *s ) -> size = q -> size ;
        strcpy(( *s ) -> name, q -> name);

        ( *s ) -> link = NULL ;

        copy ( q -> link, &( ( *s ) -> link ) ) ;
    }
}

/* displays the contents of the linked list */
void display ( struct node *q )
{
    printf ( "\n" ) ;

    /* traverse the entire linked list */
while ( q != NULL )
    {
        printf ( "%d ", q -> data ) ;
        printf("%d", q -> size) ;
        printf("%s", q -> name) ;

        q = q -> link ;
    }
}

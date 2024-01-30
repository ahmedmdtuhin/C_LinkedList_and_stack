#include<stdio.h>
#include<stdlib.h>


struct node 
{
int info;
struct node *prev, *next;
};
struct node *start=NULL;

void insertAsFirstNode()
{
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    printf("Enter a number: ");
    scanf("%d",&n->info);
    n->prev=NULL;
    n->next=NULL;
    if (start==NULL)
    {
       start=n; 
    }
    else
    {
       start->prev=n; 
       n->next=start;
       start=n;
    }
}

void deleteFisrtNode()
{
    struct node *r;
    if(start==NULL){
        printf("List is empty.");
    }
    else
    {
    r=start;
    start=start->next;
    start->prev=NULL;
    free(r);

    }
}

void viewList()
{
struct node *t;
    if(start==NULL)
    {
        printf("List is empty");
    }
    else
    {
    t=start;
    while(t->next!=NULL)
    {
    printf(" %d",t->info);
    t=t->next;
    }
    }
}

int menu()
{
    int ch;
    printf("\n 1.Add value to the list ");
    printf("\n 2.Delete First value ");
    printf("\n 3.View list ");
    printf("\n 4.Exit ");
    printf("\n\n Enter your choice: ");
    scanf("%d",&ch);

    return (ch);

}

void main()
{
    while(1){
        switch(menu())
        {
            case 1:
                  insertAsFirstNode();
                  break;
            case 2:
                  deleteFisrtNode();
                  break;
            case 3:
                  viewList();
                  break;
            case 4:
                 exit(0);
            default:
            printf("Invalid choice.");
            break;
    

        }

    }

}
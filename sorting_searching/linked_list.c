#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data ;
    struct Node*next;

};
int main ()
{   struct Node *newf=NULL;
    struct Node *head=NULL;
    struct Node *second=NULL;
    struct Node *third=NULL;
    struct Node *fourth=NULL;
    struct Node *fifth=NULL;
    struct Node *newe=NULL;
    newf=(struct Node*)malloc(sizeof(struct Node));
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth=(struct Node *)malloc(sizeof(struct Node));
    fifth=(struct Node *)malloc(sizeof(struct Node));
    newe=(struct Node  *)malloc(sizeof(struct Node));
    if (!head || !second || !third) {
        printf("Memory allocation failed\n");
        return 1;
    }
     head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = fifth;

    fifth->data = 50;
    fifth->next = NULL;

    newe->data=60;
    newe->next=NULL;
 
    newf->data=1;
    newf->next=head;
    head=newf;
    struct Node *p =head;
    
    while ( p->next!= NULL)
    {
       
        p= p->next;
    }
    p->next=newe;
    
 struct Node *temp =head;
    while ( temp!= NULL)
    {
        printf("%d -> ", temp->data);
        temp= temp->next;
    }printf("NULL\n");

    // Free allocated memory
    temp=head;
    while (temp!= NULL)
    {
        struct Node *next = temp->next;
        free(temp);
        temp= next;
    }

    return 0;
}




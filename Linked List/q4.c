#include<stdio.h>
#include<malloc.h>

typedef struct node{
int data;
struct node* next;
}NODE;

NODE* makenode(int data)
{
    NODE* temp=(NODE*) malloc(sizeof(NODE));
    temp->data=data;
    temp->next=NULL;
    return temp;
}

NODE* create()
{
    NODE* l=NULL;
    return l;
}

NODE* inserthead(NODE* l,int data)
{
    NODE *temp=makenode(data);
    temp->next=l;
    return temp;
}

NODE* inserttail(NODE* l,int data)
{
   if(!l){return makenode(data);}

   NODE* temp=l;
   while(temp->next)
   {
       temp=temp->next;
   }

   temp->next=makenode(data);

   return l;
}

void display(NODE* l)
{
     while(l)
    {
        printf("%5d",l->data);
        l=l->next;
    }
    printf("\n");
}

NODE* copy_rec(NODE *l)
{
    if(!l){return l;}

    NODE* temp=makenode(l->data);

    temp->next=copy_rec(l->next);

    return temp;
}


int main()
{
    int n1;
    int n2;
    int x;

   NODE *l1=create();
   NODE *l2=create();
   NODE *l3=create();


    printf("enter the number of elements in list 1: ");
    scanf("%d",&n1);

    for(int i=0;i<n1;i++)
    {
        scanf("%d",&x);
        l1=inserttail(l1,x);
    }

    printf("enter the number of elements in list 2: ");
    scanf("%d",&n2);

    for(int i=0;i<n2;i++)
    {
        scanf("%d",&x);
        l2=inserttail(l2,x);
    }

    printf("list 1:  ");
    display(l1);

    printf("list 2:  ");
    display(l2);


    l3=copy_rec(l1);

    NODE* temp=l3;

    while(temp->next)
    {
        temp=temp->next;
    }

    temp->next=copy_rec(l2);

    printf("concatenated list:  ");
    display(l3);



    return 0;

}

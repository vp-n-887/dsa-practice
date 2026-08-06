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

NODE* copy_iter(NODE *l)
{
    if(!l){return l;}

    NODE* temp=makenode(l->data);
    NODE* t=temp;

    l=l->next;

    while(l)
    {
      t->next=makenode(l->data);
      t=t->next;
      l=l->next;
    }

    return temp;
}


int main()
{
    int n;
    int x;
    int flag=1;
   NODE *l=create();


    printf("enter the number of elements: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        l=inserttail(l,x);
    }
    display(l);

    NODE* c1=copy_rec(l);
    NODE* c2=copy_iter(l);

    printf("\ncopy using recursion: ");
    display(c1);
     printf("\ncopy using iteration: ");
    display(c2);
    return 0;
}

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

int middle(NODE* l)
{
    NODE* t1=l;
    NODE* t2=l;

    while(t2!=NULL&&t2->next!=NULL)
    {
        t1=t1->next;
        t2=t2->next->next;
    }

    return t1->data;
}

int main()
{
    int n;
    int x;
   NODE *l=create();


    printf("enter the number of elements: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        l=inserttail(l,x);
    }

    display(l);

    printf("middle element: ");
    printf("%d",middle(l));

    return 0;

}

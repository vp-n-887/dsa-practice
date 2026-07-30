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

int count(NODE *l)
{
    int count=0;
    while(l)
    {
        count++;
        l=l->next;
    }
    return count;
}

int pos(NODE* l,int data)
{
    int pos=1;
    while(l)
    {
        if(l->data==data){return pos;}
        pos++;
        l=l->next;
    }
    return pos;
}

int sum(NODE *l)
{
    int s=0;
    while(l)
    {
        s=s+l->data;
        l=l->next;
    }
    return s;
}

void print_rev(NODE* l)
{
    if(l)
    {
        print_rev(l->next);
        printf("%5d",l->data);
    }
}



void display(NODE* l)
{
     while(l)
    {
        printf("%5d",l->data);
        l=l->next;
    }
}

void create(NODE **l)
{
    *l=NULL;
}



int main()
{
    NODE *l1=makenode(500);
    l1=inserthead(l1,200);
    l1=inserthead(l1,600);
    l1=inserttail(l1,300);



    display(l1);
    l1=inserttail(l1,400);
    printf("\n");
    display(l1);
    printf("\n");
    print_rev(l1);
    printf("\n");
    printf("%d",count(l1));
    printf("\n%d",pos(l1,400));
    printf("\n%d",sum(l1));

    printf("\n\nl1 after double pointer:");
    create(&l1);
    display(l1);

    l1=makenode(500);
    display(l1);

    return 0;

}

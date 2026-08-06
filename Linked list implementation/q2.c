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



void display(NODE* l)
{
     while(l)
    {
        printf("%5d",l->data);
        l=l->next;
    }
    printf("\n");
}

int main()
{
    int n1;
    int n2;
    int x;
    int flag=1;

   NODE *l1=create();
   NODE *l2=create();


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



    while(l1&&l2)
    {
        if((l1->data)!=(l2->data)){flag=0;break;}
        l1=l1->next;
        l2=l2->next;

    }

    if(l1!=NULL||l2!=NULL){flag=0;}


    if(flag){printf("\nl1 and l2 are same");}
    else{printf("\nl1 and l2 are not same");}

    return 0;

}

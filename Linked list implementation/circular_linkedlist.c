#include<stdio.h>
#include<malloc.h>

typedef struct node{
    int val;
    struct node* next;
}NODE;

NODE* makenode(int val,NODE* next)
{
    NODE* l=(NODE*)malloc(sizeof(NODE));
    l->val=val;
    l->next=next;
    return l;
}

NODE* insert_circ_beg(NODE* l,int data)
{
    if(!l){NODE* t=makenode(data,NULL);t->next=t; return t;}

    NODE* t=makenode(data,l->next);
    l->next=t;

    return l;
}

NODE* insert_circ_tail(NODE*l,int data)
{
    if(!l){NODE* t=makenode(data,NULL);t->next=t; return t;}

    NODE* t=makenode(data,l->next);
    l->next=t;

    l=t;
    return l;
}


void display(NODE* l)
{
   NODE*t=l->next;

   do{
    printf("%5d",t->val);
    t=t->next;
   }
   while(t!=l->next);
}


int main()
{
    NODE* l1=NULL;

    l1=insert_circ_beg(l1,100);
    l1=insert_circ_beg(l1,200);
    l1=insert_circ_tail(l1,2000);
    l1=insert_circ_tail(l1,3000);
    l1=insert_circ_beg(l1,10);

    l1=del(l1,2000);
    display(l1);

    return 0;
}
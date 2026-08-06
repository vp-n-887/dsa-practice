#include<stdio.h>
#include<malloc.h>

typedef struct node{
    int data;
    struct node* next;
}NODE;


typedef struct{
    NODE* top;
}stack;

NODE* makenode(int data)
{
    NODE* t=(NODE*)malloc(sizeof(NODE));
    t->data=data;
    t->next=NULL;
    return t;
}

stack createstack()
{
    stack s;
    s.top=NULL;
    return s;
}

int isempty(stack s)
{
    if(s.top==NULL){return 1;}
    return 0;
}

void push(stack*s,int data)
{
    NODE* temp=makenode(data);
    temp->next=s->top;

    s->top=temp;
}

void pop(stack*s,int *data)
{
    if(isempty(*s)){*data=-1;return;}

    NODE* temp=s->top;
    *data=temp->data;

    s->top=temp->next;
    //free is the proper method but this works just fine
    //free(temp);
}

void display(stack s)
{
    int x;
    while(!isempty(s))
    {
        pop(&s,&x);
        printf("%5d",x);
    }
    /*NODE* temp=s.top;
    while(temp!=NULL)
    {
        printf("%5d",temp->data);
        temp=temp->next;
    }*/

    printf("\n");
}

int main()
{
    stack s=createstack();

    push(&s,100);
    push(&s,200);
    push(&s,300);
    display(s);

    int x;
    pop(&s,&x);
    printf("%d",x);
     pop(&s,&x);
    printf("%d",x);
     pop(&s,&x);
    printf("%d",x);
    display(s);
    return 0;
}
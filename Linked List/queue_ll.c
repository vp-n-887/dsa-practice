#include<stdio.h>
#include<malloc.h>

typedef struct node{
    int data;
    struct node* next;
}NODE;

typedef struct{
    NODE* front;
    NODE* rear;
}queue;

NODE* makenode(int data)
{
    NODE* temp=(NODE*)malloc(sizeof(NODE));
    temp->data=data;
    temp->next=NULL;
    return temp;
}

queue createqueue()
{
    queue q;
    q.front=NULL;
    q.rear=NULL;
    return q;
}

int isempty(queue q)
{
    if(q.front==NULL){return 1;}
    return 0;
}

void push(queue*q,int data)
{
    NODE* temp=makenode(data);

    if(isempty(*q))
    {
        q->front=temp;
        q->rear=temp;
    }

    else{
        q->rear->next=temp;
        q->rear=temp;
    }
}

void pop(queue* q,int* data)
{
    NODE* temp=q->front;
    *data=temp->data;

    q->front=temp->next;

    if(q->front==NULL){q->rear=NULL;}

   //not very necessary
    free(temp);
}

void display(queue q)
{
    NODE* temp=q.front;

    while(temp!=NULL)
    {
        printf("%5d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    queue q;
    q=createqueue();

    push(&q,100);
    push(&q,200);
    push(&q,300);
    push(&q,400);
    display(q);

    int x;
    pop(&q,&x);
    pop(&q,&x);

    display(q);

    return 0;
}
#include<stdio.h>
#define MAX 10

typedef struct{
    int front;
    int rear;
    char val[MAX];
}queue;

void createque(queue *q)
{
    q->front=0;
    q->rear=0;
}

int isempty(queue q)
{
    if(q.front==q.rear){return 1;}
    return 0;
}

int isfull(queue q)
{
    if((q.rear+1)%MAX==q.front){return 1;}
    return 0;
}

void enqueue(queue *q,char val)
{
    if(isfull(*q)){return;}

    q->rear=(q->rear+1)%MAX;
    q->val[q->rear]=val;
}

void dequeue(queue *q,char *val)
{
    if(isempty(*q)){return;}

    q->front=(q->front+1)%MAX;
    *val=q->val[q->front];
}

int count(queue q)
{
    return (q.rear-q.front+MAX)%MAX;
}

int ww(queue q,char a[])
{
    int i=0;
    char x;
    int period=-1;

     while(a[i]!='\0')
    {
        if(a[i]=='.'){i++;period=i;break;}
        enqueue(&q,a[i]);
        i++;
    }

    if(period==-1){return 0;}

    while(!isempty(q))
    {
        dequeue(&q,&x);
        if(x!=a[i])
        {return 0;}
        i++;
    } 

    if(a[i]!='\0'){return 0;}

    return 1;
}

int main()
{
    queue q;
    char a[50];
    
    createque(&q);
    printf("enter string: ");
    scanf("%s",a);

    if(ww(q,a)){printf("in the format w.w");}
    else {printf("not in the format w.w");}

    return 0;

}
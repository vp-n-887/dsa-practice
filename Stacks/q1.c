#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10

typedef struct{
int val[MAX_SIZE];
int top;
}stack;

stack createstack()
{
    stack s;
    s.top=0;
    return s;
}

int isempty(stack s)
{
   if(s.top==0){return 1;}
   return 0;
}

int isfull(stack s)
{
    if(s.top==MAX_SIZE-1){return 1;}
    return 0;
}
void push(stack *s,int val)
{
    if(isfull(*s)){return;}

    s->top=s->top+1;
    s->val[s->top]=val;
}

void pop(stack *s,int *val)
{
    if(isempty(*s)){return;}

    *val=s->val[s->top];
    s->top=s->top-1;

}

int peek(stack s)
{
    if(isempty(s)){return -999999999;}

    return s.val[s.top];
}

void copy(stack s1,stack *s2)
{
    stack s3;
    s3=createstack();
    int x;
    while(!isempty(s1))
    {
        pop(&s1,&x);
        push(&s3,x);
    }
    int y;
    while(!isempty(s3))
    {
       pop(&s3,&y);
       push(s2,y);
    }
}


int main()
{
    stack s1,s2,s3,s4;

    s1=createstack();
    s2=createstack();
    s3=createstack();

    int n;
    int x;

    printf("enter the number of elements: ");
    scanf("%d",&n);

    while(n)
    {
        x=rand()%100;
        if(x%2==0){push(&s2,x);}
        else if(x%2!=0){push(&s1,x);}
        n--;
    }


   copy(s1,&s3);


    printf("stack 1:\n");
    while(!isempty(s1))
    {
        int a;
        pop(&s1,&a);
        printf("%d  ",a);
    }

    printf("\nstack 2:\n");
    while(!isempty(s2))
    {
        int b;
        pop(&s2,&b);
        printf("%d  ",b);
    }


   printf("\ncopying stack1 to stack3\nstack 3: \n");
   while(!isempty(s3))
    {
        int c;
        pop(&s3,&c);
        printf("%d  ",c);
    }


    return 0;
}








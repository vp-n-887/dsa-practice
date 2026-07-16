#include<stdio.h>
#include<string.h>
#define MAX_SIZE 10


typedef struct{
char val[MAX_SIZE];
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
void push(stack *s,char val)
{
    if(isfull(*s)){return;}

    s->top=s->top+1;
    s->val[s->top]=val;
}

void pop(stack *s,char *val)
{
    if(isempty(*s)){return;}

    *val=s->val[s->top];
    s->top=s->top-1;

}

int balanced(char a[])
{
   stack s;
   s=createstack();
   char x;

   int i=0;

   while(a[i]!='\0')
   {
    if(a[i]=='[')
    {
        push(&s,a[i]);
    }
    else if(a[i]==']')
    {
        if(isempty(s)){return 0;}
        pop(&s,&x);
    }

    i++;
   }

   if(isempty(s)){return 1;}
   else {return 0;}
}

int main()
{
    char a[10];

    printf("enter sequence: ");
    gets(a);

   if(balanced(a)){printf("well balnced");}
   else {printf("not balanced");}

    return 0;
}

#include<stdio.h>
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

void print(stack s)
{
     while(!isempty(s))
    {
        char b;
        pop(&s,&b);
        printf("%c",b);
    }
}

int main()
{
    stack s1;

    s1=createstack();
    char a[10];

    printf("enter string: ");
    scanf("%s",a);

    int i=0;
    while(a[i]!='\0')
    {
        push(&s1,a[i]);
        i++;
    }

    printf("in reverse order:\n");
    print(s1);
    return 0;
}

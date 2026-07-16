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
    gets(a);

    int i=0;
    int reverse=1;
    char x;
    int period=-1;

    while(a[i]!='\0')
    {if(a[i]=='.')
        {period=i;
        break;}
        i++;
    }

    if(period==-1){printf("'.' not found");return 0;}

    i=0;


    while(a[i]!='\0')
    {
        if(i<period)
        {
           push(&s1,a[i]);
        }

        else if(i>period)
        {
            pop(&s1,&x);
            if(x!=a[i])
            {
                reverse=0;
                break;
            }
        }
        i++;

    }

    if(reverse==1){printf("in the format");}
    else {printf("not in the format");}


    return 0;

}

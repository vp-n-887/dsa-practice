#include<stdio.h>
#define MAX 10

typedef struct{
char val[MAX];
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
    if(s.top==MAX-1){return 1;}
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

int balanced(stack *s,char a[])
{
    int i=0;
    char x;

    while(a[i]!='\0')
    {
        if(a[i]>='A'&&a[i]<='Z')
        {
            push(s,a[i]);
        }

        else if(a[i]>='a'&&a[i]<='z')
        {
            if(isempty(*s)){return 0;}

            pop(s,&x);
            if(x+32!=a[i]){return 0;}
        }

        i++;
    }
   if(isempty(*s)){return 1;}
   else{return 0;}
}


int main()
{
    char a[50];
    stack s;

    s=createstack();
    printf("enter string: ");
    scanf("%s",a);

    if(balanced(&s,a)){printf("it is balanced");}
    else{printf("not balanced");}

    return 0;
}
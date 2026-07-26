#include<stdio.h>
#define MAX 10

typedef struct{
int val[MAX];
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

int main()
{
    char a[50];
    stack s;
    int i=0;
    int op1;
    int op2;
    int x;

    s=createstack();
    printf("enter postfix expression: ");
    scanf("%s",a);

    while(a[i]!='\0')
    {
        if(a[i]>='a'&&a[i]<='z')
        {
            push(&s,a[i]-'0'-'0');
        }

        else{
        pop(&s,&op2);
        pop(&s,&op1);

        switch(a[i])
        {
            case '+': {push(&s,op1+op2);break;}
            case '-': {push(&s,op1-op2);break;}
            case '*': {push(&s,op1*op2);break;}
            case '/': {push(&s,op1/op2);break;}
            case '%': {push(&s,op1%op2);break;}
        }
    }
        i++;
    }

    pop(&s,&x);

    printf("result: %d",x);
    return 0;
}
#include<stdio.h>
#include<string.h>
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

//the actual function

int isopernad(char c)
{
    if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='1'&&c<='9')){return 1;}
    return 0;
}

int isp(char c)
{
    switch(c)
    {
        case '#':{return 0;}
        case '+':{return 3;}
        case '-':{return 3;}
        case '*':{return 5;}
        case '/':{return 5;}
        case '^':{return 6;}
        case '(':{return 1;}
    }
}

int icp(char c)
{
   switch(c)
    {
        case '+':{return 2;}
        case '-':{return 2;}
        case '*':{return 4;}
        case '/':{return 4;}
        case '^':{return 7;}
        case '(':{return 8;}
        case ')':{return -1;}
    } 
}

int main()
{
    char a[50];
    stack s;
    int i=0;
    char x;

    s=createstack();
    printf("enter string: ");
    scanf("%s",a);

    push(&s,'#');
    while(a[i]!='$')
    {
        if(isopernad(a[i])){printf("%c",a[i]);}

        else if(a[i]==')')
        {
            while(s.val[s.top]!='(')
            {
                pop(&s,&x);
                printf("%c",x);
            }

            pop(&s,&x);
        }

        else
        {
            while(isp(s.val[s.top])>icp(a[i]))
            {
                pop(&s,&x);
                printf("%c",x);
            }
        push(&s,a[i]);
        }
        i++;
    }

    while(s.val[s.top]!='#')
    {
        pop(&s,&x);
        printf("%c",x);
    }

    return 0;

}
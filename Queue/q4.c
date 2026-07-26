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

int wwr(char a[],stack *s)
{
    int i=0;
    int period=-1;
    char x;

    while(a[i]!='\0')
    {
        if(a[i]=='='){period=i;i++;break;}
        push(s,a[i]);
        i++;
    }

    if(period==-1){return 0;}
    
    while(!isempty(*s))
    {
        pop(s,&x);
        if(x!=a[i]){return 0;}
        i++;
    }

    if(a[i]!='\0'){return 0;}

    return 1;
}


int main()
{
    stack s;
    char a[50];

    s=createstack();
    printf("enter string: ");
    scanf("%s",a);

    if(wwr(a,&s)){printf("in the format w.w(r)");}
    else{printf("not in the format");}

    return 0;


}
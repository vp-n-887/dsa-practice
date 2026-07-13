#include<stdio.h>

void getpoly(int p[],int n)
{
    p[0]=n;
    for(int i=1;i<=2*n;i++)
    {
        scanf("%d",&p[i]);
    }
}

void printpoly(int p[],int n)
{
    printf("\n");
    for(int i=0;i<=2*n;i++)
    {
        printf("%5d",p[i]);
    }
    printf("\n");
}

int main()
{
    int p1[50];
    int p2[50];
    int p3[50];

    int n;
    int m;

    printf("enter n and m: ");
    scanf("%d %d",&n,&m);

    printf("1st polynomial: \n");
    getpoly(p1,n);
    printpoly(p1,n);

    printf("2st polynomial: \n");
    getpoly(p2,m);
    printpoly(p2,m);

    printf("sum of polynomials: ");

    int i=1,j=1,k=0,t,p=1;
    while(i<=n&&j<=m)
    {
        if(p1[2*i]==p2[2*j]){t=p1[2*i-1]+p2[2*j-1];
        if(t)
            {
                p3[2*p-1]=t;
                p3[2*p]=p1[2*i];
                k++;
                p++;
            }
                i++;
                j++;
        }
        else if(p1[2*i]>p2[2*j])
        {
            p3[2*p]=p1[2*i];
            p3[2*p-1]=p1[2*i-1];
            i++;
            p++;
            k++;
        }

        else if(p1[2*i]<p2[2*j])
        {
            p3[2*p]=p2[2*j];
            p3[2*p-1]=p2[2*j-1];
            j++;
            p++;
            k++;
        }
    }

    while(i<=n)
    {
        p3[2*p]=p1[2*i];
        p3[2*p-1]=p1[2*i-1];
        i++;
        p++;
        k++;
    }

     while(j<=m)
    {
        p3[2*p]=p2[2*j];
        p3[2*p-1]=p2[2*j-1];
        j++;
        p++;
        k++;
    }



    p3[0]=k;

        printpoly(p3,k);
        return 0;

    }





#include<stdio.h>

int main()
{
    int m,n;

    printf("row and column of 2d sparse matrix: ");
    scanf("%d %d",&m,&n);

    int a[m][n];

    printf("values of matrix: ");

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    int triplet[50][50];
    int k=1;
    int count=0;

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]!=0){
                triplet[k][0]=i;
                triplet[k][1]=j;
                triplet[k][2]=a[i][j];
                k++;
                count++;
            }
        }
    }

    triplet[0][0]=m;
    triplet[0][1]=n;
    triplet[0][2]=count;

    //triplet no of row is no of non zerovalues +1 (1 coz we have heading)

    for(int i=0;i<count;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%5d",triplet[i][j]);
        }
        printf("\n");
    }

    return 0;
}

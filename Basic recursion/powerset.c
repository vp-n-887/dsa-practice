#include<stdio.h>

void power(int arr[10],int subset[10],int n,int index,int subsize)
{
    if(index==n)
    {
        printf("{ ");
        for(int i=0;i<subsize;i++)
        {
            printf("%d",subset[i]);
        }
        printf(" }\n");
        return;
    }


 
      //including th element
    subset[subsize]=arr[index];
    power(arr,subset,n,index+1,subsize+1);


       //excluding the elemnt
    power(arr,subset,n,index+1,subsize);




}
int main()
{

    int n;
    scanf("%d",&n);

    int a[n];

    printf("array values: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    int sub[n];
    power(a,sub,n,0,0);

    
}
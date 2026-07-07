#include<stdio.h>

void tower(int n,char source,char auxillary,char destination)
{
    if(n==1){
        printf("disk 1 is moved frm %c to %c\n",source,destination);
        return ;//the control will go back to its caller and not outside the function so if its executed due to the 1st tower call it will go back to it and will print the printf statement
    }

    tower(n-1,source,destination,auxillary);
    printf("disk %d moved from %c to %c\n",n,source,destination);

    tower(n-1,auxillary,source,destination);
}

int main()
{
    int n;
    scanf("%d",&n);

    char source='A';
    char auxillary='B';
    char destination='C';

    tower(n,source,auxillary,destination);
    return 0;
}
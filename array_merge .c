#include<stdio.h>
int main()
{
    int a[5],b[4],c[9],i,j=0;
    printf("enter the element in first array : \n");
    for(i=0 ; i<5 ; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter the element in second array : \n");
    for(i=0 ; i<4 ; i++)
    {
        scanf("%d",&b[i]);
    }
    for(i=0 ; i<5 ; i++)
    {
        c[i]=a[i];
    }
    for(i=5 ; i<9 ; i++)
    {
        c[i]=b[j];
        j++ ;
    }
    for(i=0 ; i<9 ; i++)
    {
        printf("%d\t",c[i]);
    }
    return 0;
}

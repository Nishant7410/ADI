#include<iostream>
#include<stdlib.h>
using namespace std;
int subset(int **a,int n,int sum,int arr[])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<sum;j++)
        {
            if(i==0&&j!=0)
                a[i][j]=0;
            else if(j==0)
                a[i][j]=1;
            else if(arr[i-1]>j)
                a[i][j]=a[i-1][j];
            else
                a[i][j]=a[i-1][j-arr[i-1]]+a[i-1][j];
        }
    }
    return a[n-1][sum-1];
}
int main()
{
    int n,c=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int sum;
    cin>>sum;
    int **a=(int **)malloc(sizeof(int*)*(n+1));
    for(int i=0;i<n+1;i++)
        a[i]=(int *)malloc(sizeof(int)*sum+1);
    cout<<subset(a,n+1,sum+1,arr);

}



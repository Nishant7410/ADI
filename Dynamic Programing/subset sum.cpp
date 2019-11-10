#include<iostream>
#include<stdlib.h>
using namespace std;
void subset(int **a,int n,int sum,int arr[])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<sum;j++)
        {
            if(i==0&&j!=0)
                a[i][j]=0;
            else if(j==0)
                a[i][j]=1;
            else if(arr[i]>j)
                a[i][j]=a[i-1][j];
            else
                a[i][j]=a[i-1][j-arr[i]]||a[i-1][j];
        }
    }
}
int main()
{
    int n,c=0;
    cin>>n;
    int arr[n];
    int sum;
    cin>>sum;
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int **a=(int **)malloc(sizeof(int*)*(n+1));
    for(int i=0;i<n+1;i++)
        a[i]=(int *)malloc(sizeof(int)*sum+1);
    subset(a,n+1,sum+1,arr);
    for(int i=0;i<n+1;i++)
        if(a[i][sum])
        {
            cout<<"Yes";
            c=1;
            break;
        }
        if(c==0)
            cout<<"No";
}


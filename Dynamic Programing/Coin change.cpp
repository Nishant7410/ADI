#include<iostream>
using namespace std;
int coin(int arr[],int n,int sum)
{
    int a[n][sum];
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
                a[i][j]=a[i][j-arr[i-1]]+a[i-1][j];
        }
    }
    return a[n-1][sum-1];
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int sum;
    cin>>sum;
    cout<<coin(arr,n+1,sum+1);
}

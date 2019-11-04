#include<iostream>
using namespace std;
int matrix(int arr[],int n)
{
    int res[n][n];
    for(int i=1;i<n;i++)
        res[i][i]=0;
    for(int l=2;l<n;l++)
    {
        for(int i=1;i<n-l+1;i++)
        {
            int j=i+l-1;
            res[i][j]=INT_MAX;
            for(int k=i;k<=j-1;k++)
            {
                int r=res[i][k]+res[k+1][j]+(arr[i-1]*arr[k]*arr[j]);
                if(r<res[i][j])
                    res[i][j]=r;
            }
        }
    }
    return res[1][n-1];
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<matrix(arr,n);
}

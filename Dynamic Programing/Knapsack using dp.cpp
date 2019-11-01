#include<iostream>
#include<stdlib.h>
using namespace std;
void knapsack(int **a,int n,int c,int p[],int w[])
{
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<c+1;j++)
        {
            if(i==0||j==0)
                a[i][j]=0;
            else if(w[i-1]<=j)
            {
                int a1=p[i-1]+a[i-1][j-w[i-1]];
                int b=a[i-1][j];
                a[i][j]=a1>b?a1:b;
            }
            else
            {
                a[i][j]=a[i-1][j];
            }
        }
    }
}
int main()
{
    int c;
    cin>>c;
    int n;
    cin>>n;
    int p[n],w[n];
    for(int i=0;i<n;i++)
        cin>>p[i];
    for(int i=0;i<n;i++)
        cin>>w[i];
    int **a=(int **)malloc(sizeof(int *)*(n+1));
    for(int i=0;i<n+1;i++)
        a[i]=(int *)malloc(sizeof(int)*(c+1));
    knapsack(a,n,c,p,w);
    cout<<a[n][c];
}

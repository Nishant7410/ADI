#include<iostream>
using namespace std;
int egg(int n,int k)
{
    if(k==1||k==0)
        return k;
    if(n==1)
        return k;
    int min1=INT_MAX,res;
    for(int x=1;x<=k;x++)
    {
        res=max(egg(n-1,x-1),egg(n,k-x));
        if(res<min1)
          min1=res;
    }
    return min1+1;
}
int main()
{
    int n,k;
    cin>>n>>k;
    cout<<egg(n,k);
}

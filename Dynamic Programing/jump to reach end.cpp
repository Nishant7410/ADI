#include<iostream>
using namespace std;
// using three steps 1,2,3
int main()
{
    int n;
    cin>>n;
    int ar[n+1];
    ar[0]=1;
    ar[1]=1;
    ar[2]=2;
    for(int i=3;i<=n;i++)
    {
        ar[i]=ar[i-1]+ar[i-2]+ar[i-3];
    }
    cout<<ar[n];
}

#include<iostream>
#include<algorithm>
#include<limits>
using namespace std;
int minjumps(int arr[],int n){
if(n==1)
    return 0;
int res=INT_MAX;
for(int i=n-2;i>=0;i--)
{
    if(i+arr[i]>=n)
    {
        int sub=minjumps(arr,i+1);
        if(sub!=INT_MAX)
        {
            res=min(res,sub+1);
        }
    }
}
return res;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<minjumps(arr,n);
}

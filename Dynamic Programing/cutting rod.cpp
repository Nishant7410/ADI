#include<iostream>
#include<algorithm>
using namespace std;
int cutting(int p[],int l)
{
int arr[l+1];
arr[0]=0;
for(int i=1;i<=l;i++)
{
    int max1=INT_MIN;
    for(int j=0;j<i;j++)
    {
        max1=max(max1,p[j]+arr[i-j-1]);
    }
     arr[i]=max1;
}
  return arr[l];
}
int main()
{
    int l;
    cin>>l;
    int p[l];
    for(int i=0;i<l;i++)
        cin>>p[i];
    cout<<cutting(p,l);
}


#include<iostream>
#include<algorithm>
using namespace std;
void print(int arr[],int n,int m[])
{
    int n1=*max_element(arr,arr+n);
    int p[n1];
    int k=0;
    while(1)
    {
        k=0;
        int max1=arr[0];
        int c=0;
        for(int i=1;i<n;i++)
            if(arr[i]>max1)
            {
            max1=arr[i];
            c=i;
            }
        if(arr[c]!=n1)
              break;
        p[k++]=m[c];
        int c1=arr[c];
        arr[c]=0;
        for(int i=c-1;i>=0;i--)
        {
            if((arr[i]==(c1-1))&&(m[i]<p[k-1]))
            {
                --c1;
                p[k++]=m[i];
                arr[i]=0;

            }
        }
        for(int i=n1-1;i>=0;i--)
            cout<<p[i]<<" ";
         cout<<endl;

    }
}
int lis(int arr[],int n)
{
    int store[n];
    store[0]=1;
    for(int i=1;i<n;i++)
    {
        store[i]=1;
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j]&&store[i]<store[j]+1)
                store[i]=store[j]+1;
        }
    }
    /*for(int i=0;i<n;i++)
        cout<<store[i]<<" ";
    cout<<endl;*/
   print(store,n,arr);
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
        lis(arr,n);
}

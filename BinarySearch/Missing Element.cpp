#include<iostream>
using namespace std;
int missing(int ar[], int N)
{
    int l = 0, r = N - 1;
    while (l <= r) {

        int mid = (l + r) / 2;
        if (ar[mid] != mid + 1 && ar[mid - 1] == mid)
            return mid + 1;
        if (ar[mid] != mid + 1)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}
int main()
{
  int n;
  cin>>n;
  int ar[n];
  for(int i=0;i<n;i++)
  {
      cin>>ar[i];
  }
  cout<<missing(ar,n);
}


#include <iostream>
using namespace std;
int findMin(int arr[], int n)
{

	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];

     if(sum%2!=0)
        return false;
	bool dp[n+1][sum/2+1];

	for (int i = 0; i <= n; i++)
		dp[i][0] = true;

	for (int i = 1; i <= sum/2; i++)
		dp[0][i] = false;


	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=sum/2; j++)
		{

			dp[i][j] = dp[i-1][j];

			if(j>=arr[i-1])
				dp[i][j] = dp[i][j]||dp[i-1][j-arr[i-1]];
		}
	}
   return dp[n][sum/2];
}
int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  cout<<findMin(arr,n);
	return 0;
}



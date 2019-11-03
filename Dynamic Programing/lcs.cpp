#include<iostream>
#include<algorithm>
using namespace std;
int lcs(int s1,int s2,string str1,string str2)
{
    int ar[s1+1][s2+1];
    for(int i=0;i<s1+1;i++)
    {
        for(int j=0;j<s2+1;j++)
        {
            if(i==0||j==0)
                ar[i][j]=0;
            else if(str1[i-1]==str2[j-1])
            {
                ar[i][j]=1+ar[i-1][j-1];
            }
            else
            {
                ar[i][j]=max(ar[i-1][j],ar[i][j-1]);
            }
        }
    }
    return ar[s1][s2];
}
int main()
{
    string str1,str2;
    cin>>str1>>str2;
    cout<<lcs(str1.length(),str2.length(),str1,str2);
}

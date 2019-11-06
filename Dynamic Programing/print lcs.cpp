#include<iostream>
#include<algorithm>
using namespace std;
void print(int ar[100][100],int i,int j,string str1,string str2,string ans)
{
    if(i==0||j==0)
    {
        string k=ans;
        reverse(k.begin(),k.end());
        cout<<k<<endl;
        return;
    }
    else if(str1[i-1]==str2[j-1])
    {
        ans=ans+str1[i-1];
        print(ar,i-1,j-1,str1,str2,ans);
    }
    else
    {
        if(ar[i-1][j]>ar[i][j-1])
            print(ar,i-1,j,str1,str2,ans);
        else
            print(ar,i,j-1,str1,str2,ans);
    }
}
void lcs(int s1,int s2,string str1,string str2)
{
    int ar[100][100];
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
    string ans=" ";
    print(ar,s1,s2,str1,str2,ans);
}
int main()
{
    string str1,str2;
    cin>>str1>>str2;
    lcs(str1.length(),str2.length(),str1,str2);
}

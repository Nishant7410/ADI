#include<iostream>
#include<map>
using namespace std;
int main()
{
    string str;
    cin>>str;
    int n;
    cin>>n;
    map<string,int>m;
    for(int i=0;i<str.length();i++)
    {
        for(int j=1;j<=str.length()-i;j++)
        {
            string s=str.substr(i,j);
            m[s]++;
        }
    }
    map<string,int>::iterator it;
    int max1=-1;
    string result="";
    for(it=m.begin();it!=m.end();it++)
    {
        if(it->second==n)
        {
            int n1=it->first.length();
            if(max1<n1)
            {
                max1=n1;
                result=it->first;
            }
        }
    }
    cout<<result<<" --> "<<n;
}

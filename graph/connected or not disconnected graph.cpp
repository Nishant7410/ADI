#include<iostream>
using namespace std;
void print(int **edge,int n,int sv,bool *visit)
{
    visit[sv]=true;
    for(int i=0;i<n;i++)
    {
        if(i==sv)
            continue;
        if(edge[sv][i]==1)
        {
            if(visit[i])
                continue;
            print(edge,n,i,visit);
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    int **edge=new int*[n];
    for(int i=0;i<n;i++)
    {
        edge[i]=new int[n];
        for(int j=0;j<n;j++)
            edge[i][j]=0;
    }
    for(int i=0;i<e;i++)
    {
        int f,s;
        cin>>f>>s;
        edge[f][s]=1;
        edge[s][f]=1;
    }
    bool *visit=new bool[n];
    for(int i=0;i<n;i++)
        visit[i]=false;
    print(edge,n,0,visit);//0 means we assume graph start from 0
    int c=0;
    for(int i=0;i<n;i++)
        if(visit[i]==false)
            c=1;
   if(c==0)
       cout<<"Connected";
   else
       cout<<"Not Connected";


}

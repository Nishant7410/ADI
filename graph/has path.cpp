#include<iostream>
using namespace std;
int haspath(int **edge,int n,int sv,int e,bool *visit)
{
    static int a=0;
    if(sv==e)
    {
        a=1;
    }


    visit[sv]=true;
    for(int i=0;i<n;i++)
    {
        if(i==sv)
            continue;
        if(edge[sv][i]==1)
        {
            if(visit[i])
                continue;
             haspath(edge,n,i,e,visit);

        }
    }
    if(a==1)
        return 1;
    else return 0;
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
    int sv,en;
    cin>>sv>>en;
    bool *visit=new bool[n];
    for(int i=0;i<n;i++)
        visit[i]=false;
    cout<<haspath(edge,n,sv,en,visit);//0 means we assume graph start from 0

}


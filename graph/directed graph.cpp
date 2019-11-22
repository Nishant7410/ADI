#include<iostream>
using namespace std;
void print(int **edge,int n,int sv)
{
    cout<<sv<<endl;
    //visit[sv]=true;
    for(int i=0;i<n;i++)
    {
        if(i==sv)
            continue;
        if(edge[sv][i]==1)
        {
            print(edge,n,i);
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
    }
  /*  bool *visit=new bool[n];
    for(int i=0;i<n;i++)
        visit[i]=false;*/
    print(edge,n,0);//0 means we assume graph start from 0

}


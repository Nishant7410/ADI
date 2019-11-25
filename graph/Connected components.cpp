
#include<iostream>
#include<vector>
using namespace std;
void printDfs(int **edge,int n,int sv,bool *visit,vector<int> &v)
{
    v.push_back(sv);
    visit[sv]=true;
    for(int i=0;i<n;i++)
    {
        if(i==sv)
            continue;
        if(edge[sv][i]==1)
        {
            if(visit[i])
                continue;
            printDfs(edge,n,i,visit,v);
        }
    }
}

void Dfs(int **edge,int n)
{
     bool *visit=new bool[n];
     vector<int> v;
    for(int i=0;i<n;i++)
        visit[i]=false;
        for(int i=0;i<n;i++)
        {
            if(!visit[i])
            {
                printDfs(edge,n,i,visit,v);
                for(int i=0;i<v.size();i++)
                    cout<<v[i]<<" ";
                cout<<endl;
                v.clear();

            }
        }
        delete []visit;
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
    cout<<"Dfs"<<endl;
    Dfs(edge,n);

}

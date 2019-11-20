
#include<iostream>
#include<limits.h>
using namespace std;

int findvertex(int *w,int n,bool *v)
{
    int minvertex=-1;
    for(int i=0;i<n;i++)
    {
        if(!v[i] && (minvertex==-1||w[i]<w[minvertex]))
            minvertex=i;
    }
    return minvertex;
}

void prims(int **edge,int n)
{
  int *parent=new int[n];
  int *weight=new int[n];
  bool *visited=new bool[n];
  for(int i=0;i<n;i++)
  {
      weight[i]=INT_MAX;
      visited[i]=false;
  }
  parent[0]=-1;
  weight[0]=0;
  for(int i=0;i<n;i++)
  {
      int minvertex=findvertex(weight,n,visited);
      visited[minvertex]=true;
      for(int j=0;j<n;j++)
      {
          if(edge[minvertex][j]!=0 && !visited[j])
            if(edge[minvertex][j]<weight[j])
            {
            weight[j]=edge[minvertex][j];
            parent[j]=minvertex;
            }
      }
  }

  for(int i=1;i<n;i++)
  {
      if(parent[i]<i)
        cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
      else
        cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
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
        int f,s,w;
        cin>>f>>s>>w;
        edge[f][s]=w;
        edge[s][f]=w;
    }
    prims(edge,n);

}

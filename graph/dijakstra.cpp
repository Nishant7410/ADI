
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
  int *distance=new int[n];
  bool *visited=new bool[n];
  for(int i=0;i<n;i++)
  {
      distance[i]=INT_MAX;
      visited[i]=false;
  }
  distance[0]=0;
  for(int i=0;i<n;i++)
  {
      int minvertex=findvertex(distance,n,visited);
      visited[minvertex]=true;
      for(int j=0;j<n;j++)
      {
          if(edge[minvertex][j]!=0 && !visited[j])
            {
                int dis=edge[minvertex][j]+distance[minvertex];
                if(dis<distance[j])
                    distance[j]=dis;
            }
      }
  }

  for(int i=0;i<n;i++)
  {
     cout<<i<<" "<<distance[i]<<endl;
  }
  delete []distance;
  delete []visited;
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


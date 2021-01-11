#include<bits/stdc++.h>
using namespace std;

void print(int** edges , int n , int sv, bool* visited)
{
    cout<<sv<<endl;
    visited[sv]=true;
    for(int i=0;i<n;i++)
    {
        if(i==sv)
        {
            continue;
        }
     if(edges[sv][i]==1)
     {
        if(visited[i])
        {
            continue;
        }
         print(edges,n,i,visited); //explore all edges
     }
    }

}

int main()
{
    int n; //vertices
    int e; //edges
    cout<<"Enter the vertices and edges"<<endl;
    cin>>n>>e;
    int** edges = new int*[n];  
    for(int i=0;i<n;i++)
    {
        edges[i] = new int[n];
        for(int j=0;j<n;j++)
        {
            edges[i][j]=0;
        }
    }

    for(int i=0;i<e;i++)
    {
        int f,j;
        cin>>f>>j;
        edges[f][j]=1;
        edges[j][f]=1;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<edges[i][j]<<" ";
        }
        cout<<endl;
    }

    bool* visited= new bool[n];
    for (int i=0;i<n;i++)  //not to be in loop
    {
        visited[i]=false;
    }

    
    cout<<"Vertices by DFS traversal are"<<endl;
    print(edges,n,0,visited);
    return 0;

}
#include<bits/stdc++.h>
using namespace std;

void printBFS(int** edges , int n , int sv)
{
    queue<int> pendingvertices;
    bool* visited= new bool[n];
    for (int i=0;i<n;i++)  //not to be in loop
    {
        visited[i]=false;
    }
    pendingvertices.push(sv);
    visited[sv]=true;

    while (!pendingvertices.empty())
    {
        int currentvertex = pendingvertices.front();
        pendingvertices.pop();
        cout<<currentvertex<<endl;

        for(int i=0;i<n;i++) //exploring the adjacent vertices
    {
        if(edges[currentvertex][i]==1 && !visited[i])
        {
            pendingvertices.push(i);
            visited[i]=true;
        }
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

    // bool* visited= new bool[n];
    // for (int i=0;i<n;i++)  //not to be in loop
    // {
    //     visited[i]=false;
    // }

    
    cout<<"Vertices by BFS traversal are"<<endl;
    printBFS(edges,n,0);
    return 0;

}
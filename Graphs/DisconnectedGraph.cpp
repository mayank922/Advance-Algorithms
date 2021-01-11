#include<bits/stdc++.h>
using namespace std;

void printDFS(int** edges , int n , int sv, bool* visited)
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
         printDFS(edges,n,i,visited); //explore all edges
     }
    }

}

void printBFS(int** edges , int n , int sv,bool* visited)
{
    queue<int> pendingvertices;
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

void DFS(int** edges , int n)//for disconnected graph
{
    bool* visited= new bool[n];
    for (int i=0;i<n;i++)  
    {
        visited[i]=false;
    }

    for(int i=0;i<n;i++) 
    {
        if(!visited[i])
        {
            printDFS(edges,n,i,visited);
        }
    }


}

void BFS(int** edges,int n)
{
    bool* visited= new bool[n];
    for (int i=0;i<n;i++)  
    {
        visited[i]=false;
    }

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            printBFS(edges,n,i,visited);
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

   
    
    cout<<"Vertices by DFS traversal are"<<endl;
    DFS(edges,n);

    cout<<"Vertices by BFS teversal are"<<endl;
    BFS(edges,n);
    return 0;

}

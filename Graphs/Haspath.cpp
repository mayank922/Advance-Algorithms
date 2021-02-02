/* Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), check if there exists any path between them or not.
 Print true if the path exists and false otherwise.*/

#include<bits/stdc++.h>
using namespace std;

bool haspath(int** edges,int n,int sv,int ev,bool*visited)
{
    if(sv==ev) //base case
    {
        return true;
    }
    visited[sv]=true;
    for(int i=0;i<n;++i)
    {
        if(edges[sv][i]==1 && !visited[i])
        {
            if(haspath(edges,n,i,ev,visited)) 
            {
                return true;
            }
        }
    }

    return false;

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

    cout<<"Enter the starting and end vertices"<<endl;
    int sv,ev;
    cin>>sv>>ev;
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
    
   cout<<(haspath(edges,n,sv,ev,visited)?"true" : "false")<<endl;

    

}
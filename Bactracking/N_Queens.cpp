#include<bits/stdc++.h>
using namespace std;
int board[11][11];


bool ispossible(int n,int row,int col)
{
	//same column check
	for(int i=row-1;i>=0;i--)
	{
		if(board[i][col]==1)
		{
			return false;
		}
	}
	//upper right diognal
	for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++)
	{
		if(board[i][j]==1)
		{
			return false;
		}
	}
	
	//upper left diognal
	for(int i=row-1,j=col-1;i>=0 && j>=0;i-- , j--)
	{
		if(board[i][j]==1)
		{
			return false;
		}
	}
	
	return true;
}

void nqueenhelper(int n,int row)
{
	if(row==n)
	{
		//reached a solution
		//print
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<board[i][j]<<" ";
			}
		}
		cout<<endl;
		return;
	}
	
	for(int j=0;j<n;j++)
	{
		if(ispossible(n,row,j))
		{
			board[row][j]=1;
			nqueenhelper(n,row+1); //for smaller problems
			board[row][j]=0;       //else backtrack to previous row
		}
	}
	return;
}

void placequeens(int n)
{
	memset(board,0,sizeof(int));
	nqueenhelper( n,0);
}

int main()
{
	placequeens(10);
	return 0;
}

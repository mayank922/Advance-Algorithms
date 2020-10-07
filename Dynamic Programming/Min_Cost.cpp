#include<bits/stdc++.h>
using namespace std;

int min_cost(int** input , int si,int sj,int ei,int ej,int** output)
{

	if(si==ei || sj == ej)
	{
		return input[ei][ej];
	}
	
	if(si>ei || sj >ej)
	{
		return INT_MAX;
	}
	
	if(output[si][sj]>-1)
	{
		return output[si][sj];
	}
	
	int option1 = min_cost(input,si+1,sj,ei,ej,output);   //right 
	int option2 = min_cost(input,si+1,sj+1,ei,ej,output);  //diognal
	int option3 = min_cost(input,si,sj+1,ei,ej,output);    //down
	 
	 int cost =input[si][sj] + min(option1,min(option2,option3));
	 output[si][sj] = cost;     //store for reuse
	 return cost;
	
}

int main()
{
	int n;
	cin>>n;
	int **input = new int*[n];
	for(int i=0;i<n;i++)
	{
		input[i] = new int[n];
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>input[i][j];
		}
	}
	int si,sj,ei,ej;
	cout<<"Start point"<<endl;
	cin>>si>>sj;
	cout<<"End Point"<<endl;
	cin>>ei>>ej;
	int **output = new int*[n];
	for(int i=0;i<n;i++)
	{
		
		output[i] = new int[n];
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			output[i][j] = -1;
		}
	}
	
	
	cout<<min_cost(input,si,sj,ei,ej,output)<<endl;
	
	
}

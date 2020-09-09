#include<bits/stdc++.h>
using namespace std;

int alphacodes(int *a,int size,int *arr)
{
    int output;
	if(size==0)
	{
		return 1;
	}
	if(size==1)
	{
		return 1;
	}
	if(arr[size]>0)    //return if once calculated
	{
		return arr[size];
	}
	if(a[size-1]!=0)
	{
		output=alphacodes(a,size-1,arr);
	}
	
	if(a[size-2]*10 + a[size-1]<=26  && a[size-2]!=0)
	{
		output=output+alphacodes(a,size-2,arr);
	}
	arr[size]=output;   //memoization
	return output;
	
}
int main()
{
	
	
	while(true)
	{
		string s;
		cin>>s;
		int a[s.size()]={0};
		int arr[s.size()+1]={0};
		
		if(s=="0")
		{
			break;
		}
		else
		{
			for(int i=0;i<s.size();i++)
			{
				a[i]=s[i]-'0';
			}
			cout<<alphacodes(a,s.size(),arr)<<endl;
		}
		
	}
	
}


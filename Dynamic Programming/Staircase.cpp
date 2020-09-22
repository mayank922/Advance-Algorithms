/* A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.

Time complexity of your code should be O(n).

Input format :
Integer n (No. of steps)
Constraints :
n <= 70
Sample Input 1:
4
Sample Output 1:
7
*/



#include <iostream>
using namespace std;



long staircasehelp(long *arr,int n)
{
	if(n==0 || n==1)
	{
		return 1;
	}
	if(n==2)
	{
		return 2;
	}
	if(arr[n]>0)
	{
		return arr[n];
	}
	
	long output = staircasehelp(arr,n-1)+staircasehelp(arr,n-2)+staircasehelp(arr,n-3);
	arr[n]=output;
	return output;
}

long staircase(int n)
{
	long *arr = new long[n+1];
	long x=staircasehelp(arr,n);
	return x;
}

int main()
{
	int n;
	cin >> n;
	cout << staircase(n);
}


#include <bits/stdc++.h>
using namespace std;


int fib2(int n, int * arr) {
	if (n == 0 || n == 1) 
	{
		return 1;
	}
	if (arr[n] > 0)     //return if once calculated
	{
		return arr[n];
	}
	int m =pow(10,9)+7;
	long output = (long)(fib2(n - 1, arr) + fib2(n - 2, arr));
	int out = (int)(output%m);
	arr[n] = out;    //memoization
	return out;
}




int main() {
	int n;
	cin >> n;
	int arr[n+1]={0};
	cout << fib2(n,arr) << endl;
}


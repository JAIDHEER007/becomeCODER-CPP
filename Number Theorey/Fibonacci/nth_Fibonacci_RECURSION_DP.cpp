//Printing Nth Fibonacci number using Recursion optimized with Dynamic Programming
//a = 0
//b = 1

#include<iostream>
using namespace std;

int dp[100005] = {-1,0,1,1};  //DP array which memorizes the result
int max_query = 3;

int Fib(int n){
	if(dp[n] != -1)
		return dp[n];
	
	return (dp[n] = Fib(n-1) + Fib(n-2)); //Assigns the sum to dp[n] and also retuns it
}

int nthFib(int n){
	if(n > max_query){
		for(int i=max_query+1;i<=n;i++)
			dp[i] = -1;
		max_query = n;
		return Fib(n);
	}
	return dp[n];
}

int main(){
	
	cout<<nthFib(1)<<endl;
	cout<<nthFib(2)<<endl;
	cout<<nthFib(3)<<endl;
	cout<<nthFib(5)<<endl;
	cout<<nthFib(7)<<endl;
	cout<<nthFib(13)<<endl;
	cout<<nthFib(24)<<endl;
	cout<<nthFib(30)<<endl;
	cout<<nthFib(10)<<endl;
	
	return 0;
}

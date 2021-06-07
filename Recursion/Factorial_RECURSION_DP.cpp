//Printing Factorial of a  number using Recursion optimized with Dynamic Programming

#include<iostream>
using namespace std;

long long dp[100005] = {1,1,2};  //DP array which memorizes the result
int max_query = 2;

long long Fact(int n){
	if(dp[n] != -1)
		return dp[n];
	
	return (dp[n] = n * Fact(n-1)); //Assigns the product to dp[n] and also retuns it
}

long long Factorial(int n){
	if(n > max_query){
		for(int i=max_query+1;i<=n;i++){
			dp[i] = -1;
			max_query = n;
		}
		return Fact(n);
	}
	return dp[n];
}

int main(){
	
	cout<<Factorial(0)<<endl;
	cout<<Factorial(1)<<endl;
	cout<<Factorial(2)<<endl;
	cout<<Factorial(3)<<endl;
	cout<<Factorial(5)<<endl;
	cout<<Factorial(7)<<endl;
	cout<<Factorial(10)<<endl;
	cout<<Factorial(13)<<endl;
	cout<<Factorial(20)<<endl;
	
//	cout<<Factorial(21)<<endl; OVERFLOW 
	
	cout<<dp[15]<<endl;
	cout<<Factorial(15)<<endl; //Returns in O(1) time as it is already present in DP array. 
	
	return 0;
}

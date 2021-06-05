//Printing Nth Fibonacci number using Recursion
//a = 0
//b = 1

#include<iostream>
using namespace std;

int nthFib(int n){
	if(n == 1)
		return 0;
	if((n == 2) || (n == 3))
		return 1;
	
	return nthFib(n-1) + nthFib(n-2);
}

int main(){
	cout<<nthFib(1)<<endl;
	cout<<nthFib(5)<<endl;
	cout<<nthFib(7)<<endl;
	cout<<nthFib(13)<<endl;
	cout<<nthFib(24)<<endl;
	cout<<nthFib(30)<<endl;
	return 0;
}

//Printing Nth Fibonacci number using loops
//a = 0
//b = 1

#include<iostream>
using namespace std;

int nthFib(int n){
	if(n == 1)
		return 0;
	if((n == 2) || (n == 3))
		return 1;
	
	int a = 0;
	int b = 1;
	int c = a+b;
	int term = 3;
	while(term < n){
		a = b;
		b = c;
		c = a+b;
		term++;
	}
	return c;
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

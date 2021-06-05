//isPrime
//Using recursion

#include<iostream>
using namespace std;

bool isPrime(int n, int i){
	if((i * i) <= n){
		if((n % i == 0) || (n % (i+2) == 0))
			return false;
		else
			return isPrime(n,i+6);
	}else
		return true; 
}

bool isPrime(int n){
	if(n == 1)
		return false;
	if((n == 2) || (n == 3))
		return true;
	if((n % 2 == 0) || (n % 3 == 0))
		return false; 
	
	return isPrime(n,5);
}

int main(){
	cout<<boolalpha;
	
	cout<<isPrime(53)<<endl;			//True
	cout<<isPrime(27)<<endl; 			//False
	cout<<isPrime(19)<<endl;			//True
	cout<<isPrime(553007)<<endl;		//False
	cout<<isPrime(10009)<<endl;			//True
	cout<<isPrime(644913)<<endl;		//False
	cout<<isPrime(11987167)<<endl; 		//True
	
	return 0;
}

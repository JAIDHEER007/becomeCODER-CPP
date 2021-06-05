//Prime or not
//Implementation 2

#include<iostream>
using namespace std;

bool isPrime(int number){
	for(int i=2;i<=(number>>1);i++){
		if((number%i)==0)
			return false;
	}
	return (number==1)?(false):(true);
}

int main(){
	cout<<boolalpha<<isPrime(1)<<endl;
	cout<<boolalpha<<isPrime(2)<<endl;
	cout<<boolalpha<<isPrime(3)<<endl;
	cout<<boolalpha<<isPrime(4)<<endl;
	cout<<boolalpha<<isPrime(7)<<endl;
	cout<<boolalpha<<isPrime(19)<<endl;
	cout<<boolalpha<<isPrime(100)<<endl;
	cout<<boolalpha<<isPrime(553)<<endl;
	cout<<boolalpha<<isPrime(557)<<endl;
	
	return 0;
}

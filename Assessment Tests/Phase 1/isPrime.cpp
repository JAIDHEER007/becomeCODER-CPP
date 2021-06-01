//IsPrime

//If prime return -1
//Else return the factor greator than one

#include<iostream>
using namespace std;


//Using sieve of Eratosthenes
long long isPrime(long long number){
	if(number == 1)
		return 1;
	if((number == 2)||(number == 3))
		return -1;
	if(number % 2 == 0)
		return 2;
	if(number % 3 == 0)
		return 3;
		
	for(long long i=5;(i*i)<=number;i+=6){
		if(number % i == 0)
			return i;
		else if(number % (i+2) == 0)
			return (i+2);
	}
	
	return -1;
}

int main(){
	//1
	cout<<isPrime(1)<<endl<<endl;
	
	//Testing Primes
	cout<<isPrime(53)<<endl;
	cout<<isPrime(239)<<endl;
	cout<<isPrime(563)<<endl;
	cout<<isPrime(10009)<<endl;
	cout<<isPrime(2691427213)<<endl;
	cout<<isPrime(1726703129)<<endl;
	cout<<isPrime(20490823)<<endl;
	cout<<isPrime(23141177)<<endl;
	cout<<isPrime(70113257)<<endl;
	cout<<isPrime(11987167)<<endl;
	cout<<isPrime(2)<<endl;
	cout<<isPrime(3)<<endl;
	cout<<isPrime(5)<<endl;
	cout<<isPrime(7)<<endl<<endl;
	
	//Testing the non primes
	//Should return the first factor greator than one
	cout<<isPrime(4)<<endl;
	cout<<isPrime(6)<<endl;
	cout<<isPrime(9)<<endl;
	cout<<isPrime(10)<<endl;
	cout<<isPrime(49)<<endl;
	cout<<isPrime(640)<<endl;
	cout<<isPrime(3909210)<<endl;
	cout<<isPrime(644913)<<endl;
	cout<<isPrime(231411711)<<endl;
	cout<<isPrime(125)<<endl;
	cout<<isPrime(553007)<<endl;
	
	
	return 0;
}

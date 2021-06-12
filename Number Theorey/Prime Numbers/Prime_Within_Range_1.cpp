//finding next and before prime
//TechGig Question 2

#include<bits/stdc++.h>
using namespace std;

bool isPrime(int number){
	if(number == 1)
		return false;
	if((number == 2)||(number == 3))
		return true;
	if((number % 2 == 0) || (number % 3 == 0))
		return false;
		
	for(int i=5;(i*i)<=number;i+=6){
		if((number % i == 0) || (number % (i+2) == 0))
			return false;
	}
	return true;
}

int main(){
	int l = 20;
	int r = 100;
	
	int nextPrime = l;
	int beforePrime = r;
	
	bool nextPrime_control = true; //Used to verify if ANY Primes are available in range of L, R
	
	for(;nextPrime<=r;nextPrime++){
		if(isPrime(nextPrime)){
			nextPrime_control = false; //Yea, A Prime is Present
			break;
		}
	}	
	if(nextPrime_control){ //If nextPrime_control is true. Then just simply print L,R acc to Question
		nextPrime = l;
		beforePrime = r;
	}
	else{
		for(;beforePrime>=l;beforePrime--) //Find the next Prime
			if(isPrime(beforePrime)){ break; }	
	}
	
	
	cout<<nextPrime<<endl;
	cout<<beforePrime<<endl;
	
	
	return 0;
}

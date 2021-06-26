//Project Euler 10 
//Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler005/problem
//Sieve of Eratosthenes

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 1000000		//Exact Number for which Prime number which is < 10^6 will occur

vector<int> primes;

void generatePrimes(){
	bool *seive = new bool[MAX](); 
	for(int i=2;i<MAX;seive[i]=true,i++);
	for(int i=2;(i*i)<MAX;i++){
		if(seive[i]){
			for(int j=(i*i);j<MAX;j+=i)
				seive[j]=false;
		}
	}
	for(int i=2;i<MAX;i++)
		if(seive[i]){ primes.push_back(i); }
	delete[] seive;
}

long long primeSum(int N){
	long long sum = 0;
	for(int prime:primes)
		if(prime <= N){ sum += prime; }
	return sum; 
}

int main(){
	generatePrimes();
	
	int primes_size = primes.size();
	cout<<primes_size<<endl;
	cout<<primes[primes_size - 1]<<endl;
	
	cout<<primeSum(5)<<endl;
	cout<<primeSum(10)<<endl;
	cout<<primeSum(1000000)<<endl; //10^6
	
	return 0;
}


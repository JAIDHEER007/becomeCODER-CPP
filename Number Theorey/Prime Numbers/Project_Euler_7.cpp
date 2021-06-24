//Sieve of Eratosthenes

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX_SIZE 10001
#define MAX 104730		//Exact Number for which 10001 Primes will occur
				//Found it by Trail and Error 

vector<int> prime;

void generatePrimes(){
	prime.push_back(-1);
	bool *seive = new bool[MAX](); 
	for(int i=2;i<MAX;seive[i]=true,i++);
	for(int i=2;(i*i)<MAX;i++){
		if(seive[i])
			for(int j=(i*i);j<MAX;seive[j]=false,j+=i)
	}
	for(int i=2;i<MAX;i++)
		if(seive[i]){ prime.push_back(i); }
	delete[] seive;
}

int main(){
	generatePrimes();
	
	cout<<prime[1]<<endl;
	cout<<prime[2]<<endl;
	cout<<prime[3]<<endl;
	cout<<prime[6]<<endl;
	cout<<prime[10000]<<endl<<endl;
	
	
	int prime_size = prime.size();
	cout<<prime_size<<endl;
	for(int i=0;i<prime_size;i++)
		cout<<(i+1)<<'\t'<<prime[i]<<endl;
	
	return 0;
}


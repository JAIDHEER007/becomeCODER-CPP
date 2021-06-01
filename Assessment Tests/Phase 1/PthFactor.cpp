//Pth factor
//Given an long integer n
//Find the pth factor from all the factors of n while they were sorted in ascending order
//If p is more than number of factors then return 0;

#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

long PthFactor(long p, long n){
	vector<long> factors;
	long n_sqrt = sqrt(n);
	
	for(long i=1;i<=n_sqrt;i++){
		if((n % i) == 0){
			factors.push_back(i);
			if((n/i) != i)
				factors.push_back((n/i));
		}
	}
	
	if(p > factors.size())
		return 0;
	
	sort(factors.begin(),factors.end());
	
	//for(long factor:factors)
	//	cout<<factor<<" ";
	//cout<<endl;
		
	return factors[p-1];
}


int main(){
	cout<<PthFactor(2,100)<<endl;
	cout<<PthFactor(20,100)<<endl;
	
	cout<<PthFactor(2,INT_MAX)<<endl; //Prime
	cout<<PthFactor(20,INT_MAX-1)<<endl; 
	
	cout<<PthFactor(2,553007)<<endl; 
	
	return 0;
}

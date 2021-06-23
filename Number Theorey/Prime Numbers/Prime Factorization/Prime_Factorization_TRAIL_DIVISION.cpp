//Prime Factorization using Taril Division

#include<iostream>
#include<map>

using namespace std;

typedef map<int,int> table;

table primeFactorize(int number){
	table result;
	while(!(number & 1)){	//Eleminating all 2 factors
		++result[2];
		number>>=1;
	}
	while(!(number % 3)){	//Eleminating all 3 factors
		++result[3];
		number /= 3;
	}
	//From This point We eleiminated all 2,3 prime factors
	//Now the prime factors will start form 5,7,11,13....
	//Now 6k +- 1 Rule can be applied 
	
	for(int i=5;(i*i)<=number;i+=6){
		while(!(number % i)){
			++result[i];
			number /= i;
		}
		while(!(number % (i+2))){
			++result[i+2];
			number /= (i+2);
		}
	}
	
	if(number > 1)
		++result[number];
	
	return result;
}

void print(table &res){
	for(auto it:res){
		cout<<(it.first)<<" "<<(it.second)<<endl;
	}
}

int main(){
	table result = primeFactorize(553007);
	print(result);
	
	//Testing
	for(int i=1;i<=64;i++){
		cout<<"============="<<endl;
		cout<<"Number: "<<i<<endl;
		result = primeFactorize(i);
		print(result);
		cout<<"============="<<endl;
	}
	
	return 0;
}

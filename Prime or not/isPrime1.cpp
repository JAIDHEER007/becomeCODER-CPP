//Prime or not
//Implementation 1

#include<iostream>
using namespace std;

bool isPrime(int number){
	int count = 0;
	for(int i=1;i<=number;i++){
		if((number%i)==0){
			count++;
			if((count>=2)&&(i!=number)){ return false; }
		}
	}
	return (count==2); 
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

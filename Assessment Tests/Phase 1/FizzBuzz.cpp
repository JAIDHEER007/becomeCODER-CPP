//FizzBuzz

//Given an integer n
//Traverse from 1 to n
//For every integer
//If divisible by both 3 and 5 ==> FizzBuzz
//If divisible by only 3 ==> Fizz
//If divisible by only 5 ==> Buzz
//Else ==> print the number

#include<iostream>
using namespace std;

void FizzBuzz1(int n){
	for(int i=1;i<=n;i++){
		if((i % 3 == 0) && (i % 5 == 0))
			cout<<"FizzBuzz"<<endl;
		else if(i % 3 == 0)
			cout<<"Fizz"<<endl;
		else if(i % 5 == 0)
			cout<<"Buzz"<<endl;
		else 
			cout<<i<<endl;
	}
}

//Single Line using Ternary Operators
//to_string is needed or less it will lead to an error
void FizzBuzz2(int n){
	for(int i=1;i<=n;i++)
		cout<<((i % 15)?(((i % 3)?((i % 5)?(to_string(i)):("Buzz")):("Fizz"))):("FizzBuzz"))<<endl;
}

int main(){
	FizzBuzz1(15);
	cout<<endl<<endl;
	FizzBuzz2(15);
	
	return 0;
}



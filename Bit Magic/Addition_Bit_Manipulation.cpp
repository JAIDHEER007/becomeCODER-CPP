//Sum of two numbers using bit manipulation only

#include<iostream>
using namespace std;

int add(int a, int b){
	while(b){
		int temp = a;
		a ^= b; 	//XOR, finding the sum
		b &= temp; 	//AND, finding the carry
		b <<= 1; 	//Left Shifting by One, As carry should be added to next bit
	}
	return a; 
}

int main(){
	cout<<add(10,20)<<endl;
	cout<<add(1,2)<<endl;
	cout<<add(53,0)<<endl;
	cout<<add(0,53)<<endl;
	
	return 0;
}

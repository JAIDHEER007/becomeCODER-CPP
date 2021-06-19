//Binary Exponentiation
//using Loops and Recursion

#include<iostream>
using namespace std;

long long naiveExponentation(int base, int power){
	long long result = 1;
	for(int i=1;i<=power;i++)
		result *= base;
	return result;
}

long long binaryExponentation_L(long long base, int power){
	long long result = 1;
	while(power){
		if(power & 1)
			result *= base;
		base *= base;
		power >>= 1;
	}
	return result;
}

//Efficient by its own 
//No need to optimize it by DP
long long binaryExponentation_R(int base, int power){
	if(power == 0)
		return 1;
	if(power == 1)
		return base;
	long long res = binaryExponentation_R(base, power>>1);
	if(power & 1)
		return (res * res * base);
	else
		return (res * res);
}

int main(){
	cout<<naiveExponentation(2,10)<<endl;
	cout<<binaryExponentation_L(2,10)<<endl;
	cout<<binaryExponentation_R(2,10)<<endl;
	
	cout<<naiveExponentation(53,7)<<endl;
	cout<<binaryExponentation_L(53,7)<<endl;
	cout<<binaryExponentation_R(53,7)<<endl;
	
	//Overflow
	//Long Long Max Limit: 2⁶³ - 1
	cout<<naiveExponentation(2,63)<<endl;
	cout<<binaryExponentation_L(2,63)<<endl;
	cout<<binaryExponentation_R(2,63)<<endl;
	
	return 0;
}

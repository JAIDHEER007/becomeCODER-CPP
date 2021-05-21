//Even or odd

#include<iostream>
using namespace std;

bool inline isOdd(int num){
	return (num & 1);
}

int main(){
	cout<<boolalpha;
	cout<<isOdd(0)<<endl;
	cout<<isOdd(1)<<endl;
	cout<<isOdd(11)<<endl;
	cout<<isOdd(24)<<endl;
	cout<<isOdd(53)<<endl<<endl;
	
	return 0;
}

/*
Working:

>>Basic Math
1. Even Number + 1 = Odd Number
2. Odd Number + 1 = Even Number

0 is considered as Even number 
Binary representation of zero is '0'
Here first Bit is Zero

Now by adding 1, we get 1 which is Odd Number
Binary representation of one is '1'
Here first bit is One

Now by adding 1, we get 2 which is Even number
Binary Representation of two is '10'
Here first bit is Zero

So we can arrive at a conclusion that 
1. All Even Numbers have their first bit as ZERO
2. All Odd Numbers have their first bit as ONE

>> How to check if first bit is one or zero

By performing & with one,
If output is One then it is odd
else Even.

*/

/*
Internally compiler converts (num % 2ⁿ) to (num & (2ⁿ - 1)) for faster execution
*/

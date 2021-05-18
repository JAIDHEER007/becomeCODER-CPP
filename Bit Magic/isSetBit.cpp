//Determine wether Kth bit is set or not

#include<iostream>
using namespace std;

bool inline isSetBit(int number, int position){
	return (number & (1<<(position-1)));
}

int main(){
	cout<<boolalpha;
	
	cout<<isSetBit(8,4)<<endl;
	cout<<isSetBit(13,4)<<endl;
	cout<<isSetBit(13,2)<<endl;
	cout<<isSetBit(13,5)<<endl;
	
	return 0;
}

/*
	Bit Representation of 13
	
	13 			═══►		1		1		0		1
	position 	═══►		4		3		2		1
	
	
*/

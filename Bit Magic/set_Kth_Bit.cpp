//Set Kth bit
//LSB is represented by 1ˢᵗ positon

#include<iostream>
using namespace std;

string bin(int num, int bit_length = 0){
	string result = "";
	do{
		result = ((num & 1)?("1"):("0")) + result;
		num >>= 1;
	}while(num);
	if(bit_length > result.length())
		return (string((bit_length-result.length()),'0') + result);
	return result;
}

int inline setKthBit(int num, int position){
	return (num | (1<<(position-1)));
}

int main(){
	cout<<bin(13)<<endl;
	cout<<bin(setKthBit(13,2))<<endl;
	cout<<bin(setKthBit(13,5))<<endl;
	
	return 0;
}

/*

Output:
1101
1111
11101

*/

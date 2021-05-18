//Unset Kth bit
//LSB is represented by 1ˢᵗ position

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

int unsetKthBit(int num, int position){
	int pow2 = (1<<(position-1));
	return ((num & pow2)?(num ^ pow2):(num));
}

int main(){
	cout<<bin(13)<<endl;
	cout<<bin(unsetKthBit(13,2))<<endl;
	cout<<bin(unsetKthBit(13,1))<<endl;
	cout<<bin(unsetKthBit(15,4))<<endl;
	
	return 0;
}

/*
Output:
1101
1101
1100
111

*/

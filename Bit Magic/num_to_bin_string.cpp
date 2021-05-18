//Binary representation

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

int main(){
	cout<<bin(553007)<<endl<<endl;
	
	for(int i=0;i<=32;i++)
		cout<<bin(i,6)<<endl;
	
	return 0;
}

/*
Output:
10000111000000101111

000000
000001
000010
000011
000100
000101
000110
000111
001000
001001
001010
001011
001100
001101
001110
001111
010000
010001
010010
010011
010100
010101
010110
010111
011000
011001
011010
011011
011100
011101
011110
011111
100000

*/

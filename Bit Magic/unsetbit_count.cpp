//Count number of unset bits

#include<iostream>
using namespace std;

int unsetBitCount(int num){
	int count = 0;
	do{
		if(!(num & 1)){ count++; }
		num >>= 1;
	}while(num);
	return count;
}

int main(){
	cout<<unsetBitCount(0)<<endl;
	cout<<unsetBitCount(5)<<endl;
	cout<<unsetBitCount(13)<<endl;
	cout<<unsetBitCount(15)<<endl;
	cout<<unsetBitCount(32)<<endl;
	
	return 0;
}

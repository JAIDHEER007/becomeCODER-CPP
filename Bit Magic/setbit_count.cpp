//Count Number of setbits

#include<iostream>
using namespace std;

int setBitCount(int num){
	int count = 0;
	while(num){
		if(num & 1){ count++; }
		num >>= 1;
	}
	return count;
}

int main(){
	cout<<setBitCount(0)<<endl;
	cout<<setBitCount(5)<<endl;
	cout<<setBitCount(13)<<endl;
	cout<<setBitCount(15)<<endl;
	
	return 0;
}


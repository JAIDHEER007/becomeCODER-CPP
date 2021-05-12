//Happy Number
//Happy Number sequnece: 7, 13, 19, 23, 31, 79, 97, 103, 109, 139 ...

#include<iostream>
using namespace std;

bool isHappyNumber(int number){
	int res = 0;
	while(1){
		int rem = (number % 10);
		number /= 10;
		res += (rem * rem);
		if(number == 0){
			number = res;
			res = 0;
			if((number >= 1)&&(number <= 9))
				break;
		}
	}
	return (number==1)?(true):(false);
}

int main(){
	cout<<boolalpha<<isHappyNumber(1)<<endl;
	cout<<boolalpha<<isHappyNumber(4)<<endl;
	cout<<boolalpha<<isHappyNumber(7)<<endl;
	cout<<boolalpha<<isHappyNumber(13)<<endl;
	cout<<boolalpha<<isHappyNumber(19)<<endl;
	cout<<boolalpha<<isHappyNumber(24)<<endl;
	cout<<boolalpha<<isHappyNumber(553)<<endl;
		
	return 0;
}

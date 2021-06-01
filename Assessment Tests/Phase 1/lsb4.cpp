//4th bit from LSB

#include<iostream>
using namespace std;

int lsb4(int number){
	return ((number & 8)?(1):(0));
}

int main(){
	cout<<lsb4(23)<<endl;
	cout<<lsb4(8)<<endl;
	cout<<lsb4(32)<<endl;
	cout<<lsb4(77)<<endl;
	cout<<lsb4(3)<<endl;
	cout<<lsb4(0)<<endl;
		
	return 0;
}

/*
0
1
0
1
0
0
*/

/*
Idea:

let number be #####1####
Here '#' represents 0 or 1 bit 

By perfomring and with 8 ==> 1000
by performing and with 000, ### will become 0 irrespective of value of #

The output will defined by the 4th bit

if the 4th bit is 1, then the result will be 8
else it will be zero


*/

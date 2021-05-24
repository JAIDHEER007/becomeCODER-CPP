//Checking if a number is power 2

#include<iostream>
using namespace std;

bool inline isPower2(int num){
	return ((num==0)?(false):(!(num & (num - 1))));
}

int main(){
	for(int i=0;i<=1000000;i++)
		if(isPower2(i)){ cout<<i<<endl; }
	return 0;
}

/*
Idea:
1     ---> 2⁰   --->		   1
2     ---> 2¹   --->		  10
4     ---> 2²   --->		 100
8     ---> 2³   --->		1000
16    ---> 2⁴   --->       10000
32    ---> 2⁵   --->	  100000
64    ---> 2⁶   --->	 1000000
128   ---> 2⁷   --->    10000000
256   ---> 2⁸   --->   100000000
512   ---> 2⁹   --->  1000000000

Binary representation of number which is power 2 has one and only one and that is the MSB

So if we count number of set bits and the count is 1 then it is a power of 2

Much better approach is performng (num & (num - 1))

Logic behind it is

Let num be 128
binary representation of num is 10000000
now, num - 1 is 127 and its binary representation is 1111111

num 	===> 128 ===> 10000000
num - 1 ===> 127 ===> 01111111 (Leading Zero is added)

now (num & (num - 1)) will be 0 
This is possible only when num is power of 2

But this code fails when num is 0

so add a condition to rule out num = 0 case 

This is done in O(1) time and space complexity

*/

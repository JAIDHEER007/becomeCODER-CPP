//Ugly Number
//LeetCode problem 263

// https://leetcode.com/problems/ugly-number/

#include<iostream>
using namespace std;

bool isUglyNumber(int number){
	if(number == 0)
		return false;
	if(number == 1)
		return true;
	
	while(!(number % 2)){ number /= 2; }
	while(!(number % 3)){ number /= 3; }
	while(!(number % 5)){ number /= 5; }
	
	return (number == 1);
}

int main(){
	cout<<boolalpha;
	
	cout<<isUglyNumber(1)<<endl;
	
	cout<<isUglyNumber(2)<<endl;
	cout<<isUglyNumber(3)<<endl;
	cout<<isUglyNumber(5)<<endl;
	
	cout<<isUglyNumber(1024)<<endl;
	cout<<isUglyNumber(59049)<<endl;
	cout<<isUglyNumber(78125)<<endl;
	
	cout<<isUglyNumber(648)<<endl;
	cout<<isUglyNumber(455625)<<endl;
	cout<<isUglyNumber(1000)<<endl;
	
	cout<<isUglyNumber(7000)<<endl;
	cout<<isUglyNumber(396)<<endl;
	
	return 0;
}

//Explanation

//A number is ugly if its factors are limited to only 2 or 3 or 5

//For a number say 'number'
//Eliminate all the factors of 2, 3 and 5

//After elemination if the 'number' is 1, then the 'number' has 2,3,5 as its factors only 
//If the 'number' is not 1. Then there exist a factor other than 2,3,5.

//We can eliminate the particular factors say 'a' from 'number' by
//Dividing the number with 'a' until the remainder becomes a non zero 



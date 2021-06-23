//LC 168. Excel Sheet column Title
//Link: https://leetcode.com/problems/excel-sheet-column-title

#include<iostream>
using namespace std;

string numberToTitle(long long number){
	string res = "";
	while(number){
		int rem = (number % 26);
		number /= 26;
		if(rem)
			res = char(rem + 64) + res;
		else{
			res = 'Z' + res;
			--number;
		}
	}
	return res;
}

int main(){
	cout<<numberToTitle(INT_MAX)<<endl;
	cout<<numberToTitle(5537)<<endl;
	return 0;
}


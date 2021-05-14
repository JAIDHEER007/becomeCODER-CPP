#include<bits/stdc++.h>
using namespace std;

int inline ctoi(char digit){
	return digit - '0';
}

int main(){
	//50 digit number
	string num1 = "6500279974475861000129972487405262108162558460499110056797931547503195706942909900855716138020618882";
	string num2 = "3989708836510172361286662415649453898219547093037086910765348422229211653419896427415912078768174214";
//	cin>>num1>>num2;
	
	int len_num1 = num1.length();
	int len_num2 = num2.length();
	
	//making the two strings to equal lengthed
	//by adding padding zeroes to left
	//using string fill constructor
	if(len_num1 < len_num2){
		num1 = string((len_num2 - len_num1),'0') + num1;
		len_num1 = len_num2; 
	}else if(len_num1 > len_num2){
		num2 = string((len_num1 - len_num2),'0') + num2;
		len_num2 = len_num1;
	}
	
	string res = "";
		
	int carry = 0;
	for(int i=len_num1-1, j=len_num2-1;(i>=0)&&(j>=0);i--,j--){
		int sum = (ctoi(num1[i]) + ctoi(num2[j])) + carry;
		res = (to_string(sum%10)) + res;
		carry = sum/10;
	}
	if(carry)
		res = to_string(carry) + res;
	
	cout<<res<<endl;
	
	return 0;
}

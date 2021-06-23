//LC 168. Excel Sheet column Title
//Link: https://leetcode.com/problems/excel-sheet-column-title
//Reference Link: https://github.com/JAIDHEER007/becomeCODER-CPP/blob/aa224af9856080b9049fc76c15359cd9cf29d3ed/PDF/LC_171_168_EXCEL_SHEET.pdf

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


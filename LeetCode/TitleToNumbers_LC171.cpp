//LC 171. Excel Sheet Column Number
//Link: https://leetcode.com/problems/excel-sheet-column-number/
//Reference Link: https://github.com/JAIDHEER007/becomeCODER-CPP/blob/aa224af9856080b9049fc76c15359cd9cf29d3ed/PDF/LC_171_168_EXCEL_SHEET.pdf

#include<iostream>
using namespace std;

long long titleToNumbers(string text){
	int text_len = text.length();
	long long base = 1;
	long long columnNumber = 0;
	
	for(int i=text_len-1;i>=0;i--){
		int ch_int = (text[i]-'A'+1);
		columnNumber += (ch_int * base);
		base *= 26;
	}
	
	return columnNumber;
}

long long titleToNumbers2(string text){
	long long result = 0;
	for(int ch_int:text)
		result = (result * 26) + (ch_int - 64);
	return result;
}

int main(){
	cout<<titleToNumbers("A")<<endl;
	cout<<titleToNumbers("ZY")<<endl;
	cout<<titleToNumbers("FXSHRXW")<<endl;
	cout<<titleToNumbers("JAIDHEER")<<endl;

	
	cout<<titleToNumbers2("A")<<endl;
	cout<<titleToNumbers2("ZY")<<endl;
	cout<<titleToNumbers2("FXSHRXW")<<endl;
	cout<<titleToNumbers2("JAIDHEER")<<endl;

	return 0;
}

//Its similar to Number System





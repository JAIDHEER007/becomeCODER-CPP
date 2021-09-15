// Leetcode 917 Reverse Only Letters
// https://leetcode.com/problems/reverse-only-letters/

#include<iostream>
using namespace std; 

bool inline isalpha(char ch){
	return ((ch <= 'z' && ch >= 'a')||(ch <= 'Z' && ch >= 'A'));
}

string reverseOnlyLetters(string s){
	string onlyAlphabets = "";
	
	for(char ch:s)
		if(isalpha(ch)) onlyAlphabets = ch + onlyAlphabets; 
	
	int index = 0;
	for(char &ch:s)
		if(isalpha(ch)) ch = onlyAlphabets[index++];
	return s;
}

int main(){
	cout<<reverseOnlyLetters("ab-cd")<<endl;
	cout<<reverseOnlyLetters("Test1ng-Leet=code-Q!")<<endl; 
	
	return 0; 
}

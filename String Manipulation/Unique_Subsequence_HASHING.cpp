//Finding the unique subsequence

#include<iostream>
#include<vector>
using namespace std;

string uniqueSubsequence(string text){
	vector<bool> alphabets(26);
	string result = "";
	for(char ch:text){
		if(!alphabets[ch - 'A']){
			result += ch;
			alphabets[ch - 'A'] = true;
		}
	}
	
	return result;
}

int main(){
	cout<<uniqueSubsequence("JAIDHEER")<<endl;
	cout<<uniqueSubsequence("AAA")<<endl;
	cout<<uniqueSubsequence("BCA")<<endl;
	cout<<uniqueSubsequence("DDE")<<endl;
	cout<<uniqueSubsequence("AAB")<<endl;
	cout<<uniqueSubsequence("CCA")<<endl;
	cout<<uniqueSubsequence("ADA")<<endl;
	return 0;
}

//Question 8
//String Reduction

#include<bits/stdc++.h>
#define NeedForSpeed ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int getMinDeletions(string test){
	bool *alphabets = new bool[26]();
	int deletions = 0;
	for(char ch:test){
		if(!alphabets[ch-'a']){
			++deletions; 
			alphabets[ch-'a'] = true; 			
		}
	}
	delete[] alphabets;
	return test.length() - deletions;
}
int main(){
	NeedForSpeed;
	
	cout<<getMinDeletions("abab")<<endl;
	cout<<getMinDeletions("abcab")<<endl;
	cout<<getMinDeletions("abcabc")<<endl;	
	
	return 0;
}




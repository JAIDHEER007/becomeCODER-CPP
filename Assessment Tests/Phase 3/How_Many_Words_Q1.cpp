//Question 1
//How Many Words

#include<bits/stdc++.h>
#define NeedForSpeed ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

bool inline isValidChar(char ch){
	return (((ch>='a')&&(ch<='z'))||((ch>='A')&&(ch<='Z')));
}

bool isValidLastChar(char ch){
	return (isValidChar(ch))||(ch=='.')||(ch==',')||(ch=='?')||(ch=='!');
}

bool isValidWord(string word){
	int word_len = word.length();
	
	if(word_len == 1)
		return isValidChar(word[0]);
	
	if(isValidLastChar(word[word_len-1]))
		--word_len;
	else
		return false; 
	
	for(int i=0;i<word_len;++i){
		if((isValidChar(word[i]))||(word[i]=='-'))
			continue; 
		else
			return false;
	}
	return true;
}

int howMany(string sentence){
	int count = 0;
	stringstream ss(sentence);
	string word;
	
	while(ss>>word)
		if(isValidWord(word)){ ++count; }
	
	return count; 
}

int main(){
	NeedForSpeed;
	
	string sentence; 
	getline(cin,sentence);
	
	cout<<howMany(sentence)<<endl;
	
	return 0;
}




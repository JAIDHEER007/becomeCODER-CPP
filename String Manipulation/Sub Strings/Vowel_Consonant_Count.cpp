//Number of substrings that start with Vowel or Consonants

#include<iostream>
using namespace std;

bool inline isVowel(char ch){
	return ((ch == 'a')||(ch == 'e')||(ch == 'i')||(ch == 'o')||(ch == 'u'));
}

int vowelCount(string text){
	int count = 0;
	for(int i=0;i<text.length();i++)
		if(isVowel(text[i])){ count += (text.length() - i); }
	return count; 
}

int consonantCount(string text){
	int count = 0;
	for(int i=0;i<text.length();i++)
		if(!isVowel(text[i])){ count += (text.length() - i); }
	return count; 
}

int main(){
	string text = "jaidheer";
	
	cout<<"Number of substrings that start with Vowel: "<<vowelCount(text)<<endl;
	cout<<"Number of substrings that start with Consonant: "<<consonantCount(text)<<endl;
	
	return 0;
}

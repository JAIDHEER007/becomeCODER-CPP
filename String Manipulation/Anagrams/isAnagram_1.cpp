//Checking if a string is anagram or not

//Two strings are said to be anagrams if one can be formed from 
//other by just rearranging the letters

//Example:
//string1: red lips like tenth
//string2: kill the president

//string2 can be formed by rearranging the letters of string2

//Approaches:
//Method 1
//If the strings are alphanumeric, contains uppercase, lowercase and special characters
//then better way is to sort the strings

//if string1.sorted == string2.sorted then they are anagrams

//This method takes O(nlogn) time to sort 

//Method 2: Using map data structure. 

//Method 3: using hashing

#include<iostream>
#include<vector>

using namespace std;

bool isAnagram(string str1, string str2){
	if(str1.length() != str2.length()){ return false; }
	vector<int> alphabets(26);
	
	for(char alphabet:str1)
		alphabets[alphabet - 'a']++;
	for(char alphabet:str2)
		alphabets[alphabet - 'a']--;
	for(int frequency:alphabets)
		if(frequency!=0){ return false; }
	return true; 
	
}

int main(){
	string str1, str2;
	cin>>str1>>str2;
	
	cout<<boolalpha<<isAnagram(str1, str2)<<endl;
	
	return 0;
}


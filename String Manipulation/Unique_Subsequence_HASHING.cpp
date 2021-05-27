//Finding the unique subsequence

#include<iostream>
#include<vector>
using namespace std;

string uniqueSubsequence(string text){
//	vector<bool> alphabets(26);
	bool alphabets[26] = { false };
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
	cout<<uniqueSubsequence("JAIDHEER")<<endl;				//JAIDHER
	cout<<uniqueSubsequence("AAA")<<endl;					//A
	cout<<uniqueSubsequence("BCA")<<endl;					//BCA
	cout<<uniqueSubsequence("DDE")<<endl;					//DE
	cout<<uniqueSubsequence("AAB")<<endl;					//AB
	cout<<uniqueSubsequence("CCA")<<endl;					//CA
	cout<<uniqueSubsequence("ADA")<<endl;					//AD
	cout<<uniqueSubsequence("AAABBBDDDCCCEEEABCD")<<endl;	//ABDCE
	
	return 0;
}

/*
a subsequence is a sequence that can be derived from another sequence by 
deleting some or no elements without changing the order of the remaining elements

For Example, consider JAIDHEER
Subsequence can be
JAIDHEER
JADH
EER
AID
ADEER

Subequence will formed from by deleting some characters form given string
but without changing the order of occurence of elements

Unique sunsequence if is similar to subsequence but repeating elements will be deleted

For example consider the string AAABBBDDDCCCEEEABCD

The unique subsequence will be ABDCE

In the given string the order of occurence of unique string is A B D C E (remaing characters are deleted)

► Ideas ◄

══════════
║ IDEA 1 ║
══════════

► maintain a blank string called output 

► traverse the given string from left to right

► if the output string is empty simply concat the trvaersed character to the output string

► if the output string is not empty. Check for traveresed character in the output string

	►► if the traversed charcarter is present already simply skip the loop
	►► if not, then concatenate the traversed character to the output string
	
♦ This method works fine but inorder to check if the traversed character is present in the given string 
or not, We have to travrese the output string everytime for each and every character in the input
string. 

♦ This is much time taking process for large strings

♦ but this process is suitable for alphanumeric strings and strings with special charcater

══════════
║ IDEA 2 ║
══════════

►► if the input string is restricted to lowercase, uppercase, numeric values this method can be used 

► The idea is to flag array declared to accept boolean value for all 26 alphabets

► Here in C++, a vector declared to accept boolean values is initalized to false automatically

► The hash of each alphabet is given by (taversed character - 'A') (For this problem all string is in upper case)

► Now Traverse the string from left to right

► if hash value of a the traversed character given by hash formula, (taversed character - 'A') is false

► Then add the character to output string and set the hash value to true

► So, if the same traversed character occurs again, The hash value will be true. So, simply skip it.

► In this way, we can determine if the trvaersed charcater is present in the output string or not in O(1) time.

■ a single boolean variable taken 1 byte of space in c++;

■ vector<bool> alphabets(26) ==> 40 bytes of space due to library functions

■ bool alphabets(26) = { false }; ==> 26 bytes of space as there are no library functions

■ So, for simple hashing using normal array instead of vector is better.

■ These sizes are found using sizeof operator.


*/

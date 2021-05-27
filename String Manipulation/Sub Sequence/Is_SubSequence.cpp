#include<iostream>
using namespace std;

bool isSubSequence(string main, string text){
	int i = 0;
	for(char ch:text){
		int index = -1;
		for(;i<main.length();i++){
			if(main[i] == ch){
				index = i;
				break;
			}
		}
		if(index == -1){ return false; }
		i++;
	}
	return true;
}

int main(){
	cout<<boolalpha;
	
	cout<<isSubSequence("jaidheer","jar")<<endl;
	cout<<isSubSequence("jaidheer","air")<<endl;
	cout<<isSubSequence("jaidheer","raj")<<endl;
	cout<<isSubSequence("bbaaaa","aaaaaa")<<endl;
	
	string main = "EJFWXIIQCDJBECRGEHRWAUQYJRDJJGPORSDRWXLYFZEFKEJBBUBYOWMFSZKIBDXZUCRTWDQOHFYWHGBIOFUHEXUXYOKBSAAAUFKCOOBUYKHUNWHFOCPPHZRKQLKVMIJQWRUHINFBUJCOXPIQWPIPUVIHPPUSESKEJJKFHBAKIZYRHECATGRLACZBEFOLPPWDSBHFBYBA";
	string text = "EJFWXIQCDBRGHAUYPOSLZKMTNV"; //UniqueSubsequence of main. Refer Unique_Subsequence.cpp for more information
	
	cout<<isSubSequence(main,text)<<endl;
	
	return 0;
}

//Working

//Subsequence is string formed form deleting some charcaters in the given string 
//but without changing the relative position

//here consider two strings 'main' and 'text'

//We have to find wether 'text' is a substring of 'main' or not.

//In most of the cases 'text' will be smaller than 'main'

//So iterating the 'text' string is better than iterating 'main' string

//So we will trvaerse the 'text' string from left to right and for each charcater 
//We will perform linear search in the 'main' string

//But the linear search will not start from zero for each charcater in 'text' string
//Initially it will be started from 0 onwards, but for next Character it will be started from
//next index of location of previous charcater

//If index is -1, then the character is not present, So 'text' will not be subsequence at all. Simply return false

//If the loop completes without any problem. Then return true.


//Largest Substring that starts and ends with a given character

#include<iostream>
using namespace std;

//Most Naive Implementation
string largestSubStr_se_naive(string text, char start, char end){
	string largest_substr = "";
	for(int i=0;i<text.length();i++){
		for(int j=i;j<text.length();j++){
			string sub_str = text.substr(i,(j-i+1));
			if((sub_str[0]==start)&&(sub_str[sub_str.length()-1]==end)){
				if(sub_str.length() > largest_substr.length())
					largest_substr = sub_str;
			}
		}
	}
	return largest_substr;
}

//Efficient Implementation
string largestSubStr_se_efficient(string text, char start, char end){
	int start_ptr = 0;
	for(;start_ptr<text.length();start_ptr++)
		if(text[start_ptr] == start){ break; }
	if(start_ptr == text.length()){
		return "";
	}
	
	int end_ptr = text.length() - 1;
	for(;end_ptr >= 0;end_ptr--)
		if(text[end_ptr] == end){ break; }
	if(end_ptr == -1){
		return "";
	}
	
	return text.substr(start_ptr,(end_ptr - start_ptr + 1));
}

int main(){
	
	cout<<largestSubStr_se_naive("HASFJGHOGAKZZFEGA",'A','Z')<<endl;
	cout<<largestSubStr_se_efficient("HASFJGHOGAKZZFEGA",'A','Z')<<endl;
	
	cout<<largestSubStr_se_naive("ThisIsATest",'T','t')<<endl;
	cout<<largestSubStr_se_efficient("ThisIsATest",'T','t')<<endl;
	
	cout<<largestSubStr_se_naive("ThisIsATest",'T','T')<<endl;
	cout<<largestSubStr_se_efficient("ThisIsATest",'T','T')<<endl;
	
	cout<<largestSubStr_se_naive("Jaidheer",'J','J')<<endl;
	cout<<largestSubStr_se_efficient("Jaidheer",'J','J')<<endl;
	
	cout<<largestSubStr_se_naive("Jaidheer",'r','r')<<endl;
	cout<<largestSubStr_se_efficient("Jaidheer",'r','r')<<endl;
	
	cout<<largestSubStr_se_naive("QWERTY",'Q','A')<<endl;
	cout<<largestSubStr_se_efficient("QWERTY",'Q','A')<<endl;
	
	cout<<largestSubStr_se_naive("QWERTY",'A','Y')<<endl;
	cout<<largestSubStr_se_efficient("QWERTY",'A','Y')<<endl;
	
	cout<<largestSubStr_se_naive("QWERTY",'A','A')<<endl;
	cout<<largestSubStr_se_efficient("QWERTY",'A','A')<<endl;
	
	
	return 0;
}

/*
Idea:
Naive implementation is to check all the substrings and find the match

Efficient implementation is to check for first occurence of start character from left
and for the first occurence of end character from the right.

It will give the first occurences of start and end characters

now return the substring.

The substring length will be (end_pos - start_pos + 1)
*/

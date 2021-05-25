//Substring

#include<iostream>
using namespace std;

int main(){
	int substr_count = 0;
	string text = "jaidheer";
	
	for(int i=0;i<text.length();i++){
		for(int j=i;j<text.length();j++){
			cout<<(text.substr(i,(j-i+1)))<<endl;
			substr_count++;
		}
	}
	
	cout<<endl<<"Total substrings: "<<substr_count<<endl;
	
	//Using direct formula
	cout<<"Total substrings: "<<(((text.length())*(text.length() + 1))/2)<<endl;

	return 0;
}

/*
Idea:
Substrings that can be generated from string jaidheer

----------------------------------------------------------------------
j	a	i	d	h	e	e	r
^

j
ja
jai
jaid
jaidh
jaidhe
jaidhee
jaidheer						Total Substrings Starting with 'j': 8
----------------------------------------------------------------------
----------------------------------------------------------------------
j	a	i	d	h	e	e	r
    ^

a
ai
aid
aidh
aidhe
aidhee
aidheer							Total Substrings Starting with 'a': 7
----------------------------------------------------------------------
----------------------------------------------------------------------
j	a	i	d	h	e	e	r
        ^

i
id
idh
idhe
idhee
idheer							Total Substrings Starting with 'i': 6
----------------------------------------------------------------------
----------------------------------------------------------------------
j	a	i	d	h	e	e	r
        	^

d
dh
dhe
dhee
dheer							Total Substrings Starting with 'd': 5
----------------------------------------------------------------------
----------------------------------------------------------------------
j	a	i	d	h	e	e	r
        		^

h
he
hee
heer							Total Substrings Starting with 'h': 4
----------------------------------------------------------------------
----------------------------------------------------------------------
j	a	i	d	h	e	e	r
        			^

e
ee
eer								Total Substrings Starting with 'e': 3
----------------------------------------------------------------------
----------------------------------------------------------------------
j	a	i	d	h	e	e	r
        				^

e
er								Total Substrings Starting with 'e': 2
----------------------------------------------------------------------
----------------------------------------------------------------------
j	a	i	d	h	e	e	r
        					^

r								Total Substrings Starting with 'r': 1
----------------------------------------------------------------------


So, total number of substrings is 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 = 36

Let length of given string be 'N'
So by observation we can deduce a formula for total number of substrings

It is the sum of first N natural numbers: (N*(N+1)) / 2

*/

/*
About substr() function
synatx: string substr (size_t pos, size_t len)

It will return the substring, starting from 'pos' and having length 'len'

*/

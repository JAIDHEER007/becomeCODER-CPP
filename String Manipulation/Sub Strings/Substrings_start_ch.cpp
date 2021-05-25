//Susbtrings starting with a given character

#include<iostream>
using namespace std;

//Naive Implementation
int subStrs_start_ch_naive(string text, char start){
	int count = 0;
	for(int i=0;i<text.length();i++){
		for(int j=i;j<text.length();j++){
			string sub_str = text.substr(i,(j-i+1));
			if(sub_str[0] == start){ count++; } 
		}
	}
	return count; 
}

//Efficient Implementation
int subStrs_start_ch_effcient(string text, char start){
	int count = 0;
	for(int i=0;i<text.length();i++){
		if(text[i] == start)
			count += (text.length() - i); 
	}
	return count;
}
int main(){
	string text = "lpzxxvyxfu";
	char start = 'x';
	
	cout<<subStrs_start_ch_naive(text,start)<<endl;
	cout<<subStrs_start_ch_effcient(text,start)<<endl;
	
	return 0;
}

/*
Idea:

1. Naive Implementation is to find all substrings and increment the count for every
   string that starts with given character
   
2. Efficient implementation

length of given string = n = 10

l	p	z	x	x	v	y	x	f	u
0	1	2	3	4	5	6	7	8	9

all Substrings
-----------------------------------------
l	p	z	x	x	v	y	x	f	u
0	1	2	3	4	5	6	7	8	9
^

l
lp
lpz
lpzx
lpzxx
lpzxxv
lpzxxvy
lpzxxvyx
lpzxxvyxf
lpzxxvyxfu

Total substrings: 10 (or) n - 0
-----------------------------------------
-----------------------------------------

l	p	z	x	x	v	y	x	f	u
0	1	2	3	4	5	6	7	8	9
	^

p
pz
pzx
pzxx
pzxxv
pzxxvy
pzxxvyx
pzxxvyxf
pzxxvyxfu

Total substrings: 9 (or) n - 1
-----------------------------------------
-----------------------------------------

l	p	z	x	x	v	y	x	f	u
0	1	2	3	4	5	6	7	8	9
		^

z
zx
zxx
zxxv
zxxvy
zxxvyx
zxxvyxf
zxxvyxfu

Total substrings: 8 (or) n - 2
-----------------------------------------
-----------------------------------------

l	p	z	x	x	v	y	x	f	u
0	1	2	3	4	5	6	7	8	9
			^

x
xx
xxv
xxvy
xxvyx
xxvyxf
xxvyxfu

Total substrings: 7 (or) n - 3
-----------------------------------------
-----------------------------------------

l	p	z	x	x	v	y	x	f	u
0	1	2	3	4	5	6	7	8	9
				^

x
xv
xvy
xvyx
xvyxf
xvyxfu

Total substrings: 6 (or) n - 4
-----------------------------------------
-----------------------------------------

l	p	z	x	x	v	y	x	f	u
0	1	2	3	4	5	6	7	8	9
					^

v
vy
vyx
vyxf
vyxfu

Total substrings: 5 (or) n - 5
-----------------------------------------
-----------------------------------------

l	p	z	x	x	v	y	x	f	u
0	1	2	3	4	5	6	7	8	9
						^

y
yx
yxf
yxfu

Total substrings: 4 (or) n - 6
-----------------------------------------
-----------------------------------------

l	p	z	x	x	v	y	x	f	u
0	1	2	3	4	5	6	7	8	9
							^

x
xf
xfu

Total substrings: 3 (or) n - 7
-----------------------------------------
-----------------------------------------

l	p	z	x	x	v	y	x	f	u
0	1	2	3	4	5	6	7	8	9
								^
				
f
fu

Total substrings: 2 (or) n - 8
-----------------------------------------
-----------------------------------------

l	p	z	x	x	v	y	x	f	u
0	1	2	3	4	5	6	7	8	9
									^
				
u

Total substrings: 1 (or) n - 9
-----------------------------------------
-----------------------------------------

Just find the sum of substring count that starts with given character

*/

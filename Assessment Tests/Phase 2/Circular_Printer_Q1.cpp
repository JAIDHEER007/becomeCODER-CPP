//Question 1
//Circular Printer

// Similar Question in LeetCode: 1974. Minimum Time to Type Word Using Special Typewriter
//Link: https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter/

#include<bits/stdc++.h>
#define NeedForSpeed ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int inline ctoi(char ch){
	return (ch-'A')+1;
}

long getTime(string test){
	char source = 'A';
	long total_time = 0;
	for(char destination:test){
		int time1 = abs(ctoi(destination)-ctoi(source));
		int time2 = 26 - time1;
		total_time += min(time1,time2);
		source = destination;
	}
	return total_time; 
}

int main(){
	NeedForSpeed;
	
	cout<<getTime("BZA")<<endl;
	cout<<getTime("AZGB")<<endl;
	cout<<getTime("ZNMD")<<endl;
	
	return 0;
}




//A. And Then There Were K 
//CodeForces 721 problem A
//Link: https://codeforces.com/contest/1527/problem/A
//My Submission Link: https://codeforces.com/contest/1527/submission/119995332


#include<iostream>
using namespace std;

int findK_naive(int number){
	int result = number;
	for(int i=1;i<=number;i++){
		result &= (number - i);
		if(result == 0){ return (number - i); }
	}
}

int findK_efficient(int number){
	if(number == 1)
		return 0;
	if((number == 2) || (number == 3))
		return 1;
	int bits = 0;
	for(;number;(++bits, number>>=1));
	return ((1<<(bits-1)) - 1);
	
}

int main(){
	cout<<findK_naive(17)<<endl;
	cout<<findK_efficient(17)<<endl;
	
	
	return 0;
}

//Approach:
//Use the Naive Method which you can figure out
//Print the k value from 1 to 553 
//Analyze the pattern 
//Link: https://github.com/JAIDHEER007/becomeCODER-CPP/blob/main/PDF/And%20Then%20There%20Were%20K.pdf

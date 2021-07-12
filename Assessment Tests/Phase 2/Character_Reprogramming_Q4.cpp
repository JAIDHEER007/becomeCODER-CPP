//Question 4
//Character Reprogramming

#include<bits/stdc++.h>
#define NeedForSpeed ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int getMaxDeletions(string moves){
	pair<int,int> initial;
	pair<int,int> final;
	
	for(char move:moves){
		switch(move){
			case 'U': 
				++(final.first);
				break;
			case 'D':
				--(final.first);
				break;
			case 'R':
				++(final.second);
				break;
			case 'L':
				--(final.second);
				break;
		}	
	}
	int v_diff = final.first - initial.first;
	int h_diff = final.second - initial.second;
	
	return (moves.length() - (v_diff+h_diff));
}

int main(){
	NeedForSpeed;
	
	cout<<getMaxDeletions("URDR")<<endl;
	cout<<getMaxDeletions("RRR")<<endl;
	cout<<getMaxDeletions("RUDRL")<<endl;
	
	return 0;
}




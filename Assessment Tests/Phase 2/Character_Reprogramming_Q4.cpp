//Question 4
//Character Reprogramming

#include<bits/stdc++.h>
#define NeedForSpeed ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int getMaxDeletions(string moves){
	pair<int,int> start;
	pair<int,int> end;
	
	for(char move:moves){
		switch(move){
			case 'U': 
				++(end.first);
				break;
			case 'D':
				--(end.first);
				break;
			case 'R':
				++(end.second);
				break;
			case 'L':
				--(end.second);
				break;
		}	
	}
	int v_diff = end.first - start.first;
	int h_diff = end.second - start.second;
	
	return (moves.length() - (v_diff+h_diff));
}

int main(){
	NeedForSpeed;
	
	cout<<getMaxDeletions("URDR")<<endl;
	cout<<getMaxDeletions("RRR")<<endl;
	cout<<getMaxDeletions("RUDRL")<<endl;
	
	return 0;
}




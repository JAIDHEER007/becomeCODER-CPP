//Given a rope of length 'N'
//Also given, three possible cut lengths a,b,c

//Return the max number of cuts that can be made

#include<iostream>
using namespace std;

int maxCuts(int N, int a, int b, int c){
	if(N == 0)
		return 0;
	if(N < 0)
		return -1;
	int fcall1 = maxCuts((N-a),a,b,c);
	int fcall2 = maxCuts((N-b),a,b,c);
	int fcall3 = maxCuts((N-c),a,b,c);
	
	int max_res = max(fcall1, max(fcall2, fcall3)); 
	
	return ((max_res < 0)?(-1):(max_res + 1));
}

int main(){
	cout<<maxCuts(4,1,2,4)<<endl;
	cout<<maxCuts(10,4,3,2)<<endl;
	cout<<maxCuts(100,3,7,9)<<endl;
	
	return 0;
}

//Actual Combinations are not Calculated 

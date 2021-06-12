//Given a rope of length 'N'
//Also given, three possible cut lengths a,b,c

//Return the max number of cuts that can be made

//Optimized with Dynamic programming

#include<iostream>
#include<vector>
using namespace std;

typedef vector<int> vi;

int Cuts(int N, int a, int b, int c, vi &dp){
	if(N < 0)
		return -1;
	if(dp[N] != -1)
		return dp[N];
	int fcall1 = Cuts((N-a),a,b,c,dp);
	int fcall2 = Cuts((N-b),a,b,c,dp);
	int fcall3 = Cuts((N-c),a,b,c,dp);
	
	int max_res = max(fcall1, max(fcall2, fcall3)); 
	
	return (dp[N] = ((max_res < 0)?(-1):(max_res + 1)));
}

int maxCuts(int N, int a, int b, int c){
	if(N == 0)
		return 0;
	if(N < 0)
		return -1;
	vi dp(N+1,-1);
	dp[0] = 0;
	return Cuts(N,a,b,c,dp);
	
}

int main(){
//	cout<<maxCuts(4,1,2,4)<<endl;
//	cout<<maxCuts(10,4,3,2)<<endl;
	cout<<maxCuts(100,3,7,9)<<endl;
	
	return 0;
}

//Question 2
//Portfolio Balances

#include<bits/stdc++.h>
#define NeedForSpeed ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

long maxValue(int n, vector<vector<int>> rounds){
	vector<long> arr(n+1);
	for(vector<int> _round:rounds){
		arr[_round[0]-1] += _round[2];
		arr[_round[1]] += (-1 * _round[2]);
	}
	long max = arr[0];
	for(int i=1;i<arr.size();++i){
		arr[i] += arr[i-1];
		if(arr[i] > max){ max = arr[i]; }
	}
	
	return max; 
}

int main(){
	NeedForSpeed;
	
	int n; cin>>n; //Number of Investements
	int numRounds; cin>>numRounds;
	
	vector<vector<int>> rounds; 
	vector<int> roundInfo(3);
	
	for(int i=0;i<numRounds;++i){
		cin>>roundInfo[0]>>roundInfo[1]>>roundInfo[2];
		rounds.push_back(roundInfo);
	} 
	
	cout<<maxValue(n,rounds);
	
	return 0;
}




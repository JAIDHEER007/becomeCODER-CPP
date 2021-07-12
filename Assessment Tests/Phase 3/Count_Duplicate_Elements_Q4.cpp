//Question 4
//Count Duplicate Elements

#include<bits/stdc++.h>
#define NeedForSpeed ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int countDuplicates(vector<int> numbers){
	map<int,int> table;
	for(int number:numbers)
		++table[number];
		
	int duplicates = 0;
	for(auto it:table)
		if((it.second)>1){ ++duplicates; }
		
	return duplicates; 
}

int main(){
	NeedForSpeed;
	
	int n; cin>>n;
	vector<int> arr;
	
	for(int i=0;i<n;++i){
		int num; cin>>num;
		arr.push_back(num);
	}
	
	cout<<countDuplicates(arr)<<endl;
	
	return 0;
}




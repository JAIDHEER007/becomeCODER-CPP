//Question 2
//Sort the Summary

#include<bits/stdc++.h>
#define NeedForSpeed ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

vector<vector<int>> groupSort(vector<int> arr){
	map<int,int> table1;
	for(int element:arr)
		++table1[element];
	map<int,vector<int>> table2;
	for(auto it:table1)
		table2[it.second].push_back(it.first);
	for(auto &it:table2)
		sort((it.second).begin(),(it.second).end());
	vector<vector<int>> result;
	map<int,vector<int>>::reverse_iterator itr = table2.rbegin();
	for(;itr!=table2.rend();++itr){
		for(int element:(itr->second))
			result.push_back({element,(itr->first)});
	}
	return result;
}
int main(){
	NeedForSpeed;
	int n; 
	cin>>n;
	
	vector<int> arr;
	for(int i=0;i<n;++i){
		int num; cin>>num;
		arr.push_back(num);
	}
	vector<vector<int>> result = groupSort(arr);
	
	for(vector<int> row:result){
		for(int element:row)
			cout<<element<<" ";
		cout<<endl;
	}
	
	return 0;
}




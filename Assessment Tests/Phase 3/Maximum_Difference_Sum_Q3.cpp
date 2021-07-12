//Question 3
//Maximmum Difference Sum

#include<bits/stdc++.h>
#define NeedForSpeed ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int inline absDiff(int a, int b){
	return abs(a-b);
}

int minDiff(vector<int> arr){
	sort(arr.begin(),arr.end());
	int sum = 0;
	for(int i=1;i<arr.size();++i)
		sum += absDiff(arr[i],arr[i-1]);
	return sum; 
}

int main(){
	NeedForSpeed;
	
	int n; cin>>n;
	vector<int> arr;
	for(int i=0;i<n;++i){
		int num; cin>>num;
		arr.push_back(num);
	}
	
	cout<<minDiff(arr)<<endl;
	
	return 0;
}




//Question 11
//Maximizing the Final Element 

#include<bits/stdc++.h>
#define NeedForSpeed ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

bool inline isGood(int a, int b){
	return (a-b)<=1;
}

int getMaxValue(vector<int> arr){
	sort(arr.begin(),arr.end());
	if(arr[0]!=1)
		arr[0] = 1;
	
	for(int i=1;i<arr.size();++i){
		if(isGood(arr[i],arr[i-1]))
			continue;
		arr[i] = arr[i-1]+1; 
	}
	return arr[arr.size()-1];
}

int main(){
	NeedForSpeed;
	
	vector<int> arr;
	
	arr = {3,1,3,4};
	cout<<getMaxValue(arr)<<endl;
	
	arr = {1,3,2,2};
	cout<<getMaxValue(arr)<<endl;
	
	arr = {3,2,3,5};
	cout<<getMaxValue(arr)<<endl;
	
	return 0;
}




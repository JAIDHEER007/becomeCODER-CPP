//Question 3
//Programming Contest

#include<bits/stdc++.h>
#define NeedForSpeed ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int inline giveMeBias(int a, int b){
	return abs(a-b);
}

int minimizeBias(vector<int> ratings){
	int total_bias = 0;
	sort(ratings.begin(),ratings.end());
	for(int i=0;i<ratings.size();i+=2)
		total_bias += giveMeBias(ratings[i],ratings[i+1]);	
	return total_bias;
}

int main(){
	NeedForSpeed;
	vector<int> arr;
	
	arr = {4,2,5,1};
	cout<<minimizeBias(arr)<<endl;
	
	arr = {1,3,6,6};
	cout<<minimizeBias(arr)<<endl;
	
	arr = {2,4,5,3,7,8};
	cout<<minimizeBias(arr)<<endl;
	
	return 0;
}




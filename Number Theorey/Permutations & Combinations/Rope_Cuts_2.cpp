//Given a rope of length 'N'
//It can be cut in possible ways given by array 'a'
//Return the max number of cuts that are possible


#include<iostream>
#include<vector>

using namespace std;

typedef vector<int> vi;

void maxCuts(int N, vi &a, vi &arr, int &max_cuts, int index = 0){
	if(index == a.size()){
		if(N == 0){
			if(arr.size() > max_cuts)
				max_cuts = arr.size();
		}
		return;
	}
	if(a[index] <= N){
		arr.push_back(a[index]);
		maxCuts((N - a[index]),a,arr,max_cuts,index);
		arr.pop_back();
	}
	maxCuts(N,a,arr,max_cuts,index+1);
}

int main(){
	vi arr;
	vi a{2,1,4}; //Possible Cuts
	int max_cuts = 0;
	
	maxCuts(6,a,arr,max_cuts);
	
	cout<<max_cuts<<endl;
	
	return 0;
}

//This Method is Not so efficient 
//All we need is the max number of cuts only
//We dont need the actual combinations



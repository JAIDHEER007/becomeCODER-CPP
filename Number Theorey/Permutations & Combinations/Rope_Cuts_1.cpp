//Rope Cuts

#include<iostream>
#include<vector>
using namespace std;

void permutateNsum(int n, vector<int> arr, vector<int> &cut_lengths, int &max_cuts){
	if(n == 0){
		if(arr.size() > max_cuts)
				max_cuts = arr.size();
		return;
	}
	for(int cut_length:cut_lengths){
		arr.push_back(cut_length);
		if((n - cut_length) >= 0)
			permutateNsum((n - cut_length),arr,cut_lengths,max_cuts);
		arr.pop_back();
	}
}

int main(){
	vector<int> arr;
	vector<int> cuts_lengths{2,1};
	
	int max_cuts = 0;
	
	permutateNsum(5,arr,cuts_lengths,max_cuts);
	
	cout<<max_cuts<<endl;
	
	return 0;	
}

//This Method is Not so efficient 
//All we need is the max number of cuts only
//We dont need the actual combinations
//Moreover this algorithm generates repeating combinations which result in same number of cuts


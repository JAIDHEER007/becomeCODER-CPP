//Sort an array of 0s, 1s and 2s
// Link: https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/

#include<iostream>
#include<vector>
using namespace std;

typedef vector<int> vi;

vi sort_012(vi arr){
	vi frequency(3);
	for(int element:arr)
		frequency[element]++;
	vi result;
	for(int i=0;i<frequency.size();i++){
		for(int j=0;j<frequency[i];j++)
			result.push_back(i);
	}
	return result;
}

int main(){
	vi arr{0, 1, 2, 0, 1, 2};
	vi result = sort_012(arr);
	
	for(int element:result)
		cout<<element<<" ";
	cout<<endl;
	
	return 0;
}

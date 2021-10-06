// LC 48 Rotate Image
// https://leetcode.com/problems/rotate-image/

#include<iostream>
#include<vector>
using namespace std;

//typedef vector<int> vi;

void print(vector<vector<int>> matrix){
	for(vector<int> row:matrix){
		for(int element:row)
			cout<<element<<" ";
		cout<<endl;
	}
	cout<<endl;
}

void transpose(vector<vector<int>> &matrix){
	int n = matrix.size(); 
	
	for(int i=0;i<n;++i){
		for(int j=i;j<n;++j)
			swap(matrix[i][j], matrix[j][i]); 
	}
}

void rotate(vector<vector<int>> &matrix){
	transpose(matrix);
	
	int n = matrix.size(); 
	
	for(int i=0;i<(n >> 1);++i){
		for(int j=0;j<n;++j)
			swap(matrix[j][i], matrix[j][n - i - 1]);
	}
}

int main(){

	vector<vector<int>> matrix{{1, 2, 3},
							   {4, 5, 6},
							   {7, 8, 9}};
							   
	print(matrix);
	
//	transpose(matrix);
	
//	print(matrix); 
	
	rotate(matrix); 
	
	print(matrix); 
	
	return 0;
}



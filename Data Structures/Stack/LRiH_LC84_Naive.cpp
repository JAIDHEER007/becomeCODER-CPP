// 84. Largest Rectangle in Histogram
// https://leetcode.com/problems/largest-rectangle-in-histogram/
// Brute Force Approach

#include<iostream>
#include<vector>

using namespace std; 

int largestRectangleArea(vector<int> &heights){
	int maxArea = INT_MIN; 
	int limit = heights.size(); 
	
	for(int i=0;i<limit;++i){
		int height = heights[i]; 
		
		int lb = i - 1;
		int rb = i + 1; 
		
		while((lb >= 0) && (heights[lb] >= height)) --lb;
		while((rb < limit) && (heights[rb] >= height)) ++rb;
		++lb;
		--rb; 
		
		// cout<<height<<" "<<lb<<" "<<rb<<endl; 
		int area = (rb - lb + 1) * height; 

		if(area > maxArea) maxArea = area; 
	}

	return maxArea; 
}

int main(){
	vector<int> arr{2,1,5,6,2,3};
	
	cout<<largestRectangleArea(arr)<<endl;
	
	return 0; 
}

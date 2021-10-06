// 84. Largest Rectangle in Histogram
// https://leetcode.com/problems/largest-rectangle-in-histogram/
// Brute Force Approach

#include<iostream>
#include<vector>
#include<stack>

using namespace std; 

vector<int> getRightSmall(vector<int> &heights){
	int hSize = heights.size(); 
	vector<int> rightSmall(hSize); 
	stack<int> stk; 
	for(int i=hSize - 1;i >= 0;--i){
		if(stk.empty())
			rightSmall[i] = hSize - 1; 
		else{
			if(heights[i] > heights[stk.top()])
				rightSmall[i] = stk.top() - 1; 
			else{
				while((!stk.empty()) && (heights[i] <= heights[stk.top()])) 
					stk.pop(); 
				if(stk.empty())
					rightSmall[i] = hSize - 1; 
				else
					rightSmall[i] = stk.top() - 1; 
			}
		}
		stk.push(i);
	}	 
	
	return rightSmall;
}

vector<int> getLeftSmall(vector<int> &heights){
	int hSize = heights.size(); 
	vector<int> leftSmall(hSize); 
	stack<int> stk; 
	for(int i=0;i<hSize;++i){
		if(stk.empty())
			leftSmall[i] = 0; 
		else{
			if(heights[i] > heights[stk.top()])
				leftSmall[i] = stk.top() + 1; 
			else{
				while((!stk.empty()) && (heights[i] <= heights[stk.top()])) 
					stk.pop(); 
				if(stk.empty())
					leftSmall[i] = 0; 
				else
					leftSmall[i] = stk.top() + 1; 
			}
		}
		stk.push(i);
	}	 
	
	return leftSmall;
}

int largestRectangleArea(vector<int>& heights) {
	int maxArea = INT_MIN; 
	 
	vector<int> leftSmall = getLeftSmall(heights);
	vector<int> rightSmall = getRightSmall(heights);

	// for(int element:leftSmall)
	// 	cout<<element<<" ";
	// cout<<endl; 
	
	// for(int element:rightSmall)
	// 	cout<<element<<" ";
	// cout<<endl; 

	for (int i = 0; i < heights.size(); ++i)
	{
		int area = (rightSmall[i] - leftSmall[i] + 1) * heights[i]; 
		if(area > maxArea) maxArea = area; 
	}
	return maxArea; 
}

int main(){
	vector<int> arr{2,1,5,6,2,3};
	
	cout<<largestRectangleArea(arr)<<endl; 

	return 0; 
}

//1365. How Many Numbers Are Smaller Than the Current Number
//LeetCode
//https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/

//Constraints
//2 <= nums.length <= 500
//0 <= nums[i] <= 100

#include<iostream>
#include<vector>

using namespace std;

vector<int> smallerNumbersThanCurrent_NAIVE(vector<int> nums){
	vector<int> result;
	int nums_size = nums.size();
	for(int i=0;i<nums_size;i++){
		int count = 0;
		for(int j=0;j<nums_size;j++)
			if((j != i) && (nums[j] < nums[i]))
				count++;
		result.push_back(count);
	}
	
	return result;
}

vector<int> smallerNumbersThanCurrent_EFFICIENT(vector<int> nums){
	vector<int> count(101); //0 to 100;
	for(int element:nums)
		count[element]++;
	
	int sum = 0;
	for(int i=0;i<count.size();i++){
		sum += count[i];
		count[i] = sum - count[i];
	}
		
	vector<int> result;
	for(int element:nums)
		result.push_back(count[element]);
	
	return result; 
}

int main(){
	vector<int> nums{8,1,2,2,3};
	
	vector<int> res1 = smallerNumbersThanCurrent_NAIVE(nums);
	for(int element:res1)
		cout<<element<<" ";
	cout<<endl;
	
	vector<int> res2 = smallerNumbersThanCurrent_EFFICIENT(nums);
	for(int element:res2)
		cout<<element<<" ";
	cout<<endl;
	
	return 0;
}

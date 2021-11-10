# 977 Squares of a Sorted Array
### <a href = 'https://leetcode.com/problems/squares-of-a-sorted-array/'>Link to LeetCode</a>

Given an integer array nums sorted in **non-decreasing order**, <br>return an array of **the squares of each number** sorted in non-decreasing order.

## Example 1:
**Input**: ```nums = [-4,-1,0,3,10]```<br>
**Output**: ```[0,1,9,16,100]```<br>
**Explanation**: After squaring, the array becomes ```[16,1,0,9,100]```.
After sorting, it becomes ```[0,1,9,16,100]```.<br>

## Example 2:
**Input**: ```nums = [-7,-3,2,3,11]```<br>
**Output**: ```[4,9,9,49,121]```<br>

## Constraints
* 1 <= nums.length <= 10⁴
* -10⁴ <= nums[i] <= 10⁴

## Naive Solution
Square Every number and sort them.<br>
```
vector<int> sortedSquares(vector<int>& nums) {
	for(int &num:nums)
		num *= num; 
	        
	sort(nums.begin(), nums.end()); 
	        
	return nums;
}
```
**Time Complexity**: ```O(nlogn)```

## Efficient Approach
Using 2 Pointers. <br>
The resultant array elements are sqaures of input array elements.<br>
So, Minus sign doesn't make any difference.<br>
But the input array is in non-decreasing order.<br>
So max sqaured value might be the sqaure of largest positive element or the sqaure of least negative element.<br>
Largest positive element will be on the right side of the input array. <br>
Least negative number will be on the left side of the input array. <br>
<br>
<img src='https://github.com/JAIDHEER007/Random-Programs/blob/main/LC_977.gif' alt='Dry run with example 2'>
<br>
```
vector<int> sortedSquares(vector<int>& nums) {
	vector<int> result(nums.size()); 
	        
	int i = 0; 
	int j = nums.size() - 1; 
	int k = nums.size() - 1; 
	        
	while(k >= 0){
		if(abs(nums[i]) > abs(nums[j])){
			result[k] = (nums[i] * nums[i]); 
		    ++i;
		}else{
			result[k] = (nums[j] * nums[j]); 
		    --j; 
		}
		--k;
	}
	return result; 
}
```





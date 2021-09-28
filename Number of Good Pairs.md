# 1512. Number of Good Pairs
#### <a href=https://leetcode.com/problems/number-of-good-pairs/>Link to LeetCode</a>
---
Given an array of integers nums, return the number of good pairs.

A pair ```(i, j)``` is called <em>good</em> if ```nums[i] == nums[j]``` and ```i < j```.

## Example 1
```
Input: nums = [1,2,3,1,1,3]
Output: 4
Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
```

## Example 2
```
Input: nums = [1,1,1,1]
Output: 6
Explanation: Each pair in the array are good.
```

## Example 3
```
Input: nums = [1,2,3]
Output: 0
```

## Constraints
* ```1 <= nums.length <= 100```
* ```1 <= nums[i] <= 100```
---
## Solution using Map
```
int numIdenticalPairs(vector<int>& nums) {
    int count = 0;
    map<int, int> table; 
        
    for(int element:nums){
        if(table[element] == 0) table[element] = -1;
        else{
            if(table[element] == -1) table[element] = 1;
            else ++table[element]; 
            count += table[element]; 
        }
    }
    return count; 
}
```

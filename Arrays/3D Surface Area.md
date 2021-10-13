# 3D Surface Area

### <a href="https://www.hackerrank.com/challenges/3d-surface-area/problem">Link to HackerRank</a>
### <a href="https://leetcode.com/problems/surface-area-of-3d-shapes/">Link to similar question in LeetCode</a>
---
We will be given a `n x m` matrix representing the heights of 'pillars'.<br>
The width and breadth of each pillar is 1<br>
We should find the **total surface area** of the structure that is formed.

## Example 1
**Input:**
```
3 3
1 3 4
2 2 3
1 2 4
```
**Output:** `60`<br>
**Structure:**<br>
<img src="https://s3.amazonaws.com/hr-assets/0/1509009918-091bdd4cba-1502631298-5cd3275ce9-img2.png" alt="Structure that is formed with above input">

## Solution
* **Top and Bottom Area:**<br>
  The Top and Bottom area will be same as `n * m` if height of each pillar is non zero.<br><br>
  <img src="https://github.com/JAIDHEER007/Random-Programs/blob/main/3D%20Surface%20Area.gif" alt="Top and Bottom of Structure">
* **Lateral Surface Area:**<br>
  After finding the top and bottom surface area, we can find the lateral surface area.<br>
  For finding the lateral surface area, we have to find the height differene between two adjacent pillars.<br>
  For Example let height of **pillar1** be `h1` and **pillar2** be `h2`. <br>
  Let `d` be the differene of `h1` and `h2`. Therefore `d = h1 - h2`.<br><br>
  
  Now based on value of `d`:
  * if `d` is **negative**. **pillar1** is shorter than **pillar2**. In this is case there is no surface area added to **pillar1**.<br>
  * if `d` is **positive**. **pillar1** is taller than **pillar2**. In this is case there is surface area added to **pillar1**.<br>
    * That Surface Area will be equal to `d`. As the width of the pillars is `1`.
  * if `d` is **zero**. **pillar1** is same as **pillar2**. In this is case there is no surface area added to **pillar1**.<br>
  * These exact conditions will be reversed in perspective of **pillar2**.<br>
  
  We have to find the height difference of adjacent pillars and for all the pillars.<br>
  
  ## Method 1
  In this method we will find the adjacent differene in a flow without checking back.<br><br>
  <img src="https://github.com/JAIDHEER007/Random-Programs/blob/main/3D_1.png"><br>
  But by simply performing this operation on bare array we will miss many borders and can cause **<a href="https://stackoverflow.com/questions/12978234/catch-segmentation-fault-in-c?rq=1">segmentation fault</a>** and it is bad thing to happen.<br>
  
  But we can overcome this problem by padding the array with zeroes. This will eliminate the problem and will give the same output. 
  ```
  0 0 0 0 0
  0 1 3 4 0
  0 2 2 3 0 
  0 1 2 4 0
  0 0 0 0 0
  ```
  ## Code with Zero Padding
  
  ```
  int surfaceArea(vector<vector<int>> heights){
    int rows = heights.size(); 
    int cols = heights[0].size(); 
    int area = 2 * (rows * cols); 


    for(vector<int>& row:heights){
        row.insert(row.begin(), 0); 
        row.insert(row.end(), 0); 
    }

    heights.insert(heights.begin(), vector<int>(heights[0].size(), 0));
    heights.insert(heights.end(), vector<int>(heights[0].size(), 0));

    for(int i = 0; i < heights.size() - 1; ++i){
        for(int j = 0; j < heights[0].size() - 1; ++j){
            area += abs(heights[i][j] - heights[i][j+1]);
            area += abs(heights[i][j] - heights[i+1][j]); 
        }
    }

    return area; 
  }
  ```

* But this method uses extra space and we are modifying the input array

## Method 2:
* In this method we will use `isValid()` function which tells wether a given coordinate lies within the input array.<br>
* Similar to the previous method, we will find the difference. But we will find the differene of all eight neighbours. <br>
* If the height difference is negative, we will not add that thing to result. But that will be covered when we dow the same operation for next pillar.<br>
* If `isValid()` function returns false, then it is boundary consition and we will add the corresponding pillar height to result.<br>

## Code without Zero Padding
```
bool inline isValid(int i, int j, int rows, int cols){
    return (i >= 0) && (i < rows) && (j >= 0) && (j < cols); 
}
```
```
int surfaceArea(vector<vector<int>>& heights){
    int rows = heights.size(); 
    int cols = heights[0].size(); 

    int area = 2 * rows * cols; 

    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; ++j){
            // Left
            if(isValid((i - 1), j, rows, cols)) area += max(0, (heights[i][j] - heights[i - 1][j]));
            else area += heights[i][j];

            // Right
            if(isValid((i + 1), j, rows, cols)) area += max(0, (heights[i][j] - heights[i + 1][j]));
            else area += heights[i][j];

            // Up
            if(isValid(i, (j - 1), rows, cols)) area += max(0, (heights[i][j] - heights[i][j - 1]));
            else area += heights[i][j];

            // Down
            if(isValid(i, (j + 1), rows, cols)) area += max(0, (heights[i][j] - heights[i][j + 1]));
            else area += heights[i][j];

        }
    }
    return area; 
}
```
  


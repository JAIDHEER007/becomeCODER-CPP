# 89. Gray Code

### <a href=https://leetcode.com/problems/gray-code/>Link to  LeetCode</a>
---
An **n-bit gray code sequence** is a sequence of `2n` integers where:

*   Every integer is in the **inclusive** range `[0, 2n - 1]`,
*   The first integer is `0`,
*   An integer appears **no more than once** in the sequence,
*   The binary representation of every pair of **adjacent** integers differs by **exactly one bit**, and
*   The binary representation of the **first** and **last** integers differs by **exactly one bit**.

Given an integer `n`, return _any valid **n-bit gray code sequence**_.

## **Example 1:**

**Input:** n = 2<br>
**Output:** [0,1,3,2]<br>
**Explanation:**<br>
The binary representation of \[0,1,3,2\] is \[00,01,11,10\].
- 00 and 01 differ by one bit
- 01 and 11 differ by one bit
- 11 and 10 differ by one bit
- 10 and 00 differ by one bit
\[0,2,3,1\] is also a valid gray code sequence, whose binary representation is \[00,10,11,01\].
- 00 and 10 differ by one bit
- 10 and 11 differ by one bit
- 11 and 01 differ by one bit
- 01 and 00 differ by one bit

## **Example 2:**

**Input:** n = 1<br>
**Output:** \[0,1\]

## **Constraints:**

*   `1 <= n <= 16`
## Solution

## Generating Gray Code. Method 1
<img src="https://github.com/JAIDHEER007/Random-Programs/blob/main/GrayCodeGen.gif" alt="gray code generation gif">

Here we have to set the nth bit
```
void inline setKthBit(int &num, int position){
    num |= (1 << position); 
}
```
Code to perform copy, inverse, setting the nth bit.
```
vector<int> generateGrayCode(int bits){
    vector<int> grayCode{0, 1};

    if(bits == 1) return grayCode; 

    for(int i = 1; i < bits; i++){
        vector<int> temp(grayCode); 
        for(int &element:temp)
            setKthBit(element, i); 
        grayCode.insert(grayCode.end(), temp.rbegin(), temp.rend());
    } 
    return grayCode; 
}
```
## Generating Gray Code. Method 2
<a href="https://www.electrical4u.com/binary-to-gray-code-converter-and-grey-to-binary-code-converter/">Refer This Link</a>
```
vector<int> grayCode(int n) {
    vector<int> gcv; 
    for(int i = 0; i < (1 << n); ++i)
        gcv.push_back(i ^ (i >> 1));
    return gcv; 
}
```

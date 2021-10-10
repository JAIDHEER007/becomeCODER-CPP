# 201. Bitwise AND of Numbers Range

### <a href=https://leetcode.com/problems/bitwise-and-of-numbers-range/>Link to LeetCode</a>
---
Given two integers `left` and `right` that represent the range `[left, right]`,<br> 
return _the bitwise AND of all numbers in this range, inclusive_.

### **Example 1:**
```
Input: left = 5, right = 7
Output: 4
```

### **Example 2:**
```
Input: left = 0, right = 0
Output: 0
```

### **Example 3:**
```
Input: left = 1, right = 2147483647
Output: 0
```
### **Constraints:**

* ```0 <= left <= right <= 2³¹ - 1```


## Solutions

### Brute Force Method
In Brute Force Method we will iteratre from `right` to `left` and store the result. <br>
Iterating from `left` to `right` is not adviced as we should increment `left` which can cause **overflow**.
```
int rangeBitwiseAnd(int left, int right) {
    int result = right; 
    for(;left <= right; (result &= right, --right));
    return result; 
}
```

But this method will cause TLE for input like ```left = 0``` and ```right = 2147483647```.

---
### Efficient Solution 1
In this method we will check if a 2 power exists within `left` and `right`. <br>
If Yes, then we will return `0`. <br>
else, we will use the above brute force method to find the result. <br>

```
5  --> 0 1 0 1
6  --> 0 1 1 0
7  --> 0 1 1 1
8  --> 1 0 0 0
9  --> 1 0 0 1
10 --> 1 0 1 0
```
Due to presence of `8`. The AND Product of all the numbers preceding `8` will become `0`.<br>
Now, due to presence of `0` the remaining AND product will become `0`.<br>

<a href=https://github.com/JAIDHEER007/becomeCODER-CPP/blob/main/Bit%20Magic/power2_next_before.cpp>Program to Find next and before 2 power for a given number</a><br>
```
int countBits(int number){
    int bits = 0;
    while(number){
        ++bits; 
        number >>= 1;
    }
    return bits; 
}

long next2power(int number){
    return pow(2, countBits(number)); 
}
int rangeBitwiseAnd(int left, int right){
    long power2 = next2power(left);
    if(power2 <= right) return 0; 
    
    int result = right; 
    for(;left <= right; (result &= right, --right));
    return result; 
}
```
**Beware of Integer Overflow** 
* Runtime: 12 ms
* Memory Usage: 5.9 MB
---
### Efficient Solution 2
**<a href=https://youtu.be/-qrpJykY2gE>Excellent Explanation by TECH DOSE</a>**
```
int rangeBitwiseAnd(int left, int right) {
    int step = 0;
    while(left != right){
        left >>= 1; 
        right >>= 1; 
        ++step;
    }
    return left << step; 
}
```
* Runtime: 8 ms
* Memory Usage: 5.7 MB



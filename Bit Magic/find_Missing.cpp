//Given an array from 1 to n
//No Repetetions
//But One Element is missing
//Find the missing element

#include<iostream>
#include<vector>

using namespace std;

int XOR_1_to_n(int n){
	switch(n % 4){
		case 0: return n;
		case 1: return 1;
		case 2: return (n+1);
		case 3: return 0;
	}
}

int findMissing(vector<int> &arr){
	int xor_arr = 0;
	for(int element:arr)
		xor_arr ^= element;
	return (xor_arr ^ XOR_1_to_n(arr.size()+1));
}

int main(){
	vector<int> arr1{ 4, 2, 3, 1 };
	cout<<findMissing(arr1)<<endl;
	
	vector<int> arr2{ 8, 21, 31, 28, 30, 
			  4, 15, 11, 26, 20, 
			  24, 29, 27, 25, 6,
			  7, 9, 1, 3, 13, 2, 
			  23, 32, 10, 22, 18, 
			  5, 16, 14, 17, 12  };
					  
	cout<<findMissing(arr2)<<endl;
	
	
	vector<int> arr3{ 37, 4, 84, 60, 61, 22, 85, 87, 50, 69, 
			  62, 66, 14, 44, 98, 97, 3, 56, 78, 17, 
			  2, 30, 1, 80, 43, 48, 63, 20, 23, 26, 
			  8, 49, 46, 25, 47, 27, 67, 94, 64, 10, 
			  54, 88, 11, 9, 74, 29, 79, 19, 96, 59, 
			  12, 73, 57, 72, 52, 7, 51, 92, 41, 34, 
			  15, 18, 42, 89, 99, 6, 65, 13, 82, 71, 
			  5, 86, 36, 75, 91, 32, 33, 45, 70, 93, 
			  39, 21, 95, 40, 77, 90, 55, 83, 58, 28, 
			  76, 53, 100, 38, 31, 81, 35, 68, 16     };
					  
	cout<<findMissing(arr3)<<endl;	
	
	return 0;
}

/*
Idea:

>>> num ^ 0 = num
>>> num ^ num = 0

Let given array be [1,2,3,5,6,7]
Here n is 7 and missing number is 4

Now Find XOR of 1 to n and strore them in 'a'
Also Find the Xor of Given array and store them in 'b'

So,
 a = 1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 ^ 7
 b = 1 ^ 2 ^ 3 ^ 5 ^ 6 ^ 7
 
 Now the missing number will be (a ^ b)
 
 a ^ b will be, 1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 ^ 7 ^ 1 ^ 2 ^ 3 ^ 5 ^ 6 ^ 7
 
 This can be rearranged to 4 ^ (1 ^ 1) ^ (2 ^ 2) ^ (3 ^ 3) ^ (5 ^ 5) ^ (6 ^ 6) ^ (7 ^ 7)
 
 All the repaeating elements will become zero
 
 So it will become 4 ^ 0 ^ 0 ^ 0 ^ 0 ^ 0 ^ 0
 
 The final result will be 4
  
*/


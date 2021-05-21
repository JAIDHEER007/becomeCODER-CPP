//XOR form 1 to n

#include<iostream>
using namespace std;

string center(int width,string text){
	int len = text.length();
	if(width < len){ return text; }
	int diff = width - len; 
	int padding1 = diff/2;
	int padding2 = diff - padding1; 
	return string(padding1,' ') + text + string(padding2,' ');
}

//Naive Implementation
int XOR_Loop(int n){
	int result = 0;
	for(int i=1;i<=n;i++)
		result ^= i;
	return result;
}

//Main Focus
//Efficient Implementation
int XOR_No_Loop(int n){
	switch(n % 4){
		case 0: return n;
		case 1: return 1;
		case 2: return (n+1);
		case 3: return 0;
	}
}

//Driver Code
int main(){
	
	int n = 32;
	cout<<string(44,'-')<<endl;
	cout<<"|"<<center(42,"XOR of 1 to "+to_string(n))<<"|"<<endl;
	cout<<string(44,'-')<<endl;
	cout<<"|"<<center(20,"XOR using Loop")<<"||"<<center(20,"XOR without Loop")<<"|"<<endl;
	cout<<string(44,'-')<<endl;
	for(int i=1;i<=32;i++)
		cout<<"|"<<center(20,to_string(XOR_Loop(i)))<<"||"<<center(20,to_string(XOR_Loop(i)))<<"|"<<endl;
	cout<<string(44,'-')<<endl;
	
	return 0;
}

/*
Output:
--------------------------------------------
|              XOR of 1 to 32              |
--------------------------------------------
|   XOR using Loop   ||  XOR without Loop  |
--------------------------------------------
|         1          ||         1          |
|         3          ||         3          |
|         0          ||         0          |
|         4          ||         4          |
|         1          ||         1          |
|         7          ||         7          |
|         0          ||         0          |
|         8          ||         8          |
|         1          ||         1          |
|         11         ||         11         |
|         0          ||         0          |
|         12         ||         12         |
|         1          ||         1          |
|         15         ||         15         |
|         0          ||         0          |
|         16         ||         16         |
|         1          ||         1          |
|         19         ||         19         |
|         0          ||         0          |
|         20         ||         20         |
|         1          ||         1          |
|         23         ||         23         |
|         0          ||         0          |
|         24         ||         24         |
|         1          ||         1          |
|         27         ||         27         |
|         0          ||         0          |
|         28         ||         28         |
|         1          ||         1          |
|         31         ||         31         |
|         0          ||         0          |
|         32         ||         32         |
--------------------------------------------
*/

/*
Idea:
--------------------------------------------------------------------------------
1 									-----> 1
1 ^ 2 									-----> 3 
1 ^ 2 ^ 3 								-----> 0
1 ^ 2 ^ 3 ^ 4 								-----> 4
--------------------------------------------------------------------------------
1 ^ 2 ^ 3 ^ 4 ^ 5 							-----> 1
1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 							-----> 7
1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 ^ 7 						-----> 0 
1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 ^ 7 ^ 8 						-----> 8
--------------------------------------------------------------------------------
1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 ^ 7 ^ 8 ^ 9 					-----> 1
1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 ^ 7 ^ 8 ^ 9 ^ 10 					-----> 11
1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 ^ 7 ^ 8 ^ 9 ^ 10 ^ 11 				-----> 0
1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 ^ 7 ^ 8 ^ 9 ^ 10 ^ 11 ^ 12 			-----> 12
--------------------------------------------------------------------------------
1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 ^ 7 ^ 8 ^ 9 ^ 10 ^ 11 ^ 12 ^ 13 			-----> 1
1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 ^ 7 ^ 8 ^ 9 ^ 10 ^ 11 ^ 12 ^ 13 ^ 14 		-----> 15
1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 ^ 7 ^ 8 ^ 9 ^ 10 ^ 11 ^ 12 ^ 13 ^ 14 ^ 15  	-----> 0
1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 ^ 7 ^ 8 ^ 9 ^ 10 ^ 11 ^ 12 ^ 13 ^ 14 ^ 15 ^ 16    -----> 16
--------------------------------------------------------------------------------

If you closely observe we can come up with a sequence
Figure it out

*/

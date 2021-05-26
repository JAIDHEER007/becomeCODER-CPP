//Removing the repeating characters and return the unique string
//out-of-place. Using Stack DS

#include<iostream>
#include<stack>
//#include <chrono>
using namespace std;

string removeRepeating(string text){
	stack<char> stk;
	
	for(char ch:text){
		if((!stk.empty()) && (ch == stk.top()))
			continue; 
		stk.push(ch);	
	}
	
	string result = "";
	while(!stk.empty()){
		result = stk.top() + result;
		stk.pop();
	}
	
	return result;
}

int main(){
	cout<<removeRepeating("jaidheer")<<endl;
	cout<<removeRepeating("aaa")<<endl;
	cout<<removeRepeating("aaaa")<<endl;
	cout<<removeRepeating("QWERTY")<<endl;
	cout<<removeRepeating("AABBA")<<endl;

//Time Testing
//test string length is 500	
/*
	auto start = chrono::high_resolution_clock::now();
	string test = "ldacwlgjoxxneprtfwsyinxfxaymptcpherarjqjtlnqesbepgqlbmyfbxjetflovvhlxqaqxipjhsqioilnloedlmgbfowfbfgydqjtzxpwgrnvamzpaqoywpxysvxodeagaraovptthijilulyodxskodfxqhpprywwqnjqzqwxrlwpinfjrywarqyeltqaymoohzwwecqtqiopaxqlqxexolusoaxpjtmxawrnsvcosyaieaqyseizhlnjjeoqfqqqwckboqyojqujoqqloljhqwlqcwxyghcqllhsbyoqajeixqwogqsfavtyoqkecvgqdrmslxqwriaqeiepkypkpreqbqprwoengaqvebkqpkxrqqadaavxoxaxwtknussnsqhnrsxxhqjdfmdolyqeqhglywarawytaqrropfrgxrekoseyapnjrboulpsjohqryipxwwopgoyemwroaoojsrttogafpmxfecsokgqiyhcono";
	cout<<removeRepeating(test)<<endl;
	auto end = chrono::high_resolution_clock::now();
	
	auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
	cout<<endl<<duration.count()<<" ms"<<endl;
	
	Time Taken: 3384 ms
*/	

	return 0;
}

/*
Working:

This is an out-of-place algorithm to remove adjacent repeating characters 
using stack DS initialized to accept characters

1. Traverse the string from left to right. Let the string be AABBA

2. initally stack is empty

|	|
|	|
---------

3. As stack is empty, push the traversed character into the stack
   Here push 'A' into the stack
   
|	|
---------		So top of the stack is 'A'
|   A	|
---------
   
4. Now check the traversed charcters with the top of stack 
	
	if taversed character is same as the top of the stack 
		pop the stack and push the traversed character
		
Traversed character = 'A'
Top of the stack = 'A'

pop the stack and push 'A'

|	|
---------		So top of the stack is 'A'
|   A	|
---------

But by close observation, poping and pushing the same character are inverse operations
So, if taversed character is same as the top of the stack simply skip the loop using continue 

5. Now check the traversed charcters with the top of stack
	
	if the traversed character is different from top of the stack simply push it to the stack
	
Traversed character = 'B'
Top of the stack = 'A'

push 'B' to the stack

|	|
---------
|   B	|
---------
|   A	|
---------

6. Taversed character is 'B' where as stack top is 'B'. So, skip the loop

|	|
---------
|   B	|
---------
|   A	|
---------

7. Taversed character is 'A' where as stack top is 'B'. So, push 'A' to stack

|	|
---------
|   A	|
---------
|   B	|
---------
|   A	|
---------

Now the required result is the string formed by traversing the stack from bottom to top

*/

/*
OUTPUT:
jaidher
a
a
QWERTY
ABA
*/


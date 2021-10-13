# 150. Evaluate Reverse Polish Notation
### <a href="https://leetcode.com/problems/evaluate-reverse-polish-notation/">Link to LeetCode</a>
---
Evaluate the value of an arithmetic expression in [Reverse Polish Notation](http://en.wikipedia.org/wiki/Reverse_Polish_notation).

Valid operators are `+`, `-`, `*`, and `/`. Each operand may be an integer or another expression.

**Note** that division between two integers should truncate toward zero.

It is guaranteed that the given RPN expression is always valid.<br>
That means the expression would always evaluate to a result, and there will not be any division by zero operation.

## **Example 1:**

**Input:** tokens = \["2","1","+","3","\*"\]<br>
**Output:** 9<br>
**Explanation:** ((2 + 1) \* 3) = 9<br>

## **Example 2:**

**Input:** tokens = \["4","13","5","/","+"\]<br>
**Output:** 6<br>
**Explanation:** (4 + (13 / 5)) = 6<br>

## **Example 3:**

**Input:** tokens = \["10","6","9","3","+","-11","\*","/","\*","17","+","5","+"\]<br>
**Output:** 22<br>
**Explanation:** <br>
((10 \* (6 / ((9 + 3) \* -11))) + 17) + 5 <br>
= ((10 \* (6 / (12 \* -11))) + 17) + 5<br>
= ((10 \* (6 / -132)) + 17) + 5<br>
= ((10 \* 0) + 17) + 5<br>
= (0 + 17) + 5<br>
= 17 + 5<br>
= 22<br>

## **Constraints:**

*   `1 <= tokens.length <= 104`
*   `tokens[i]` is either an operator: `"+"`, `"-"`, `"*"`, or `"/"`, or an integer in the range `[-200, 200]`.

## Solution

Reverse Polish Notation or Postfix Notation can be evaluted by using a **Stack**.<br>
In a postifx notation, an operator is preceded by two operands. 

1. Take an empty Stack.
2. Scan the tokens from left to right.
3. If a token is an operand. Push it to Stack.
4. If a token is an operator. Pop the stack two times to get the 2 operands.
5. Perform the required operation and push the result to stack again 
6. After parsing the entire tokens, the stack top will be the required result. 

```
bool isOperator(char ch){
    return (ch == '+') || (ch == '-') || (ch == '*') || (ch == '/'); 
}

int evalRPN(vector<string>& tokens){
    stack<int> stk; 
    for(string token:tokens){
        if((isOperator(token[0])) && (token.length() == 1)){
            int operand2 = stk.top(); 
            stk.pop(); 

            int operand1 = stk.top(); 
            stk.pop();

            int result = 0; 
            switch(token[0]){
                case '+': result = (operand1 + operand2); break; 
                case '-': result = (operand1 - operand2); break;
                case '*': result = (operand1 * operand2); break;
                case '/': result = (operand1 / operand2); break;
            } 
            stk.push(result); 
        }else{
            bool isNegative = false;  
            if(token[0] == '-'){
                isNegative = true; 
                token.erase(token.begin()); 
            }
            int value = 0;
            for(char digit:token)
                value = (value * 10) + (digit - '0'); 
            stk.push((isNegative)?(-1 * value):(value)); 
        }
    }
    return stk.top(); 
}
```
* using `stoi()` function to evaluate the operands
```
bool isOperator(char ch){
    return (ch == '+') || (ch == '-') || (ch == '*') || (ch == '/'); 
}

int evalRPN(vector<string>& tokens){
    stack<int> stk; 
    for(string token:tokens){
        if((isOperator(token[0])) && (token.length() == 1)){
            int operand2 = stk.top(); 
            stk.pop(); 

            int operand1 = stk.top(); 
            stk.pop();

            int result = 0; 
            switch(token[0]){
                case '+': result = (operand1 + operand2); break; 
                case '-': result = (operand1 - operand2); break;
                case '*': result = (operand1 * operand2); break;
                case '/': result = (operand1 / operand2); break;
            } 
            stk.push(result); 
        }else
            stk.push(stoi(token)); 
    }
    return stk.top(); 
}
```
## Reference Links
* <a href="https://en.wikipedia.org/wiki/Reverse_Polish_notation">Reverse Polish Notation Wikipedia</a>
* <a href="https://www.cplusplus.com/reference/string/stoi/">stoi()</a>

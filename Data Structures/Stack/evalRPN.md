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

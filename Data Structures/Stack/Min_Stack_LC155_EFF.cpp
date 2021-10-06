// Leet Code Question 155 
//  Min Stack
//  https://leetcode.com/problems/min-stack/
// Efficient

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

class MinStack{
    public:
        stack<int> stk;     // Normal Stack to maintain the elements
        stack<int> minStk;  // Stack to maintain the min elements

        void push(int val){
            stk.push(val); 
            if(minStk.empty()) minStk.push(val);
            else minStk.push(min(val, minStk.top())); 
        }

        void pop(){
            stk.pop(); 
            minStk.pop(); 
        }
        int top(){
            return stk.top(); 
        }

        int getMin(){
            return minStk.top(); 
        }

        void printStk(){
            vector<int> temp;
            while(!stk.empty()){
                cout<<(stk.top())<<" -> ";
                temp.push_back(stk.top());
                stk.pop(); 
            }cout<<"END"<<endl;

            for(auto itr = temp.rbegin(); itr!=temp.rend(); ++itr)
                stk.push(*itr); 
        }

        void printMinStk(){
            vector<int> temp;
            while(!minStk.empty()){
                cout<<(minStk.top())<<" -> ";
                temp.push_back(minStk.top());
                minStk.pop(); 
            }cout<<"END"<<endl;

            for(auto itr = temp.rbegin(); itr!=temp.rend(); ++itr)
                minStk.push(*itr); 
        }
};

int main(){
    MinStack ms1; 

    ms1.push(-2);
    ms1.push(0);
    ms1.push(-3);

    cout<<ms1.getMin()<<endl; 

    ms1.pop();

    cout<<ms1.top()<<endl; 

    cout<<ms1.getMin()<<endl;  

    // ms1.push(2);
    // ms1.push(0);
    // ms1.push(3);
    // ms1.push(0);

    // ms1.printStk(); 
    // ms1.printMinStk(); 

    // cout<<ms1.getMin()<<endl;

    // ms1.pop(); 

    // cout<<ms1.getMin()<<endl;

    // ms1.pop();

    // cout<<ms1.getMin()<<endl;

    // ms1.pop();

    // cout<<ms1.getMin()<<endl;

    return 0; 
}
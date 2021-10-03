#include<iostream>
#include<vector>

using namespace std; 

int inline ctoi(char ch){
	return ch - '0'; 
}

int entryTime(string keypad, string code){
	vector<vector<int>> timeArr(10); 
	int i = 0, j = 0;
	
	for(char key:keypad){
		vector<int> coordinates{i ,j++};
		timeArr[ctoi(key)] = coordinates;   
		if(j == 3){
			++i;
			j = 0; 
		}
	}
	
	int totalTime = 0;
	
	for(int i=1;i<code.length();++i)
		totalTime += max(abs(timeArr[ctoi(code[i - 1])][0] - timeArr[ctoi(code[i])][0]),
				 abs(timeArr[ctoi(code[i - 1])][1] - timeArr[ctoi(code[i])][1]));
	
	return totalTime; 
}

int main(){
	string keypad = "923857614";
	string code = "423692";
	
	cout<<entryTime(keypad, code)<<endl;
	
	
}

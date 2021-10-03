#include<iostream>
#include<vector>
#include<queue>
#include<map>

using namespace std;

int ctoi(char ch){
	return ch - '0'; 
}

map<int, vector<int>> getAdjList(string keypad){
	map<int, vector<int>> adjList; 
	
	//Corners
	adjList[ctoi(keypad[0])] = {ctoi(keypad[1]), ctoi(keypad[3]), ctoi(keypad[4])};
	adjList[ctoi(keypad[2])] = {ctoi(keypad[1]), ctoi(keypad[5]), ctoi(keypad[4])};
	adjList[ctoi(keypad[6])] = {ctoi(keypad[3]), ctoi(keypad[4]), ctoi(keypad[7])};
	adjList[ctoi(keypad[8])] = {ctoi(keypad[5]), ctoi(keypad[4]), ctoi(keypad[7])};
	
	//Diamond
	adjList[ctoi(keypad[1])] = {ctoi(keypad[0]), ctoi(keypad[2]), 
				    ctoi(keypad[3]), ctoi(keypad[5]), ctoi(keypad[4])};
	adjList[ctoi(keypad[3])] = {ctoi(keypad[0]), ctoi(keypad[6]), 
				    ctoi(keypad[1]), ctoi(keypad[7]), ctoi(keypad[4])};
	adjList[ctoi(keypad[5])] = {ctoi(keypad[2]), ctoi(keypad[8]), 
				    ctoi(keypad[1]), ctoi(keypad[7]), ctoi(keypad[4])};
	adjList[ctoi(keypad[7])] = {ctoi(keypad[6]), ctoi(keypad[8]), 
				    ctoi(keypad[3]), ctoi(keypad[5]), ctoi(keypad[4])};
	
	//Centre
	adjList[ctoi(keypad[4])] = {ctoi(keypad[0]), ctoi(keypad[1]),
				    ctoi(keypad[2]), ctoi(keypad[3]),
				    ctoi(keypad[6]), ctoi(keypad[4]),
				    ctoi(keypad[8]), ctoi(keypad[7]),}; 
	
	return adjList; 
}

int bfs(map<int, vector<int>> &adjList, int start, int end){
	vector<bool> visited(10, false);
	
	queue<pair<int, int>> q; 
	
	q.push({start, 0});
	visited[start] = true; 
	
	while(!q.empty()){
		pair<int, int> curr = q.front();
		q.pop(); 
		
		for(int adjacentNode:adjList[curr.first]){
			if(!visited[adjacentNode]){
				if(adjacentNode == end) return curr.second + 1;
				q.push({adjacentNode, (curr.second + 1)});
				visited[adjacentNode] = true; 
			}
		}
	}
	return -1; 
}

int getMinTime(string keypad, string code){
	map<int, vector<int>> adjList = getAdjList(keypad);
	
	int totalTime; 
	for(int i=1;i<code.length();++i)
		totalTime += bfs(adjList, ctoi(code[i-1]), ctoi(code[i]));
	
	return totalTime; 
}

int main(){
	string keypad = "923857614";
	string code = "423692";
	
	cout<<getMinTime(keypad, code)<<endl;
	
	return 0;  
}

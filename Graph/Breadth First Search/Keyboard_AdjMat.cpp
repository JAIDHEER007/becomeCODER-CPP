#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int ctoi(char ch){
	return ch - '0'; 
}

vector<vector<bool>> getAdjMat(string keypad){
	vector<bool> row(10, false);
	vector<vector<bool>> matrix(10, row);
	
	//Corner Pieces: 0, 2, 6, 8
	
	// 0 -> 1
	// 0 -> 3
	// 0 -> 4
	matrix[ctoi(keypad[0])][ctoi(keypad[1])] = true;
	matrix[ctoi(keypad[0])][ctoi(keypad[3])] = true;
	matrix[ctoi(keypad[0])][ctoi(keypad[4])] = true;
	
	// 2 -> 1
	// 2 -> 5
	// 2 -> 4
	matrix[ctoi(keypad[2])][ctoi(keypad[1])] = true;
	matrix[ctoi(keypad[2])][ctoi(keypad[5])] = true;
	matrix[ctoi(keypad[2])][ctoi(keypad[4])] = true;
	
	// 6 -> 3
	// 6 -> 4
	// 6 -> 7
	matrix[ctoi(keypad[6])][ctoi(keypad[3])] = true;
	matrix[ctoi(keypad[6])][ctoi(keypad[4])] = true;
	matrix[ctoi(keypad[6])][ctoi(keypad[7])] = true;
	
	// 8 -> 5
	// 8 -> 4
	// 8 -> 7
	matrix[ctoi(keypad[8])][ctoi(keypad[5])] = true;
	matrix[ctoi(keypad[8])][ctoi(keypad[4])] = true;
	matrix[ctoi(keypad[8])][ctoi(keypad[7])] = true;
	
	//Diamond Pieces: 1, 3, 5, 7
	
	// 1 -> 0
	// 1 -> 2
	// 1 -> 3
	// 1 -> 5
	// 1 -> 4
	matrix[ctoi(keypad[1])][ctoi(keypad[0])] = true;
	matrix[ctoi(keypad[1])][ctoi(keypad[2])] = true;
	matrix[ctoi(keypad[1])][ctoi(keypad[3])] = true;
	matrix[ctoi(keypad[1])][ctoi(keypad[5])] = true;
	matrix[ctoi(keypad[1])][ctoi(keypad[4])] = true;
	
	// 3 -> 0
	// 3 -> 6
	// 3 -> 1
	// 3 -> 7
	// 3 -> 4
	matrix[ctoi(keypad[3])][ctoi(keypad[0])] = true;
	matrix[ctoi(keypad[3])][ctoi(keypad[6])] = true;
	matrix[ctoi(keypad[3])][ctoi(keypad[1])] = true;
	matrix[ctoi(keypad[3])][ctoi(keypad[7])] = true;
	matrix[ctoi(keypad[3])][ctoi(keypad[4])] = true;
	
	// 5 -> 2
	// 5 -> 8
	// 5 -> 1
	// 5 -> 7
	// 5 -> 4
	matrix[ctoi(keypad[5])][ctoi(keypad[2])] = true;
	matrix[ctoi(keypad[5])][ctoi(keypad[8])] = true;
	matrix[ctoi(keypad[5])][ctoi(keypad[1])] = true;
	matrix[ctoi(keypad[5])][ctoi(keypad[7])] = true;
	matrix[ctoi(keypad[5])][ctoi(keypad[4])] = true;
	
	// 7 -> 6
	// 7 -> 8
	// 7 -> 3
	// 7 -> 5
	// 7 -> 4
	matrix[ctoi(keypad[7])][ctoi(keypad[6])] = true;
	matrix[ctoi(keypad[7])][ctoi(keypad[8])] = true;
	matrix[ctoi(keypad[7])][ctoi(keypad[3])] = true;
	matrix[ctoi(keypad[7])][ctoi(keypad[5])] = true;
	matrix[ctoi(keypad[7])][ctoi(keypad[4])] = true;
	
	//Centre Piece: 4
	//4 -> 0
	//4 -> 2
	//4 -> 6
	//4 -> 8
	
	//4 -> 1
	//4 -> 3
	//4 -> 4
	//4 -> 7
	
	matrix[ctoi(keypad[4])][ctoi(keypad[0])] = true;
	matrix[ctoi(keypad[4])][ctoi(keypad[2])] = true;
	matrix[ctoi(keypad[4])][ctoi(keypad[6])] = true;
	matrix[ctoi(keypad[4])][ctoi(keypad[8])] = true;
	
	matrix[ctoi(keypad[4])][ctoi(keypad[1])] = true;
	matrix[ctoi(keypad[4])][ctoi(keypad[3])] = true;
	matrix[ctoi(keypad[4])][ctoi(keypad[4])] = true;
	matrix[ctoi(keypad[4])][ctoi(keypad[7])] = true;
	
	return matrix; 
}

int bfs(vector<vector<bool>> &adjMat, int start, int end){
	vector<bool> visited(10, false);
	
	queue<pair<int, int>> q; 
	
	q.push({start, 0});
	visited[start] = true; 
	
	while(!q.empty()){
		pair<int, int> curr = q.front();
		q.pop(); 
		
		for(int i=1;i<10;i++){
			if(adjMat[curr.first][i] && (!visited[i])){
				if(i == end) return curr.second + 1; 
				q.push({i, (curr.second + 1)});
				visited[i] = true; 
			}
		}
	}
	return -1; 
}

int getMinTime(string keypad, string code){
	vector<vector<bool>> adjMat = getAdjMat(keypad);
	
	int totalTime; 
	for(int i=1;i<code.length();++i)
		totalTime += bfs(adjMat, ctoi(code[i-1]), ctoi(code[i]));
	
	return totalTime; 
}

int main(){
	string keypad = "923857614";
	string code = "423692";
	
	cout<<getMinTime(keypad, code)<<endl;
	
	return 0;  
}

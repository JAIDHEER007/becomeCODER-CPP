//Closed Paths

#include<iostream>
using namespace std;

int closedPaths(int number){
	int closedPathsArr[] = {1,0,0,0,1,0,1,0,2,1};
	int closedPathSum = 0;
	while(number){
		closedPathSum += closedPathsArr[number % 10];
		number  /= 10;
	}
	return closedPathSum;
}

int main(){
	cout<<closedPaths(649578)<<endl;
	
	return 0;
}

//Question 10
//Suspicious Activity From Logs

#include<bits/stdc++.h>
#define NeedForSpeed ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

vector<string> processLogs(vector<string> logs, int threshold){
	map<int,int> table;
	for(string log:logs){
		vector<string> loginfo(2);
		stringstream ss(log);
		ss>>loginfo[0];
		ss>>loginfo[1];
		if(loginfo[0] == loginfo[1])
			++table[stoi(loginfo[0])];
		else{
			++table[stoi(loginfo[0])];
			++table[stoi(loginfo[1])];
		}
		loginfo.clear();
	}
	vector<string> result;
	for(auto it:table){
		if((it.second)<threshold)
			continue;
		result.push_back(to_string(it.first));
	}
	return result;
}
int main(){
//	NeedForSpeed; 
// 	NeedForSpeed is not activated as it is interfering with string input 
	
	int n; 
	cin>>n;
	fflush(stdin);	//Flushing stdin stream is must to avoid newline false inputs
	
	vector<string> logs;
	for(int i=0;i<n;++i){
		string log; 
		getline(cin,log);
		logs.push_back(log);
	}

	int threshold;
	cin>>threshold;	
	
	vector<string> suspiciousDudes = processLogs(logs,threshold);
	
	for(string suspiciousDude:suspiciousDudes)
		cout<<suspiciousDude<<endl;

	return 0;
}




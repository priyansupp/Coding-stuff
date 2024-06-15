#include<bits/stdc++.h>
using namespace std;

int minimoves(int i, vector<int> &ladderstart, vector<int> &ladderend, vector<int> &snakeS, vector<int> &snakeE, vector<int> &dp){
	if(i > 100){
		return 1e8;
	}

	if(i == 100){
		return 0;
	}

	if(dp[i] != -1) return dp[i];

	for(int j = 0; j < ladderstart.size(); j++){
		if(ladderstart[j] == i) i = ladderend[j];
	}

	for(int j = 0; j < snakeS.size(); j++){
		if(snakeS[j] == i) i = snakeE[j];
	}



	int moves = 1e8;
	for(int role = 1; role <= 6; role++){
		moves = min(moves, 1 + minimoves(i + role, ladderstart, ladderend, snakeS, snakeE, dp));
	}

	return dp[i] = moves;
	
}		
		


void solve(){
	int n, m;
	cin >> n;
	vector<int> ladderstart(n), ladderend(n);
	
	for(int i = 0; i < n; i++){
		cin >> ladderstart[i] >> ladderend[i];
	}
	cin >> m;
	vector<int> snakeS(m), snakeE(m);
	
	for(int i = 0; i < m; i++){
		cin >> snakeS[i] >> snakeE[i];
	}
	vector<int>dp(101, -1);

	cout << minimoves(1, ladderstart, ladderend, snakeS, snakeE, dp) << '\n';

}

int main()
{
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}
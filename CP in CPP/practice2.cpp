#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;

int main() {

	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>a(n, vector<int>(m));
		for(int i = 0 ; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> a[i][j];
			}
		}
		int r = 0, c = 0;
		bool flag = false;
		for(int j = 0; j < m; j++){
			r += a[0][j];
		}
		for(int i = 1; i < n; i++){
			int rr = 0;
			for(int j = 0; j < m; j++){
				rr += a[i][j];
			}
			if(rr != r){
				cout << "NO\n";
				flag = true;
				break;
			}
		}
		for(int i = 0; i < n; i++){
			c += a[i][0];
		}
        if(!flag)
		for(int j = 1; j < m; j++){
			int cc = 0;
			for(int i = 0; i < n; i++){
				cc += a[i][j];
			}
			if(cc != c){
				cout << "NO\n";
				flag = true;
				break;
			}
		}
		if(!flag){
			cout << "YES\n";
		}
	}
	return 0;
}
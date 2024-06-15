//prime numbers between a & b. 2<=a,b<=10^9, b-a<10^6.

#include <bits/stdc++.h>

using namespace std;

vector<int> sieve(int n){
	bool prime[n+1];
	for(int i=0;i<=n;i++) prime[i]=false;
	for(int i=2;i<=sqrt(n);i++){
		if(prime[i]==false){
			for(int j=i*i;j<=n;j+=i){
				prime[j]=true;
			}
		}
	}
	vector<int>res;
	for(int i=2;i<=n;i++){
		if(prime[i]==false){
			res.push_back(i);
		}
	}
	return res;
}

int main() {
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		
		bool isprime[b-a+1];
		for(int i=0;i<=b-a;i++) isprime[i]=false;
		
		vector<int>primes=sieve(sqrt(b));  //fiding all primes upto rootb.
		
		for(int prime:primes){
			cout<<prime<<"**";
			int multiple=ceil((a*1.0)/prime);   // a is converted to double first so that we can find its ceiling.
            int index;
			if(multiple==1) multiple++;
            
			index=multiple*prime-a;
			for(int j=index;j<=b-a;j+=prime) isprime[j]=true;
		}
		for(int i=0;i<=b-a;i++){
			if(isprime[i]==false){
				int val=i+a;
				cout<<val<<endl;
			}
		}
		
	}
	return 0;
}
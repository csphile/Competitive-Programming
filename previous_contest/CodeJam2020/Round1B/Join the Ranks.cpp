#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array



void solve() {
	int r, s;	
	cin >> r >> s;
	cout << ((s-1)*r+1)/2 << "\n";
	vector<int> a;
	for(int i=0; i<s; ++i)
		for(int j=0; j<r; ++j)
			a.push_back(j);
	for(int it=0; it<(s-1)*r/2; ++it) {
		int r1=0;
		while(a[r1]==a[0])
			++r1;
		int r2=r1;
		while(a[r2]==a[r1])
			++r2;
		//a[0], a[r1]
		int r3=r2;
		while(a[r3]!=a[r1])
			++r3;
		cout << r2 << " " << r3-r2 << "\n";
		vector<int> v=vector<int>(a.begin(), a.begin()+r2);
		a.erase(a.begin(), a.begin()+r2);
		a.insert(a.begin()+r3-r2, v.begin(), v.end());
	}
	if((s-1)*r%2==1) {
		int r1=0;
		while(a[r1]==a[0])
			++r1;
		int r2=r1;
		while(a[r2]!=a[0])
			++r2;
		cout << r1 << " " << r2-r1 << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for(int i=1; i<=t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}
}
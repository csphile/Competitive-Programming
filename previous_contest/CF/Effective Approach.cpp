#include <bits/stdc++.h>

#define MP make_pair
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REPR(i, a, b) for (int i = a; i > b; i--)

using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int maN = 1e5 + 1;
int n, m; int arr[maN];
ll ans1, ans2;

void solve(){
	cin >> n;
	REP(i, 1, n + 1){
		int a; cin >> a;
		arr[a] = i;
	}
//	sort(tosort.begin(), tosort.end());
	cin >> m;

	REP(i, 0, m){
		int a; cin >> a;
		ans1 += arr[a];
		ans2 += (n + 1 - arr[a]);
	}
	cout << ans1 << " " <<  ans2;
}

int main()
{
	// int t;
	// cin >> t;
	// REP(t_, 1, t + 1)
	// {
		// cout << "Case #" << t_ << ": ";
		solve();
		cout << endl;
	//}
	return 0;
}

// if file is used:
/*
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
*/
// g++ A.cpp -o temp -Wall && ./temp < input.in
// ios::sync_with_stdio(false);
// cin.tie(0);
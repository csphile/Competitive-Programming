#include <bits/stdc++.h>

#define MP make_pair
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REPR(i, a, b) for (int i = a; i > b; i--)

using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int maN = 1e5 + 1;
int n, cum;
ll ans;

void solve(){
	cin >> n;
	REP(i, 0, n){
		int a; cin >> a;
		cum += a;
	}
	ans = 0;
	REP(i, 1, 6){
		if ((cum + i)%(n + 1) != 1)
			ans += 1;
	}
	cout << ans;
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
// g++ C.cpp -o temp -Wall && ./temp < input.in
// ios::sync_with_stdio(false);
// cin.tie(0);
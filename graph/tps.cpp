#include <bits/stdc++.h>

#define MP make_pair
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REPR(i, a, b) for (int i = a; i > b; i--)

using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const ll maxN = 1e4;
int n, m, act[maxN + 1], vis[maxN + 1];
vector<int> r[maxN + 1];
vector<int> ans;
bool bad;

void dfs(int i){
	if (vis[i])
		return ;
	vis[i] = 1;
	act[i] = 1;
	for (int j : r[i]){
		if (act[j]) bad = true;
		dfs(j);
	}
	act[i] = 0;
	ans.push_back(i);
}

void solve(){
	cin >> n >> m;
	memset(act, 0, sizeof(act));
	memset(vis, 0, sizeof(vis));
	
	REP(i, 0, m){
		int a, b; cin >> a >> b;
		r[a].push_back(b);
	}
	REP(i, 0, n + 1){
		sort(r[i].begin(), r[i].end());
		reverse(r[i].begin(), r[i].end());
	}
	bad = false;
	for (int i = n; i >= 1; i--)
		if (!vis[i])
			dfs(i);
	reverse(ans.begin(), ans.end());
	if (!bad)
		for (int a : ans)
			cout << a << " ";
	else
		cout << "Sandro fails.";
	
}

int main()
{
	ios::sync_with_stdio(false);
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
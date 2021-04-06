
/*
intelligent way to do topological sort and in the same time to dectect a cycle
in graph
*/
#include <bits/stdc++.h>

#define MP make_pair
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REPR(i, a, b) for (int i = a; i > b; i--)

using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

ll R, C;
string wall[31], ans;
vector<int> adj[26];
int v[26], cur[26];
int top_place, N = 26;
bool hascycle;

void dfs(int a){
	v[a] = 1;
	//backtracking
	cur[a] = 1;
	for (auto i: adj[a]){
		if (cur[i])
			hascycle = true;
		if (!v[i]) dfs(i);
	}
	cur[a] = 0;
	ans += char(a + 'A');
}

void solve(){
	set<char> all_c;
	cin >> R >> C;
	REP(i, 0, R) {
		cin >> wall[i];
		for (char c: wall[i])
			all_c.insert(c);
	}
	hascycle = false;
	memset(v, 0, sizeof(v));
	memset(cur, 0, sizeof(cur));
	ans = "";
	for (int i = R - 1; i >= 1; i--)
		REP(j, 0, C)
			if (wall[i][j] != wall[i - 1][j])
				adj[wall[i][j] - 'A'].push_back(wall[i - 1][j] - 'A');
		
	for (char c : all_c){
		if (!v[c - 'A']) 
			dfs(c - 'A');
	}

	reverse(ans.begin(), ans.end());
	if (hascycle)
		cout << "-1";
	else 
		cout << ans;
		
	REP(i, 0, 26)
		adj[i].clear();
}

int main()
{
	int t;
	cin >> t;
	REP(t_, 1, t + 1)
	{
		cout << "Case #" << t_ << ": ";
		solve();
		cout << endl;
	}
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
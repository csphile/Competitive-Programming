#include <bits/stdc++.h>

using namespace std;

const long long maxN = 2e5 + 1;
int n, m, act[maxN + 1], vis[maxN + 1];
vector<int> r[maxN + 1];
vector<int> ans;
bool hascycle;

void dfs(int i){
	if (vis[i])
		return ;
	vis[i] = 1;
	act[i] = 1;
	for (int j : r[i]){
		if (act[j]) hascycle = true;
		dfs(j);
	}
	act[i] = 0;
	ans.push_back(i);
}
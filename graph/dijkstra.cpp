#include <bits/stdc++.h>

#define sz(x) (int)x.size()
#define beg(x) x.begin()
#define end(x) x.end()
#define all(x) beg(x), end(x)

using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using pll = pair<long, long>;

namespace input {
    template<class T> void read(T& x) { cin >> x; }
    template<class T1, class T2> void read(pair<T1,T2>& p){read(p.first), read(p.second);}
    template<class T> void read(vector<T>& a) { for(auto& e : a) read(e); };
}

using namespace input;

namespace output {
    template<class T> void print(const T& x) { cout << x; }
    template<class T1, class T2> void print(const pair<T1,T2>& x) { 
        print(x.first), print(" "), print(x.second);
    }
    template<class T> void print(const vector<T>& x){
        for (auto& e: x) print(e), print(" ");
    }
    template<class T> void print(const set<T>& x){
        for (auto& e: x) print(e), print(" ");
    }
}
 
using namespace output;

// const int MOD = 1e9 + 7;
const int maxN = 2e5 + 1;
int n, m; 

vector<vector<int>> graph, weight;

void dijkstra(vector<vector<int>>& graph, vector<vector<int>>& weight){
    // 1 indexed;
    int n = graph.size();
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>  h;
    h.push({0, 1});
    vector<ll> dist(n + 1, -1);
    vector<int> vis(n + 1, 0);
    dist[1] = 0;
    vis[1] = 0;
    while (sz(h)){
        auto it = h.top();
        ll d = it.first; 
        int cur = it.second;
        h.pop();
        if (vis[cur]) continue;
        vis[cur] = 1; 
        int cnt = 0; 
        for (int nxt: graph[cur]){
            int w = weight[cur][cnt++];
            ll tmp = d + w;
            if (vis[nxt]) continue;
            if (dist[nxt] < 0 || tmp < dist[nxt]) {
                dist[nxt] = tmp;
                h.push({tmp, nxt});
            }
        }
    }
    for (int i = 1; i <= n; i++){
        cout << dist[i] << " "; 
    }
    cout << endl;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); 
	// int t;
	// cin >> t;
	// for (int t_ = 1; t_ < t + 1; t_++)
	{
		// cout << "Case #" << t_ << ": ";
		solve();
		cout << endl;
	}
	return 0;
}

// if file is used:
/*
	*freopen("input.txt", "r", stdin);
	*freopen("output.txt", "w", stdout);
*/

// g++ A.cpp -o temp -Wall && ./temp < input.in
// windows : g++ A.cpp -o temp -Wall && temp

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/
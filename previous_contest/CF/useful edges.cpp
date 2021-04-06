#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define trav(a, x) for (auto& a: x)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// INPUT
template<class A>
void read(complex<A> &c);

template<class A, class B>
void read(pair<A, B> &p);

template<class A>
void read(vector<A> &v);

template<class A, size_t SZ>
void read(array<A, SZ> &a);

template<class T>
void read(T &x) { cin >> x; }

void read(double &d) {
	string t;
	read(t);
	d = stod(t);
}

void read(long double &d) {
	string t;
	read(t);
	d = stold(t);
}

template<class H, class... T>
void read(H &h, T &... t) {
	read(h);
	read(t...);
}

template<class A>
void read(complex<A> &c) {
	A a, b;
	read(a, b);
	c = {a, b};
}

template<class A, class B>
void read(pair<A, B> &p) { read(p.f, p.s); }

template<class A>
void read(vector<A> &x) { trav(a, x) read(a); }

template<class A, size_t SZ>
void read(array<A, SZ> &x) { trav(a, x) read(a); }


// OUTPUT
template<typename A>
void print(vector<A> x) { trav(a, x) cout << a << " "; }

template<class A>
void print(A x) { cout << x; }

template<class H, class... T>
void print(const H &h, const T &... t) {
	print(h);
	print(t...);
}

void prints() { cout << endl; } // print int w/ spaces
template<class H, class... T>
void prints(const H &h, const T &... t) {
	print(h);
	if (sizeof...(t)) print(" ");
	prints(t...);
}
const ll inf = 1e18;
void solve() {
	int n, m; cin >> n >> m;
	vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, inf));
	auto mn1 = dist, mn2 = dist;
	vector<int> x(m), y(m), w(m);
	for (int i = 1; i <= n; i++) dist[i][i] = 0;
	for (int i = 0; i < m; i++) {
		cin >> x[i] >> y[i] >> w[i];
		dist[x[i]][y[i]] = dist[y[i]][x[i]] = w[i];
	}
	for (int k = 1; k <= n; k++){
		for (int i = 0; i <= n; i++){
			for (int j = 0; j <= n; j++){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	int q; cin >> q;
	for (int i = 0; i < q; i++){
		int u, v, l; cin >> u >> v >> l;
		for (int j = 1; j <= n; j++) {
			mn1[u][j] = min(mn1[u][j], dist[j][v] - l);
			mn2[v][j] = min(mn2[v][j], dist[j][u] - l);
		}
	}
	int ans = 0;
	for (int i = 0; i < m; i++){
		for (int u = 1; u <= n; u++){
			if (dist[u][y[i]] + w[i] + mn1[u][x[i]] <= 0 || dist[u][y[i]] + w[i] + mn2[u][x[i]] <= 0) {
				ans++;
				break;
			}
		}
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int ca = 1;
	for (int tt = 1; tt <= ca; tt++) {
		// cout << "Case #" << tt << ": ";
		solve();
	}
	return 0;
}

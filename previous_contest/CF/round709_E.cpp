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
 
struct Tree {
		typedef ll T;
		static constexpr T unit = LONG_LONG_MIN;
 
		T f(T a, T b) { return max(a, b); } // (any associative fn)
		vector<T> s;
		int n;
 
		Tree(int n = 0, T def = unit) : s(2 * n, def), n(n) {}
 
		void update(int pos, T val) {
			for (s[pos += n] = val; pos /= 2;)
				s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
		}
 
		T query(int b, int e) { // query [b, e)
			T ra = unit, rb = unit;
			for (b += n, e += n; b < e; b /= 2, e /= 2) {
				if (b % 2) ra = f(ra, s[b++]);
				if (e % 2) rb = f(s[--e], rb);
			}
			return f(ra, rb);
		}
};
 
void solve() {
	int n; cin >> n; vector<ll> b(n + 1), h(n + 1);
	rep(i, 1, n + 1) cin >> h[i];
	rep(i, 1, n + 1) cin >> b[i];
	vector<int> look(n + 1);
	for (int i = 0; i <= n; i++)
		look[i] = i - 1;
	Tree dp(n + 1);
	dp.update(0, 0);
	vector<int> inc{0};
	for (int i = 1; i <= n; i++){
		while (h[inc.back()] > h[i]){
			inc.pop_back();
		}
		look[i] = inc.back();
		inc.push_back(i);
	}
	for (int i = 1; i <= n; i++){
		int pi = look[i];
		ll tmp = dp.query(pi, i) + b[i];
		if (pi >= 1){
			tmp = max(tmp, dp.query(pi, pi + 1));
		}else{
			tmp = max(tmp, b[i]);
		}
		dp.update(i, tmp);
	}
	cout << dp.query(n, n + 1) << endl;
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int nofcase = 1;
	// cin >> nofcase;
	for (int tt = 1; tt <= nofcase; tt++) {
		// cout << "Case #" << tt << ": ";
		solve();
	}
	return 0;
}
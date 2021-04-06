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

const int maxn = 2e7 + 13;
int mini[maxn], cntp[maxn];

void solve() {
	int c, d, x; cin >> c >> d >> x;
	int ans = 0;
	for (int i = 1; i * i <= x; i++){
		if (x%i != 0) continue;
		int k1 = x / i + d;
		if (k1 % c == 0)
			ans += 1 << cntp[k1 / c];
		if (i * i == x)
			continue;
		int k2 = i + d;
		if (k2%c == 0)
			ans += 1 << cntp[k2 / c];
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int nofcase;
	cin >> nofcase;
	memset(mini, -1, sizeof(mini));
	memset(cntp, 0, sizeof(maxn));
	mini[1] = 1;
	for (int i = 2; i < maxn; i++) {
		if (mini[i] == -1)
			for (int j = i; j < maxn; j += i)
					mini[j] = i;
	}
	for (int i = 2; i < maxn; i++){
		int t = i / mini[i];
		cntp[i] = cntp[t] + (mini[t] != mini[i]);
	}
	for (int tt = 1; tt <= nofcase; tt++) {
		// cout << "Case #" << tt << ": ";
		solve();
	}
	return 0;
}

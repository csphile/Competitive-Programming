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
template<class A> void pr(A x) { cout << x; }
template<class H, class... T> void pr(const H& h, const T&... t) {
	pr(h); cout << " "; pr(t...); }
void ps() { pr("\n"); } // print w/ spaces
template<class H, class... T> void ps(const H& h, const T&... t) {
	pr(h); if (sizeof...(t)) pr(" "); ps(t...); }


ll update(ll a, ll st, ll num){
	return a - (st + num - 1)*num;
}

ll get(ll a, ll st){
	ll lo = 0, hi = 1e9 + 7;
	while (lo < hi){
		ll mid = (lo + hi + 1 ) / 2;
		if (update(a, st, mid) >= 0) lo = mid;
		else hi = mid - 1;
	}
	return lo;
}

void get_init(ll& co, ll& l, ll dif){
	ll lo = 1, hi = 2*1e9;
	while (lo < hi){
		ll mid = (lo + hi) / 2;
		if ((1ll + mid)*mid / 2 < dif){
			lo = mid + 1;
		}else{
			hi = mid;
		}
	}
	while (l < lo*(lo + 1) / 2) lo --;
	co = lo; l -= co*(co + 1) / 2;
}

ll l, r;
void solve() {
	cin >> l >> r;
	ll cnt = 0;
	if (l >= r) {
		get_init(cnt, l, l - r + 1);
		ll dr = get(r, cnt + 1);
		ll dl = get(l, cnt + 2);
		pr(cnt + dr + dl, update(l, cnt + 2, dl), update(r, cnt + 1, dr));
	}else{
		get_init(cnt, r, r - l); // because we always take firstly from left;
		ll dl = get(l, cnt + 1);
		ll dr = get(r, cnt + 2);
		pr(cnt + dr + dl, update(l, cnt + 1, dl), update(r, cnt + 2, dr));
	}
	pr("\n");
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int nofcase;
	cin >> nofcase;
	for (int tt = 1; tt <= nofcase; tt++) {
		cout << "Case #" << tt << ": ";
		solve();
	}
	return 0;
}

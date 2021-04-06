#include <bits/stdc++.h>

#define MP make_pair
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REPR(i, a, b) for (int i = a; i > b; i--)

using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int maxN = 2e5;
int N, Q;
ll arr[maxN + 1];

class FenwickTree{
	// 1 based index;
	public:
	FenwickTree(): sums_(maxN+1, 0){}
	void update(int i, int delta){
		while (i <= N){
			sums_[i] += delta;
			i += lowbit(i);
		}
	}

	ll query(int i) const{
		ll sum = 0;
		while (i > 0){
			sum += sums_[i];
			i -= lowbit(i);
		}
		return sum;
	}
	private:
	vector<ll> sums_;
	static inline int lowbit(int x){
		return x & (-x);
	}
}; 

FenwickTree f0[2], f1[2];

void app(int i, ll x){
	f0[(i&1)^1].update(i, x - arr[i]);
	f1[(i&1)^1].update(i, i*(x - arr[i]));
	f0[i&1].update(i, -(x - arr[i]));
	f1[i&1].update(i, -i*(x - arr[i]));
	arr[i] = x;
}

void solve(){
	memset(arr, 0, sizeof(arr));
	cin >> N >> Q;
	REP(i, 1, N + 1){
		int a; cin >> a;
		app(i, a);
	}
	ll ans = 0;
	REP(i, 0, Q){
		char Q;
		int l, r;
		cin >> Q >> l >> r;
		if (Q == 'U')
			app(l, r);
		else{
			ll tmp = f1[(l&1)^1].query(r) - f1[(l&1)^1].query(l - 1) - (l - 1)*(f0[(l&1)^1].query(r) - f0[(l&1)^1].query(l - 1));
			ans += tmp; //pow(-1, (l&1)^1)
		}
	}
	cout << ans;
	REP(i, 1, N + 1){
		app(i, 0);
	}
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
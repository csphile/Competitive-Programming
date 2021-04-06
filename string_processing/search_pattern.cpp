#include <bits/stdc++.h>

#define MP make_pair
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REPR(i, a, b) for (int i = a; i > b; i--)

using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using pll = pair<long, long>;
// const int MOD = 1e9 + 7;
// const int maxN = 2e5 + 1;
int n;
void cnt_sort(vector<int>& p, vector<int>& c){
	int n = p.size();
	// cout << n << endl;
	vector<int> cnt(n);
	for (auto x: c){
		cnt[x] ++;
	}
	vector<int> pos(n), p_new(n);
	pos[0] = 0;
	for (int i = 1; i < n; i++){
		pos[i] = pos[i - 1] + cnt[i - 1];
	}
	
	for (auto x: p){
		int i = c[x];
		p_new[pos[i]] = x;
		pos[i]++;
	}
	p = p_new;
}

void suffix_array(string& s, vector<int>& p){
	// cout << "here" << endl;
	s += '$';
	vector<int> c(n);
	{
		// k = 0
		vector<pair<char, int>> a(n);
		for (int i = 0; i< n; i++) a[i] = {s[i], i};
		sort(a.begin(), a.end());
		for (int i = 0; i < n; i++) p[i] = a[i].second;		
		//compute the class
		c[p[0]] = 0;
		for (int i = 1; i < n; i++){
			if (a[i].first != a[i - 1].first) c[p[i]] = c[p[i - 1]] + 1;
			else c[p[i]] = c[p[i - 1]];
		}
	}
    
	int k = 0;
	while ((1 << k) < n){
		// k-> k + 1;
		for (int i = 0; i < n; i++){
			p[i] = (p[i] - (1 << k) + n)%n;
		}

		cnt_sort(p, c);

		vector<int> c_new(n);
		// compute the class
		c_new[p[0]] = 0;
		for (int i = 1; i < n; i++){
			// cout << p[i - 1] << endl;
			pii prev = {c[p[i - 1]], c[(p[i - 1] + (1 << k))%n]};
			pii now = {c[p[i]], c[(p[i] + (1 << k))%n]};
			if (now == prev){
				c_new[p[i]] = c_new[p[i - 1]];
			}
			else{
				c_new[p[i]] = c_new[p[i - 1]] + 1;
			}
		}
		c = c_new;
		k++;
	}
	s.pop_back();
}

int lower(string& s, string& pat, vector<int>& p){
	int m = pat.size();
	int l = 1, r = p.size() - 1;
	while (l <= r){
		int mid = l + (r - l) / 2;
		// as s is terminated by $; 
		int res = pat.compare(s.substr(p[mid], m));
		// cout << s.substr(p[mid], m) << endl;
		if (res <= 0){
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	return l;
}

int upper(string& s, string& pat, vector<int>& p){
	int m = pat.size();
	int l = 1, r = p.size() - 1;
	while (l <= r){
		int mid = l + (r - l) / 2;
		// as s is terminated by $; 
		int res = pat.compare(s.substr(p[mid], m));
		// cout << s.substr(p[mid], m) << endl;
		if (res < 0){
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	// cout << l << endl;
	return l;
}

void solve(){
	string s; cin >> s;
	n = s.size() + 1;
	vector<int> p(n); 
	suffix_array(s, p);
	// Don't return anything in your algorithme; 
	int q; cin >> q;
	for (int i = 0; i < q; i++){
		string pat; cin >> pat;
		// cout << search(s, pat, p) << endl;
		cout << upper(s, pat, p) - lower(s, pat, p) << endl;
	}
}

int main()
{
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	// int t;
	//cin >> t;
	//REP(t_, 1, t + 1)
	{
		// cout << "Case #" << t_ << ": ";
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
// windows : g++ A.cpp -o temp -Wall && temp

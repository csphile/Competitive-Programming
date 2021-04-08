#include <bits/stdc++.h>

#define MP make_pair
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REPR(i, a, b) for (int i = a; i > b; i--)

using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using pll = pair<long, long>;

struct SuffixArray
{
	const int L;
	string s;
	// prefix
	vector<vector<int>> prefix;
	// classes
	vector<vector<int>> classes;

	SuffixArray(const string &s_) : L(s.size() + 1)
	{
		s = s_ + '$';
		suffix_array();
	}

	void suffix_array()
	{
		vector<int> p(L), c(L);
		{
			// k = 0
			vector<pair<char, int>> a(L);
			for (int i = 0; i < L; i++)
				a[i] = {s[i], i};
			sort(a.begin(), a.end());
			for (int i = 0; i < L; i++)
				p[i] = a[i].second;
			//compute the class
			c[p[0]] = 0;
			for (int i = 1; i < L; i++)
			{
				if (a[i].first != a[i - 1].first)
					c[p[i]] = c[p[i - 1]] + 1;
				else
					c[p[i]] = c[p[i - 1]];
			}
			prefix.push_back(p);
			classes.push_back(c);
		}

		int k = 0;
		while ((1 << k) < L)
		{
			// k-> k + 1;
			for (int i = 0; i < L; i++)
			{
				p[i] = (p[i] - (1 << k) + L) % L;
			}

			cnt_sort(p, c);

			vector<int> c_new(L);
			// compute the class
			c_new[p[0]] = 0;
			for (int i = 1; i < L; i++)
			{
				// cout << p[i - 1] << endl;
				pii prev = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % L]};
				pii now = {c[p[i]], c[(p[i] + (1 << k)) % L]};
				if (now == prev)
				{
					c_new[p[i]] = c_new[p[i - 1]];
				}
				else
				{
					c_new[p[i]] = c_new[p[i - 1]] + 1;
				}
			}
			c = c_new;
			prefix.push_back(p);
			classes.push_back(c);
			k++;
		}
	}

	vector<int> GetSuffixArray() { return prefix.back(); }

	static void cnt_sort(vector<int> &prefix, vector<int> &c)
	{
		int n = prefix.size();
		// cout << n << endl;
		vector<int> cnt(n);
		for (auto x : c)
		{
			cnt[x]++;
		}
		vector<int> pos(n), p_new(n);
		pos[0] = 0;
		for (int i = 1; i < n; i++)
		{
			pos[i] = pos[i - 1] + cnt[i - 1];
		}

		for (auto x : prefix)
		{
			int i = c[x];
			p_new[pos[i]] = x;
			pos[i]++;
		}
		prefix = p_new;
	}
};

int n;
void cnt_sort(vector<int> &p, vector<int> &c)
{
	int n = p.size();
	// cout << n << endl;
	vector<int> cnt(n);
	for (auto x : c)
	{
		cnt[x]++;
	}
	vector<int> pos(n), p_new(n);
	pos[0] = 0;
	for (int i = 1; i < n; i++)
	{
		pos[i] = pos[i - 1] + cnt[i - 1];
	}

	for (auto x : p)
	{
		int i = c[x];
		p_new[pos[i]] = x;
		pos[i]++;
	}
	p = p_new;
}

void suffix_array(string &s, vector<int> &p, vector<int> &c)
{
	// cout << "here" << endl;
	s += '$';
	// vector<int> c(n);
	{
		// k = 0
		vector<pair<char, int>> a(n);
		for (int i = 0; i < n; i++)
			a[i] = {s[i], i};
		sort(a.begin(), a.end());
		for (int i = 0; i < n; i++)
			p[i] = a[i].second;
		//compute the class
		c[p[0]] = 0;
		for (int i = 1; i < n; i++)
		{
			if (a[i].first != a[i - 1].first)
				c[p[i]] = c[p[i - 1]] + 1;
			else
				c[p[i]] = c[p[i - 1]];
		}
	}

	int k = 0;
	while ((1 << k) < n)
	{
		// k-> k + 1;
		for (int i = 0; i < n; i++)
		{
			p[i] = (p[i] - (1 << k) + n) % n;
		}

		cnt_sort(p, c);

		vector<int> c_new(n);
		// compute the class
		c_new[p[0]] = 0;
		for (int i = 1; i < n; i++)
		{
			// cout << p[i - 1] << endl;
			pii prev = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]};
			pii now = {c[p[i]], c[(p[i] + (1 << k)) % n]};
			if (now == prev)
			{
				c_new[p[i]] = c_new[p[i - 1]];
			}
			else
			{
				c_new[p[i]] = c_new[p[i - 1]] + 1;
			}
		}
		c = c_new;
		k++;
	}
	// s.pop_back();
}

void lcp(string s, vector<int> &p, vector<int> &c, vector<int> &lcp_)
{
	int k = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int pi = c[i];
		int j = p[pi - 1];
		// lcp_[i] = lcp(s[i...], s[j...])
		while (s[i + k] == s[j + k])
			k++;
		lcp_[pi] = k;
		k = max(k - 1, 0);
	}
}

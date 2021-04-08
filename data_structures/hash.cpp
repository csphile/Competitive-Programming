#include <bits/stdc++.h>
using namespace std;
static constexpr int A = 1000000007, B = 1000000037;

class Hash
{
public:
    Hash(const string &s)
    {
        h[0] = s[0] % B;
        p[0] = 1;
        for (int i = 1; i < s.size(); ++i)
        {
            h[i] = (h[i - 1] * A + s[i]) % B;
            p[i] = (p[i - 1] * A) % B;
        }
    }

    // a and b are inclusive
    long long hash(const int a, const int b)
    {
        if (a)
        {
            const auto res = (h[b] - h[a - 1] * p[b - a + 1]) % B;
            return res < 0 ? B + res : res;
        }
        else
        {
            return h[b];
        }
    }

private:
    long long h[2000], p[2000];
};
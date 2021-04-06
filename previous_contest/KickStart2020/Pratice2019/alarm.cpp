//use c++ in kickstart since it's more faster and the same algorithm passes
//for c++ but not for python
#include <iostream>
#include <math.h>
using namespace std;
long long tomod = 1000000007;
long long power(long long x,long long y)
{
    long long t=1;
    while(y!=0)
    {
        if(y%2==1)
            t=t*x%tomod;
        x=x*x%tomod;
        y/=2;
    }
    return t;
}

int main() {
  long long t, N, K, x1, y1, C, D, E1, E2, F;
  cin >> t;
  for (int t_ = 1; t_ <= t; ++t_) {
    cin >> N >> K >> x1 >> y1 >> C >> D >> E1 >> E2 >> F;
    long long res = 0;
    long long x_new, y_new;
    long long factor = K;
    for (int i = 1; i <= N; ++i){
        int cur = (x1 + y1) % F;

        if (i != 1 ){
            /* compute the inverse of 1 / (i - 1) */
            factor += (power(i, K + 1) - i) * power(i - 1, tomod - 2);
            factor %= tomod;
        }
        /* pay attention to add modulus everywhere*/
        res += (((factor*cur)%tomod)*(N - i + 1)%tomod);
        res %= tomod;

        x_new = (x1 * C + y1 * D + E1) % F;
        y_new = (y1 * C + x1 * D + E2) % F;
        x1 = x_new;
        y1 = y_new;
    }
    cout << "Case #" << t_ << ": " << res << endl;
  }
  return 0;
}

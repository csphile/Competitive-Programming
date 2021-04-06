//
// Created by gael on 05/10/2020.
//
// passed cses 1107 sliding cost
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;

using namespace std;

typedef tree<
        int,
        null_type,
        less_equal<int>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;

using ll = long long;
#define trav(a,x) for (auto& a: x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()

template<class T> void read(T& t){ cin >> t;}
void read(double& d) { string t; read(t); d = stod(t); }
void read(long double& d) { string t; read(t); d = stold(t); }

template<class T> void read(vector<T>& vt){trav(a, vt) read(a);}
template<class H, class... T> void read(H& h, T&... t){ read(h); read(t...);}
int main(){
    ordered_set X;
    X.insert(1);
    X.insert(2);
    X.insert(4);
    X.insert(8);
    X.insert(16);

    cout<<*X.find_by_order(1)<<endl; // 2
    cout<<*X.find_by_order(2)<<endl; // 4
    cout<<*X.find_by_order(4)<<endl; // 16
    cout<<(end(X)==X.find_by_order(6))<<endl; // true

    cout<<X.order_of_key(-5)<<endl;  // 0
    cout<<X.order_of_key(1)<<endl;   // 0
    cout<<X.order_of_key(3)<<endl;   // 2
    cout<<X.order_of_key(4)<<endl;   // 2
    cout<<X.order_of_key(400)<<endl; // 5

    int n, k; read(n, k);
    vector<int> arr(n); read(arr);
    ordered_set s;
    for (int i = 0; i < k; i++) s.insert(arr[i]);
    ll old_m = *s.find_by_order((k + 1)/2 - 1);
    ll d = 0;
    for (int i = 0; i < k; i++){
        d += abs(arr[i] - old_m);
    }
    cout << d;
    for (int i = k; i < n; i++){
        s.erase(s.find_by_order(s.order_of_key(arr[i - k])));
        s.insert(arr[i]);
        ll m = *s.find_by_order((k + 1)/2 - 1);
        d += abs(m - arr[i]) - abs(old_m - arr[i - k]);
        if (k%2 == 0) d -= (m - old_m); // if k is even, m >= old_m
        old_m = m;
        cout << " " << d;
    }
    cout << endl;
    return 0;
}

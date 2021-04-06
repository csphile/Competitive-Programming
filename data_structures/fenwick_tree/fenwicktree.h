#include <bits/stdc++.h>

#define MP make_pair
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REPR(i, a, b) for (int i = a; i > b; i--)

using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const ll maxN = 1e4;

class FenwickTree{
    public:
    FenwickTree(int n): sums_(n + 1, 0){}

    void update(int i, int delta){
        i++; // FenwickTree is 1 indexed;
        while (i < sums_.size()){
            sums_[i] += delta;
            i += lowbit(i);
        }
    }
    int qry(int i){
        i++;
        int sum = 0; 
        while (i > 0){
            sum += sums_[i];
            i -= lowbit(i);
        }
        return sum;
    }
    private:
    vector<int> sums_;
    static inline int lowbit(int x){
        return x & (-x);
    };
};

struct Node {
  Node *left, *right;
  int sum;
  void pushup() {
    sum = left->sum + right->sum;
  }
};

Node* build(int a, int b) {
  Node* ret = new Node();
  ret->sum = 0;
  if (a + 1 == b) return ret;
  int mid = (a + b) / 2;
  ret->left = build(a, mid);
  ret->right = build(mid, b);
  return ret;
}
void insert(Node* cur, int a, int b, int pos, int c) {
  if (pos < a || pos >= b) return;
  if (a + 1 == b) {
    cur->sum += c;
    return;
  }
  int mid = (a + b) / 2;
  insert(cur->left, a, mid, pos, c);
  insert(cur->right, mid, b, pos, c);
  cur->pushup();
}
int query(Node* cur, int a, int b, int k) {
  if (a + 1 == b) {
    return a;
  }
  int mid = (a + b) / 2;
  return cur->left->sum >= k
    ? query(cur->left, a, mid, k)
    : query(cur->right, mid, b, k - cur->left->sum);
}
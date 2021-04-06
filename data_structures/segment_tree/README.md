# Segment Tree

| data structures | modify elements | take the prefix sum |
|-----------------|-----------------|---------------------|
| array |  O(1) | O(n) |
| prefix array |    O(n)   |   O(1) |
| segment tree | O(log n) |    O(log n) |

## How to implement 
Method 1: Top down 
```c++
int build(int node, int left, int right) {
    if(left == right) {
        return segmentTree[node] = left;
    }
    int leftNode = node << 1;
    int rightNode = leftNode | 1;
    int mid = left + (right - left) / 2;
    int leftIdx = build(leftNode, left, mid);
    int rightIdx = build(rightNode, mid + 1, right);
    return segmentTree[node] = (arr[leftIdx] <= arr[rightIdx]) ? leftIdx : rightIdx;
}
```
简单来说，假如要储存长度为n的数组，根节点则储存线段`[0, n + 1)`（左闭右开）。对所有节点的子结点，都把父节点对半分开，树叶上就是原数组。    
内存占用：`4*n`     

Method 2: Bottom up    
此情况下，`b += n, e += n` 得到树叶节点，再往上查找     

```c++
template <typename T>
class SegmentTree
{
	static T unit = INT_MIN; 
	T f(T a, T b) {return max(a, b); }
	vector<T> data;
	int n; 
	SegmentTree(int n = 0, T def = unit): data(2*n, def), n(n){}
	void update(int pos, T val){
		for (data[pos += n] = val; pos /= 2; )
			data[pos] = f(data[pos*2], data[pos*2 + 1]); 
	}
	T query(int b, int e){
		// [b, e)
		b += n; 
		e += n; 
		T ra = unit, rb = unit; 
		for (; b < e; b /= 2, e /= 2){
			if (b&1)
				ra = f(ra, data[b++]); 
			if (e&1)
				rb = f(data[--e], rb); 
		}
		return f(ra, rb); 
	}
};
```

## Application 

[Skyline Photo](https://codeforces.com/problemset/problem/1482/E)     
[Solution](../../previous_contest/CF/round709_E.cpp)
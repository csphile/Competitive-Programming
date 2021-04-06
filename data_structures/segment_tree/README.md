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
This will use approximately 4*n memory where n is the original size of the array. We can do better 

Method 2: 
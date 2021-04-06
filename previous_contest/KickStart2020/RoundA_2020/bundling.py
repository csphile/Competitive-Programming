from math import ceil
from sys import stdin

def readarray(tpr):
    return list(map(tpr, stdin.readline().split()))

def readint():
    return int(stdin.readline())

def readstring():
    return str(stdin.readline().strip())

def dfs(u, d, cnt, c, k):
    global ans
    for i in range(26):
        if c[u][i]:
            dfs(c[u][i], d + 1, cnt, c, k)
            cnt[u] += cnt[c[u][i]]
    if cnt[u] >= k:
        cnt[u] -= k
        ans += d


def solve():
    global ans
    ans = 0
    c = [[0]*26 for _ in range(int(2e6 + 1))]
    cnt = [0 for _ in range(int(2e6 + 1))]

    n, k = readarray(int)
    m = 1
    for _ in range(n):
        s = readstring()
        u = 0
        for cha in s:
            if not c[u][ord(cha) - ord('A')]:
                c[u][ord(cha) - ord('A')] = m
                m += 1
            u = c[u][ord(cha) - ord('A')]
        cnt[u] += 1
    dfs(0, 0, cnt, c, k)
    print(ans)


if __name__ == "__main__":
    global ans, k
    t = readint()
    for t_ in range(1, t + 1):
        print("Case #{}: ".format(t_), end="")
        solve()

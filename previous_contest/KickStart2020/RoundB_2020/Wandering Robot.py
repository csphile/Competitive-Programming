import math
from sys import stdin

# for interactive problem:
# python interactive_runner.py python local_testing_tool.py 2 -- python interact.py
# The same algorithme can't pass with python
def readarray(tpr):
    return list(map(tpr, stdin.readline().split()))


def readint():
    return int(stdin.readline())

def C(m, n, f):
    return f[m + n] - f[m] - f[n]   

def solve():
    W, H, L, U, R, D = readarray(int)
    #precomputation
    maxn = W + H + 1
    f = [0]
    p = [0]
    for i in range(1, maxn + 1):
        f.append(f[-1] + math.log(i))

    for i in range(1, maxn + 1):
        p.append(p[-1] + math.log(2))

    ans = 0


    if R < W:
        for i in range(U - 1):
            ans += math.exp(C(i, R - 1) - p[i + R])
    
    if D < H:
        for i in range(L - 1):
            ans += math.exp(C(i, D - 1) - p[i + D])
    print(ans)

if __name__ == "__main__":
    t = readint()
    for t_ in range(1, t + 1):
        print("Case #{}: ".format(t_), end="")
        solve()

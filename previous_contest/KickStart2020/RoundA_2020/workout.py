from math import ceil
from sys import stdin


def readarray(tpr):
    return list(map(tpr, stdin.readline().split()))


def readint():
    return int(stdin.readline())


# input here
n, k = None, None

def solve():
    n, k = readarray(int)
    m = readarray(int)
    lb = 1
    rb = m[-1] - m[0]
    while lb < rb:
        mb = (lb + rb) // 2
        k2 = 0
        for i in range(1, len(m)):
            d = m[i] - m[i - 1]
            # ceil((m[i] - m[i - 1]) / mb)
            #k2 += (d + mb - 1) // mb - 1
            k2 += ceil(d / mb) - 1
        if k2 > k:
            lb = mb + 1
        else:
            rb = mb
    print(lb)


if __name__ == "__main__":
    t = readint()
    for t_ in range(1, t + 1):
        print("Case #{}: ".format(t_), end="")
        solve()

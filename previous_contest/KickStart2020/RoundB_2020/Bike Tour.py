from math import ceil
from sys import stdin

# for interactive problem:
# python interactive_runner.py python local_testing_tool.py 2 -- python interact.py

def readarray(tpr):
    return list(map(tpr, stdin.readline().split()))


def readint():
    return int(stdin.readline())



def solve():
    N = readint()
    arr = readarray(int)
    ans = 0
    for i in range(1, N - 1):
        if arr[i] > arr[i - 1] and arr[i] > arr[i + 1]:
            ans += 1
    print(ans)


if __name__ == "__main__":
    t = readint()
    for t_ in range(1, t + 1):
        print("Case #{}: ".format(t_), end="")
        solve()

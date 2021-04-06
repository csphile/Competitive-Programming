from math import ceil
from sys import stdin

# for interactive problem:
# python interactive_runner.py python local_testing_tool.py 2 -- python interact.py

def readarray(tpr):
    return list(map(tpr, stdin.readline().split()))


def readint():
    return int(stdin.readline())



def solve():
    N, D = readarray(int)
    days = readarray(int)
    max_ = []
    for i in range(len(days)):
        max_.append(D // days[i] * days[i])

    ls , rs = 1, max(max_) + 1

    while ls < rs:
        ms = (ls + rs) // 2 + 1
        next = ms
        possible = True

        for i in range(N):
            if next > max_[i]:
                possible = False
                break
            if next % days[i] == 0:
                next = next
            else:
                next = (next // days[i] + 1) * days[i]
            
        if possible:
            ls = ms
        else:
            rs = ms - 1
    print(ls)


if __name__ == "__main__":
    t = readint()
    for t_ in range(1, t + 1):
        print("Case #{}: ".format(t_), end="")
        solve()

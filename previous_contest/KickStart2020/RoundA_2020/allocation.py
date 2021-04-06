from sys import stdin


def readarray(tpr):
    return list(map(tpr, stdin.readline().split()))


def readint():
    return int(stdin.readline())


def solve(houses, B):
    houses = sorted(houses)
    sum = 0
    for i_iter in range(len(houses)):
        sum += houses[i_iter]
        if sum > B:
            return i_iter
    return len(houses)

if __name__ == "__main__":
    t = readint()
    for i in range(1, t + 1):
        A, B = [int(s) for s in input().split(" ")]
        houses = readarray(int)
        res_i = solve(houses, B)
        print("Case #{}: {}".format(i, res_i))

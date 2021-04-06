from sys import stdin


def readarray(tpr):
    return list(map(tpr, stdin.readline().split()))


def readint():
    return int(stdin.readline())


def solve(S):
    S += "0"
    res = [0 for _ in range(len(S))]
    for i, s in enumerate(S):
        if i == 0:
            res[0] = int(s)
            continue
        s_cur = int(s)
        s_prev = int(S[i - 1])
        res[i] = -s_prev + s_cur
    toreturn = []
    for i in range(len(S)):
        if res[i] > 0:
            toreturn.append(res[i] * '(')
        else:
            toreturn.append((-res[i])*')')
        toreturn.append(S[i])
    toreturn.pop(-1)
    return "".join(toreturn)

if __name__ == "__main__":
    t = readint()
    for i in range(1, t + 1):
        STR = readarray(str)
        STR = STR[0]
        res = solve(STR)
        print("Case #{}: {}".format(i, res))

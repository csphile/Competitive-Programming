from sys import stdin


def readarray(tpr):
    return list(map(tpr, stdin.readline().split()))


def readint():
    return int(stdin.readline())


def solve(intervals):
    intervals_ind = [[itval, ind] for ind, itval in enumerate(intervals)]
    intervals = sorted(intervals_ind, key=lambda x: x[0])

    toReturn = {}
    cur = [0, 0]
    for i in range(len(intervals)):
        if intervals[i][0][0] >= cur[0]:
            cur[0] = intervals[i][0][1]
            toReturn[intervals[i][1]] = 'C'

        elif intervals[i][0][0] >= cur[1]:
            cur[1] = intervals[i][0][1]
            toReturn[intervals[i][1]] = 'J'

        else:
            return False

    temp = []
    for k, v in sorted(toReturn.items(), key=lambda x: x[0]):
        temp.append(v)
    return ''.join(temp)


if __name__ == "__main__":
    t = readint()
    for t_ in range(1, t + 1):
        N = readint()
        intervals = []
        for _ in range(N):
            intervals.append(readarray(int))
        res = solve(intervals)
        if not res:
            print("Case #{}: {}".format(t_, "IMPOSSIBLE"))
        else:
            print("Case #{}: {}".format(t_, res))

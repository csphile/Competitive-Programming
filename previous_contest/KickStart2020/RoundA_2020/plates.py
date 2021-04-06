from sys import stdin


def readarray(tpr):
    return list(map(tpr, stdin.readline().split()))


def readint():
    return int(stdin.readline())


def solve(values, N, K, P):
    cum_values = []

    for j in range(N):
        temp = [0]
        for k in range(K):
            temp.append(temp[-1] + values[j][k])
        cum_values.append(temp)
    dp = [[0] * (P + 1) for _ in range(N)]
    for p in range(P + 1):
        if p <= K:
            dp[0][p] = cum_values[0][p]
        else:
            dp[0][p] = dp[0][p - 1]

    for j in range(1, N):
        for k in range(P + 1):
            for k_ in range(max(k - K, 0), k + 1):
                dp[j][k] = max(dp[j - 1][k_] + cum_values[j][k - k_], dp[j][k])

    return dp[N - 1][P]


if __name__ == "__main__":
    t = readint()
    for i in range(1, t + 1):
        N, K, P = [int(s) for s in input().split(" ")]
        values = []
        for _ in range(N):
            values.append(readarray(int))
        res = solve(values, N, K, P)
        print("Case #{}: {}".format(i, res))

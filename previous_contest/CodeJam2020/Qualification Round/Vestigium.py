from sys import stdin


def readarray(tpr):
    return list(map(tpr, stdin.readline().split()))


def readint():
    return int(stdin.readline())


def solve(N, matrix):
    trace, r, c = 0, 0, 0
    for j in range(N):
        trace += matrix[j][j]
        temp = set({})
        for k in range(N):
            if matrix[j][k] in temp:
                r += 1
                break
            else:
                temp.add(matrix[j][k])
        temp_colomn = set({})
        for k in range(N):
            if matrix[k][j] in temp_colomn:
                c += 1
                break
            else:
                temp_colomn.add(matrix[k][j])
    return trace, r, c

if __name__ == "__main__":
    t = readint()
    for i in range(1, t + 1):
        N = readint()
        matrix = []
        for _ in range(N):
            matrix.append(readarray(int))
        trace, r, c = solve(N, matrix)
        print("Case #{}: {} {} {}".format(i, trace, r, c))

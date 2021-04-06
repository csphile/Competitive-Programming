import math
def solve(R, C, lines):
    seen, res = bfs(R, C, lines)
    if res == 0 and seen[0][0] == -1:
        i = R // 2
        j = C // 2
        lines[i] = lines[i][0:j] + '1' + lines[i][j+1:]
        _, temp = bfs(R, C, lines)
        return temp
    K = res
    K_left = 1
    while K_left < K:
        mid = (K_left + K) // 2
        #check if we can visit all offices with steps greater than mid within mid steps
        #find all offices with steps > mid
        leftUpper, rightUpper, leftDown, rightDown = (C, R), (R, 0), (0, C), (0, 0)
        for i in range(R):
            for j in range(C):
                if seen[i][j] > mid:
                    if i + j < leftUpper[0] + leftUpper[1]:
                        leftUpper = (i, j)
                    if i + j > rightDown[0] + rightDown[1]:
                        rightDown = (i, j)
                    if j - i > rightUpper[1] - rightUpper[0]:
                        rightUpper = (i, j)
                    if j - i < leftDown[1] - leftDown[0]:
                        leftDown = (i, j)
        diat = max(abs(leftUpper[0] - rightDown[0]) + abs(leftUpper[0] - rightDown[0]),
            abs(rightUpper[0] - leftDown[0]) + abs(rightUpper[1] - leftDown[0]))
        if math.ceil(diat / 2) > mid:
            K = mid - 1
        else:
            K_left = mid + 1
    return K_left

def bfs(R, C, lines):
    seen = [[-1]*C for _ in range(R)]
    tosee = []
    #do a BFS
    steps = 0
    for i in range(R):
        for j in range(C):
            if lines[i][j] == '1':
                tosee.append((i, j))
                seen[i][j] = 0
    directions = [1, 0, -1, 0, 1]
    while tosee:
        size = len(tosee)
        searched = False
        while size:
            size -= 1
            i, j = tosee.pop(0)
            for d in range(4):
                to_i = i + directions[d]
                to_j = j + directions[d + 1]
                if  to_i >= 0 and to_i < R and to_j >= 0 and to_j < C and seen[to_i][to_j] == -1:
                    searched = True
                    seen[to_i][to_j] = steps
                    tosee.append((to_i, to_j))
        if searched: steps += 1
    return seen, steps
t = int(input())
for i in range(1, t + 1):
    R, C = [int(s) for s in input().split(" ")]
    lines = []
    for _ in range(R):
        lines.append(str(input()))
    res = solve(R, C, lines)
    print("Case #{}: {}".format(i, res))

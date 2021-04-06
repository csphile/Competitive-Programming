# from random import choice, shuffle
from sys import stdin


def readarray(tpr):
    return list(map(tpr, stdin.readline().split()))


def readint():
    return int(stdin.readline())


def compute_trace(board):
    res = 0
    for i in range(len(board)):
        res += board[i][i]
    return res


def solve(board, cur, K):
    if cur == N ** 2:
        if compute_trace(board) == K:
            return True
        else:
            return False

    row = cur // N
    col = cur % N

    if board[row][col] != 0:
        return solve(board, cur + 1, K)

    for i in range(1, N + 1):
        in_conflict = False
        for j in range(N):
            if board[row][j] == i or board[j][col] == i:
                in_conflict = True
                break
        if in_conflict:
            continue
        else:
            board[row][col] = i
            if solve(board, cur + 1, K):
                return True
            board[row][col] = 0
    return False


def get_diagonal(N, len_, K):
    if K <= 0:
        return []
    if len_ == 1 and K <= N:
        return [[K]]
    if len_ == 1 and K > N:
        return []
    res = []
    for i in range(1, N + 1):
        if i > K:
            break
        others = get_diagonal(N, len_ - 1, K - i)
        for o in others:
            o = list(o)
            o.append(i)
            o = sorted(o)
            o = tuple(o)
            res.append(o)
    return set(res)


if __name__ == "__main__":
    t = readint()
    for t_ in range(1, t + 1):
        N, K = readarray(int)

        board = [[0] * N for _ in range(N)]
        okay = False
        if K % N == 0:
            okay = True
            for i in range(N):
                board[i][i] = K // N
            solve(board, 0, K)
        else:
            diags = get_diagonal(N, N, K)
            if len(diags) == 0:
                okay = False
            else:
                for dia in diags:
                    for i in range(N):
                        board[i][i] = dia[i]
                    if solve(board, 0, K):
                        okay = True
                        break
                    else:
                        for i in range(N):
                            board[i][i] = 0
        if okay:
            print("Case #{}: {}".format(t_, "POSSIBLE"))
            for i in range(N):
                for j in range(N):
                    print(board[i][j], end=' ')
                print(" ")
        else:
            print("Case #{}: {}".format(t_, "IMPOSSIBLE"))
#
# def rls(n):
#     if n <= 0:
#         return []
#     else:
#         symbols = list(range(n))
#         square = _rls(symbols)
#         return _shuffle_transpose_shuffle(square)
#
#
# def _shuffle_transpose_shuffle(matrix):
#     square = matrix[:]
#     shuffle(square)
#     trans = list(zip(*square))
#     shuffle(trans)
#     return trans
#
#
# def _rls(symbols):
#     n = len(symbols)
#     if n == 1:
#         return [symbols]
#     else:
#         sym = choice(symbols)
#         symbols.remove(sym)
#         square = _rls(symbols)
#         square.append(square[0].copy())
#         for i in range(n):
#             square[i].insert(i, sym)
#         return square
#
#
# def _check_rows(square):
#     if not square:
#         return True
#     set_row0 = set(square[0])
#     return all(len(row) == len(set(row)) and set(row) == set_row0
#                for row in square)
#
#
# def readarray(tpr):
#     return list(map(tpr, stdin.readline().split()))
#
#
# def readint():
#     return int(stdin.readline())
#
#
# def compute_trace(board):
#     res = 0
#     for i in range(len(board)):
#         res += board[i][i]
#     return res
#
#
# if __name__ == '__main__':
#     t = readint()
#     for t_ in range(1, t + 1):
#         N, K = readarray(int)
#         tryTimes = 0
#         found = False
#         while tryTimes < 50000:
#             square = rls(N)
#             trace = compute_trace(square) + N
#             if trace == K:
#                 found = True
#                 break
#             tryTimes += 1
#
#         board = []
#         for i in range(N):
#             temp = []
#             for j in range(N):
#                 temp.append(square[i][j] + 1)
#             board.append(temp)
#
#         if found:
#             print("Case #{}: {}".format(t_, "POSSIBLE"))
#             for i in range(N):
#                 for j in range(N):
#                     print(board[i][j], end=' ')
#                 print(" ")
#         else:
#             print("Case #{}: {}".format(t_, "IMPOSSIBLE"))

#
#

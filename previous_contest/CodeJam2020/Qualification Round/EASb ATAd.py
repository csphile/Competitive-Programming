import sys
from sys import stdin

# for local testing
# python interactive_runner.py python local_testing_tool.py 0 -- python interact.py

def readarray(tpr):
    return list(map(tpr, stdin.readline().split()))


def readint():
    return int(stdin.readline().strip())


def readchar():
    return str(stdin.readline().strip())

same_pair, diff_pair, arr = None, None, None

def quest(i):
    print(i + 1)
    sys.stdout.flush()
    s = readint()
    return s

def findpair(i):
    # find c and b - 1 - c
    global same_pair, diff_pair, arr
    arr[i] = quest(i)
    arr[b - 1 - i] = quest(b - 1 - i)

    if diff_pair == -1 and arr[i] != arr[b - 1 - i]:
        diff_pair = i
    
    if same_pair == -1 and arr[i] == arr[b - 1 - i]:
        same_pair = i

def findchange():
    global same_pair, diff_pair, complemented, reversed, arr
    complemented = False
    if same_pair != -1 and quest(same_pair) != arr[same_pair]:
        complemented = True
    if same_pair == -1:
        quest(0) # waste an opportunity to balance the count
    
    reversed = complemented
    if diff_pair != -1 and quest(diff_pair) != arr[diff_pair]:
        reversed = not complemented
    
    if diff_pair == -1:
        quest(0)

    if reversed:
        for i in range(b // 2):
            arr[i], arr[b - 1 - i] = arr[b - 1 - i], arr[i]

    if complemented:
        for i in range(b):
            arr[i] = 1 - arr[i]

def solve():
    global same_pair, diff_pair, complemented, reversed, arr

    arr = [0 for _ in range(100)]
    diff_pair = -1
    same_pair = -1
    complemented = False
    reversed = False

    for i in range(5):
        findpair(i)
    findchange()
    c = 5
    while c < b // 2:
        for i in range(4):
            if c >= b // 2:
                break
            findpair(c)
            c += 1

        findchange()

    for i in range(b):
        print(arr[i], end = '')
    print()
    sys.stdout.flush()
    s = readchar()
    if s == 'N':
        return

diff_pair, same_pair, reversed, complemented = None, None, None, None
arr = None
t, b = readarray(int)
for _ in range(t):
    solve()



# input() reads a string with a line of input, stripping the ' ' (newline) at the end.
# This is all you need for most Kick Start problems.
t = int(input()) # read a line with a single integer
for t_ in range(t):
    n = int(input())
    s = str(input())
    m = [int(s[i]) for i in range(n)]
    windowSize = n // 2 + n % 2
    partial = sum(m[:windowSize])
    res = partial
    for i in range(n - windowSize):
        partial -= m[i]
        partial += m[i + windowSize]
        res = max(res, partial)

    print("Case #{}: {}".format(t_ + 1, res))
    # check out .format's specification for more formatting options

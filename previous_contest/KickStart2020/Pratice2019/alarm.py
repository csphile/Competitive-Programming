# input() reads a string with a line of input, stripping the ' ' (newline) at the end.
# This is all you need for most Kick Start problems.
const = int(1e9 + 7)
t = int(input()) # read a line with a single integer
def power(x,y):
    t=1
    while y != 0:
        if y % 2 == 1:
            t = (t*x) %const
        x = (x*x) %const
        y //= 2
    return t;
for t_ in range(1, t + 1):
    N, K, x1, y1, C, D, E1, E2, F = [int(s) for s in input().split(" ")]
    # read a list of integers, 2 in this case
    res = 0
    factor = K
    for i in range(1, N + 1):
        cur = (x1 + y1) % F
        #compute the number to add:
        if i != 1:
            factor += (power(i, K + 1) - i)  * power(i - 1, const - 2)
            factor %= const
        res += factor * cur * (N - i + 1)
        res %= const
        x_new = (x1 * C + y1 * D + E1) % F
        y_new = (y1 * C + x1 * D + E2) % F
        x1 = x_new
        y1 = y_new

    print("Case #{}: {}".format(t_, res % const))
    # check out .format's specification for more formatting options

# input() reads a string with a line of input, stripping the ' ' (newline) at the end.
# This is all you need for most Kick Start problems.
import sys
t = int(input())
for _ in range(t):
    A, B = [int(s) for s in input().split(" ")]
    A += 1
    N = int(input())
    s = " "
    while True:
        ans = (A + B) // 2
        print(ans)
        sys.stdout.flush()
        s = str(input())
        if s == "CORRECT":
            break
        elif s == "TOO_SMALL":
            A = ans + 1
        else:
            B = ans - 1

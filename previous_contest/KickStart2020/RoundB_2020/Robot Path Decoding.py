from math import ceil
from sys import stdin

# for interactive problem:
# python interactive_runner.py python local_testing_tool.py 2 -- python interact.py
from collections import Counter

def readarray(tpr):
    return list(map(tpr, stdin.readline().split()))

def readint():
    return int(stdin.readline())

def toadd(s):
    if len(s) == 0:
        return {"N": 0, "S": 0, "W": 0, "E": 0}

    if not s[0].isalpha():
        j = 0
        while s[j] != '(':
            j += 1

        balance = 1
        j2 = j + 1
        while balance != 0:
            if s[j2] == '(':
                balance += 1
            elif s[j2] == ')':
                balance -= 1
            j2 += 1
        j2 -= 1
        temp = toadd(s[j + 1: j2])
        
        factor = int(s[0:j])
        temp2 = toadd(s[j2 + 1:])
            
        for char in "NSWE":
            temp[char] *= factor
            temp[char] += temp2[char]
        return temp
    else:
        prefix = {"N": 0, "S": 0, "W": 0, "E": 0}
        j = 0
        while s[j].isalpha():
            prefix[s[j]] += 1
            j += 1
            if j == len(s):
                return prefix
        temp2 = toadd(s[j:])
        for char in "NSWE":
            temp2[char] += prefix[char]
        return temp2
            
def solve():
    inst = readarray(str)[0]
    record = toadd(inst)
    x, y = 0, 0
    x += record['E']
    x -= record['W']
    y -= record['N']
    y += record['S']
    print(x % (10**9) + 1, end = " ")
    print(y % (10**9) + 1)

if __name__ == "__main__":
    t = readint()
    for t_ in range(1, t + 1):
        print("Case #{}: ".format(t_), end="")
        solve()

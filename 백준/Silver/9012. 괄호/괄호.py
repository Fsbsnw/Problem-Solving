import sys
input = sys.stdin.readline

n = int(input())
for i in range(n):
    s = input().rstrip()
    stack = []
    for j in s:
        if j == '(':
            stack.append('(')
        else:
            if not stack:
                print("NO")
                break
            stack.pop()
    else:
        if stack:
            print("NO")
        else:
            print("YES")
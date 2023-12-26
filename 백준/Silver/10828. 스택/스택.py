import sys
input = sys.stdin.readline

n = int(input())
stack = []

for i in range(n):
    s = input().split()
    if len(s) == 2:
        stack.append(s[1])
    else:
        if s[0] == "top":
            if not stack:
                print(-1)
            else:
                print(stack[-1])
        elif s[0] == "size":
            print(len(stack))
        elif s[0] == "empty":
            print(1 if not stack else 0)
        else:
            if not stack:
                print(-1)
            else:
                print(stack.pop())
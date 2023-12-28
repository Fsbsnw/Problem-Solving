import sys
input = sys.stdin.readline

s = input().rstrip()
stack = []
cnt = 0
for i, c in enumerate(s):
    if c == '(':
        stack.append('(')
    else:
        if stack[-1] == '(':
            if s[i - 1] == '(':
                stack.pop()
                cnt += len(stack)
            else:
                stack.pop()
                cnt += 1
print(cnt)
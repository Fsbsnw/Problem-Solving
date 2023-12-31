import sys
input = sys.stdin.readline

s = input().rstrip()
stack = []
result = ""

for i in s:
    if i == '(':
        stack.append(i)
    elif i in ['+', '-']:
        while stack and stack[-1] != '(':
            result += stack.pop()
        stack.append(i)
    elif i in ['*', '/']:
        while stack and stack[-1] in ['*', '/']:
            result += stack.pop()
        stack.append(i)
    elif i == ')':
        while stack and stack[-1] != '(':
            result += stack.pop()
        stack.pop()
    else:
        result += i
while stack:
    result += stack.pop()
print(result)
import sys
input = sys.stdin.readline

n = int(input())
stack = []
idx = 0
result = []
arr = []
for i in range(n):
    arr.append(int(input()))

for i in range(1, n + 1):
    if not stack:
        stack.append(i)
        result.append('+')
        continue
    while stack and stack[-1] == arr[idx]:
        stack.pop()
        idx += 1
        result.append('-')
    stack.append(i)
    result.append('+')

while stack and stack[-1] == arr[idx]:
    stack.pop()
    idx += 1
    result.append('-')

if stack:
    print("NO")
else:
    for _ in result:
        print(_)
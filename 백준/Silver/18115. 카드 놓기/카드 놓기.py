import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
command = list(map(int , input().split()))
result = deque()

for i, val in enumerate(reversed(command), 1):
    if val == 1:
        result.appendleft(i)
    elif val == 2:
        temp = result.popleft()
        result.appendleft(i)
        result.appendleft(temp)
    else:
        result.append(i)

print(*result)
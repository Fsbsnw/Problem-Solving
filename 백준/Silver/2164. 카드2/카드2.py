import sys
from collections import deque
input = sys.stdin.readline

n = deque([i for i in range(1, int(input()) + 1)])

while len(n) > 1:
    n.popleft()
    n.append(n.popleft())
print(*n)
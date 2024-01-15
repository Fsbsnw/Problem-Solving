import sys
import heapq

input = sys.stdin.readline

n = int(input())
heap = []
for i in range(n):
    c = int(input())
    if c:
        heapq.heappush(heap, -c)
    else:
        if not heap:
            print(0)
        else:
            print(-heapq.heappop(heap))
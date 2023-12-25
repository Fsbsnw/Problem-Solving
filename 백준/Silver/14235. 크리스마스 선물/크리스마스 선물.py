import sys
input = sys.stdin.readline

n = int(input())
arr = []
for i in range(n):
    now = list(map(int, input().split()))
    if now[0] == 0:
        if not arr:
            print(-1)
        else:
            maxIdx = arr.index(max(arr))
            print(arr.pop(maxIdx))
    else:
        arr += now[1:]
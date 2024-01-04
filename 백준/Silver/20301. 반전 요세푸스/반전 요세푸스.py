import sys
input = sys.stdin.readline

n, k, m = map(int, input().split())

arr = [i for i in range(1, n + 1)]
idx = 0
cnt = 0

while arr:
    if (cnt // m) % 2 != 0:
        idx = (idx + len(arr) - k) % len(arr)
    else:
        idx = (idx + k - 1) % len(arr)
    cnt += 1
    print(arr.pop(idx))
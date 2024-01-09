import sys
input = sys.stdin.readline

t = int(input())
for i in range(t):
    k = int(input())
    n = int(input())
    mmax = max(n, k)
    arr = [[0] * (mmax + 1) for i in range(mmax + 1)]
    
    for i in range(len(arr[0])):
        arr[0][i] = i
    
    for i, val1 in enumerate(arr):
        if i == 0:
            continue
        for j, val2 in enumerate(val1):
            arr[i][j] = sum(arr[i - 1][:j + 1])

    print(arr[k][n])
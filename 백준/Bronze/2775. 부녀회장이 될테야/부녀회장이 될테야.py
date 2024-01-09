import sys
input = sys.stdin.readline

t = int(input())
for i in range(t):
    k = int(input())
    n = int(input())
    arr = [i for i in range(1, n + 1)]

    for i in range(k):
        for j in range(1, n):
            arr[j] += arr[j - 1]
    print(arr[n - 1])
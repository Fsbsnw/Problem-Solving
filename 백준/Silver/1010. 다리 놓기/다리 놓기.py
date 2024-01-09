import sys
input = sys.stdin.readline

t = int(input())
for i in range(t):
    R, N = map(int, sys.stdin.readline().split())

    def dp(num):
        if num == 0 or num == 1:
            return 1
        else:
            factorial = num * dp(num - 1)
        return factorial

    ans = dp(N) // (dp(R) * dp(N - R))
    print(ans)
import sys
input = sys.stdin.readline

n = int(input())
dp = {1 : 1, 2 : 3}

for i in range(3, n + 1):
    dp[i] = 2 * dp[i - 2] + dp[i - 1]
print(dp[n] % 10007)
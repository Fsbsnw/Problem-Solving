import sys
input = sys.stdin.readline

n = int(input())

dp = {0 : 0}
for i in range(1, n + 1):
    if i - 2 in dp and i - 5 in dp:
        dp[i] = min(dp[i - 2], dp[i - 5]) + 1
    elif i - 2 in dp and i - 5 not in dp:
        dp[i] = dp[i - 2] + 1
    elif i - 2 not in dp and i - 5 in dp:
        dp[i] = dp[i - 5] + 1
print(dp[n] if n in dp else -1)
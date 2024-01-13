import sys
input = sys.stdin.readline

n = int(input())
day = []
earn = []
dp = [0] * (n + 1)

for i in range(n):
    d, e = map(int, input().split())
    day.append(d)
    earn.append(e)

for i, val in enumerate(earn):
    nextR = i + day[i]
    dp[i] = max(dp[i - 1], dp[i])
    if nextR <= len(earn):
        dp[nextR] = max(dp[nextR - 1], dp[nextR] , dp[i] + val)
dp[-1] = max(dp[-2], dp[-1])
print(dp[-1])
import sys
input = sys.stdin.readline

n = int(input())
towers = list(reversed(list(map(int, input().split()))))
rasers = [0] * n
arr = []
    
for i, val in enumerate(towers):
    if i == 0:
        arr.append((i, val))
        continue
    if val > towers[i - 1]:
        while arr and arr[-1][1] < val:
            idx, tower = arr.pop()
            rasers[idx] = n - i
    arr.append((i, val))
rasers.reverse()
print(*rasers)
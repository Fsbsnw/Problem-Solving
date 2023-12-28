import math
def solution(k, d):
    cnt = 0
    for x in range(0, d + 1, k):
        maxY = (d ** 2 - x ** 2) ** 0.5
        cnt += math.ceil(maxY / k) + (1 if maxY % k == 0 else 0)
    return cnt
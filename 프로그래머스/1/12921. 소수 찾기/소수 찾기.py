def isPrime(n):
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return 0
    return 1

def solution(n):
    cnt = 0
    for i in range(2, n + 1):
        cnt += isPrime(i)
    return cnt
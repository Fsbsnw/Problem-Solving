def solution(a, b, n):
    bottles = 0
    result = 0
    while n >= a:
        n, remain = divmod(n, a)
        bottles = n * b + remain
        result += n * b
        n = bottles
    return result
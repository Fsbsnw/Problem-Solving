import math
def solution(n, k):
    arr = []
    numbers = [i for i in range(n + 1)]
    for i in range(1, n):
        temp = math.factorial(n - i)
        now = ((k - 1) // temp) + 1
        for num in numbers:
            if num:
                now -= 1
            if now == 0:
                break
        arr.append(num)
        numbers[numbers.index(num)] = 0
        k = k - temp * ((k - 1) // temp)
    arr.append(max(numbers))
    return arr
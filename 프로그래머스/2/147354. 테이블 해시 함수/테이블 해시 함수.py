from functools import reduce
def solution(data, col, row_begin, row_end):
    data.sort(key=lambda x : (x[col - 1], -x[0]))
    arr = []
    for i, num in enumerate(data[row_begin - 1 : row_end], row_begin):
        temp = 0
        for c in num:
            temp += c % i
        arr.append(temp)
    return reduce(lambda x, y : x ^ y, arr)

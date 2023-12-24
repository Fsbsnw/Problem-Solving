def solution(storey):
    print(storey)
    if storey < 10:
        return min(storey, 10 - storey + 1)
    remain = storey % 10 # 1의 자리
    return min(remain + solution(storey // 10), 10 - remain + solution(storey // 10 + 1))
# 100
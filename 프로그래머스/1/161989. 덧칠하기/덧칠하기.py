def solution(n, m, section):
    idx = 0
    cnt = 0
    for i in section:
        if idx < i:
            idx = i + m - 1
            cnt += 1
    
    return cnt
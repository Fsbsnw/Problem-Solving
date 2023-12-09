def solution(k, m, score):
    temp = 0
    cnt = 0
    score.sort(reverse=True)
    for i in score:
        cnt += 1
        if cnt == m:
            cnt = 0
            temp += i * m
    return temp
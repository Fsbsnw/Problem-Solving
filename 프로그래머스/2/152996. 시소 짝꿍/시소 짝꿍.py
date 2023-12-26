from collections import defaultdict

def solution(weights):
    weights.sort(reverse=True)
    answer = 0
    info = defaultdict(int)
    for w in weights:
        answer += info[w] + info[w*2] + info[(w*3)/2] + info[(w*4)/3]
        info[w] += 1
    return answer
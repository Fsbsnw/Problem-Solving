def solution(picks, minerals):
    mName = ["diamond", "iron", "stone"]
    result = 0
    idx = 0
    arr = []
    
    while minerals[idx:idx+5]:
        a, b, c = 0, 0, 0
        for i in minerals[idx:idx+5]:
            if i == mName[0]:
                a += 1
            elif i == mName[1]:
                b += 1
            else:
                c += 1
        arr.append((a, b, c))
        idx += 5
        
    while sum(picks) < len(arr):
        arr.pop()
        
    arr.sort(key=lambda x : (-x[0], -x[1], -x[2]))
    
    for i in arr:
        if picks[0] > 0:
            picks[0] -= 1
            result += sum(i)
        elif picks[1] > 0:
            picks[1] -= 1
            result += i[0] * 5 + sum(i) - i[0]
        else:
            picks[2] -= 1
            result += i[0] * 25 + i[1] * 5 + sum(i) - i[0] - i[1]
                        
    return result
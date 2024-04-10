import sys
input = sys.stdin.readline

n, k = map(int, input().split())
order = list(map(int, input().split()))

multitap = []
count = 0

for i in range(k):
    if order[i] in multitap:  # 이미 꽂혀있는 경우
        continue
    
    if len(multitap) < n:  # 멀티탭에 자리가 있는 경우
        multitap.append(order[i])
    else:  # 멀티탭에 자리가 없는 경우
        max_idx, max_val = -1, -1
        
        for j in range(n):
            if multitap[j] not in order[i+1:]:  # 다시 사용되지 않는 경우
                max_idx = j
                break
            
            if order[i+1:].index(multitap[j]) > max_val:  # 가장 나중에 사용되는 경우
                max_idx = j
                max_val = order[i+1:].index(multitap[j])
                
        multitap[max_idx] = order[i]
        count += 1

print(count)
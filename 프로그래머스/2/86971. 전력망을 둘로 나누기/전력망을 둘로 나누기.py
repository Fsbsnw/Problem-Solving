from collections import defaultdict

def find(parent, a):
    if parent[a] != a:
        parent[a] = find(parent, parent[a])
    return parent[a]

def union(parent, a, b):
    pa = find(parent, a)
    pb = find(parent, b)
    if pa != pb:
        parent[pa] = parent[pb]

def solution(n, wires):
    answer = int(10e9)
    for skip in range(len(wires)):
        parent = [i for i in range(n+1)]
        for idx, wire in enumerate(wires):
            if skip == idx:
                continue
            if find(parent, wire[0]) != find(parent, wire[1]):
                union(parent, wire[0], wire[1])
        
        group_value = defaultdict(int)
        for i in range(1, n+1):
            group_value[find(parent, i)] += 1
        values = list(group_value.values())
        groupA, groupB = values[0], values[1]
        answer = min(answer, abs(groupA - groupB))
             
    return answer
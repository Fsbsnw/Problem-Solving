from collections import Counter

def solution(n, wires):
    wires.sort(key = lambda x : x[0])
    
    def find(x):
        if parent[x] != x:
            return find(parent[x])
        else:
            return x

    def union(a, b):
        a = find(a)
        b = find(b)
        if a < b:
            parent[b] = a
        else:
            parent[a] = b
            
    result = n
    
    for val in wires:
        parent = [j for j in range(n + 1)]
        for wire in wires:
            if val != wire and find(wire[0]) != find(wire[1]):
                union(wire[0], wire[1])
                
        counting = []
        for i in range(1, n + 1):
            counting.append(find(i))
        counting = Counter(counting)
        counting = list(counting.values())
        result = min(result, abs(counting[0] - counting[1]))
    
    return result
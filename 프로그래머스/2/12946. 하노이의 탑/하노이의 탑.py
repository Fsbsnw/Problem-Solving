def solution(n):
    arr = []
    def recur(n, now, end, inter):
        if n == 1:
            return arr.append([now, end])
        else:
            recur(n - 1, now, inter, end)
            arr.append([now, end])
            recur(n - 1, inter, end, now)
        
    recur(n, 1, 3, 2)
    return arr
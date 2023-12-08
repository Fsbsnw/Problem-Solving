def dfs(x, y, maps, visited):
    dx = [0, 0, -1, 1]
    dy = [-1, 1, 0, 0]
    visited[x][y] = 1
    temp = int(maps[x][y])
    arr = [(x, y)]
    while arr:
        x, y = arr.pop()
        for idx in range(4):
            nx = x + dx[idx]
            ny = y + dy[idx]
            if 0 <= nx < len(maps) and 0 <= ny < len(maps[0]) and not visited[nx][ny] and maps[nx][ny] != 'X':
                arr.append((nx, ny))
                temp += int(maps[nx][ny])
                visited[nx][ny] = 1
    return temp

def solution(maps):
    visited = [[0] * len(maps[0]) for i in range(len(maps))]
    result = []
    for i in maps:
        print(i)
    
    for i in range(len(maps)):
        for j in range(len(maps[0])):
            if not visited[i][j] and maps[i][j] != 'X':
                result.append(dfs(i, j, maps, visited))
    if not result:
        result = [-1]
    return list(sorted(result))
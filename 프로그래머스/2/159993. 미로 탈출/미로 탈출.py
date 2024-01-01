dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def solution(maps):
    INF = float('inf')
    visited = [[INF] * len(maps[0]) for i in range(len(maps))]
    start = []
    lever = []
    exit = []
    for i, row in enumerate(maps):
        for j, col in enumerate(row):
            if col == 'S':
                start = [i, j]
            elif col == 'L':
                lever = [i, j]
            elif col == 'E':
                exit = [i, j]
    visited[start[0]][start[1]] = 0
    def bfs(x, y, t):
        arr = [(x, y)]
        while arr:
            cx, cy = arr.pop(0)
            for i in range(4):
                nx = dx[i] + cx
                ny = dy[i] + cy
                if 0 <= nx < len(maps) and 0 <= ny < len(maps[0]):
                    moveTo = maps[nx][ny]
                    if moveTo == t:
                        visited[nx][ny] = min(visited[nx][ny], visited[cx][cy] + 1)
                        continue
                    if moveTo != 'X' and visited[nx][ny] == INF:
                        visited[nx][ny] = min(visited[cx][cy] + 1, visited[nx][ny])
                        arr.append((nx, ny))
    bfs(start[0], start[1], "L")
    
    leverVal = visited[lever[0]][lever[1]]
    if leverVal == INF:
        return -1
    
    visited = [[INF] * len(maps[0]) for i in range(len(maps))]
    visited[lever[0]][lever[1]] = leverVal
    
    bfs(lever[0], lever[1], "E")

    if visited[exit[0]][exit[1]] == INF:
        return -1
    else:
        return visited[exit[0]][exit[1]]
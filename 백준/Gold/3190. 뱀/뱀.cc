#include <iostream>
#include <queue>

using namespace std;

#define LAND 0
#define APPLE 1

#define UP 2
#define RIGHT 3
#define DOWN 4
#define LEFT 5

int N, K, L;
int Map[101][101];
int Direction = RIGHT;
pair<int, int> Head = {1, 1};
pair<int, int> Tail = {1, 1};
queue<pair<int, char>> RotationPlan;

// 보는 방향으로 한 칸 이동
void Move(pair<int, int>& Body, int Dir)
{
    switch (Dir)
    {
        case UP:
            Body.first--;
            break;
            
        case RIGHT:
            Body.second++;
            break;
            
        case DOWN:
            Body.first++;
            break;
            
        case LEFT:
            Body.second--;
            break;
    }
}

void Rotate(int CurrentTime)
{
    if (!RotationPlan.empty())
    {
        pair<int, char> Rotation = RotationPlan.front();
        
        if (Rotation.first == CurrentTime)
        {
            if (Rotation.second == 'L')
            {
                if (Direction == UP)
                {
                    Direction = LEFT;
                }
                else
                {
                    Direction--;
                }
            }
            else
            {
                if (Direction == LEFT)
                {
                    Direction = UP;
                }
                else
                {
                    Direction++;
                }
            }
            
            RotationPlan.pop();
        }
    }
}

int main()
{
    cin >> N >> K;
    
    for (int i = 0; i < K; i++)
    {
        int x, y;
        cin >> x >> y;
        Map[x][y] = APPLE;
    }
    
    cin >> L;
    
    for (int i = 0; i < L; i++)
    {
        int Time;
        char Dir;
        cin >> Time >> Dir;
        
        RotationPlan.push({Time, Dir});
    }
    
    // 시작 뱀 위치 초기화
    Map[1][1] = Direction; // 방향 저장
    
    int Timer = 0;
    while (++Timer)
    {
        // 1. 1초마다 보는 방향으로 1칸씩 이동
        Move(Head, Direction);
        
        int x = Head.first;
        int y = Head.second;
        
        // 2-1. 이동한 위치에 벽이 있거나 몸이 있는 경우 -> 게임 종료
        if (!(0 < x && x <= N && 0 < y && y <= N)) break;
        if (Map[x][y] >= UP) break;
        
        // 2-3. 이동한 위치가 땅인 경우
        else if (Map[x][y] == LAND)
        {
            // 꼬리 제거
            int Dir = Map[Tail.first][Tail.second];
            Map[Tail.first][Tail.second] = LAND;
            Move(Tail, Dir);
        }
        
        // 3. 회전 처리
        Rotate(Timer);
        
        // 새 머리 위치에 현재 방향 저장
        Map[x][y] = Direction;
    }
    
    cout << Timer;

    return 0;
}

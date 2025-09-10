#include <iostream>
#include <vector>

using namespace std;

#define DIRECTION_TOP 0
#define DIRECTION_BOTTOM 1
#define DIRECTION_LEFT 2
#define DIRECTION_RIGHT 3

int BoardHeight, BoardWidth;
vector<vector<char>> GameBoard;
pair<int, int> HolePosition;
pair<int, int> RedBeadPosition;
pair<int, int> BlueBeadPosition;
int MinMoveCount = 11; 

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};


pair<int, int> CalculateFinalBeadPosition(pair<int, int> BeadPosition, int Direction)
{
	int CurrentX = BeadPosition.first;
	int CurrentY = BeadPosition.second;

	// 벽('#')이나 구멍('O')을 만날 때까지 해당 방향으로 계속 이동합니다.
	while (true)
	{
		CurrentX += dx[Direction];
		CurrentY += dy[Direction];

		// 보드 범위를 벗어나거나 벽을 만나면, 바로 직전 위치가 최종 위치입니다.
		if (CurrentX < 0 || CurrentX >= BoardHeight || CurrentY < 0 || CurrentY >= BoardWidth || GameBoard[CurrentX][CurrentY] == '#')
		{
			// 이동 방향의 반대로 한 칸 되돌아갑니다.
			CurrentX -= dx[Direction];
			CurrentY -= dy[Direction];
			break;
		}

		// 구멍을 만나면, 구슬이 빠져나가므로 루프를 종료합니다.
		if (GameBoard[CurrentX][CurrentY] == 'O')
		{
			break;
		}
	}
	return {CurrentX, CurrentY};
}

void SolvePuzzleRecursive(pair<int, int> CurrentRedPos, pair<int, int> CurrentBluePos, int CurrentMoveCount)
{
	// 10회를 초과하여 움직이면 실패로 간주하고 탐색을 중단합니다.
	if (CurrentMoveCount >= MinMoveCount || CurrentMoveCount > 10)
	{
		return;
	}

	// 4가지 방향(상, 하, 좌, 우)으로 기울이는 경우를 모두 탐색합니다.
	for (int Direction = 0; Direction < 4; ++Direction)
	{
		pair<int, int> NextRedPos = CalculateFinalBeadPosition(CurrentRedPos, Direction);
		pair<int, int> NextBluePos = CalculateFinalBeadPosition(CurrentBluePos, Direction);

		// 파란 구슬이 구멍에 빠진 경우, 이 경로는 실패이므로 건너뜁니다.
		if (NextBluePos == HolePosition)
		{
			continue;
		}

		// 빨간 구슬만 구멍에 빠진 경우, 성공입니다. 최소 이동 횟수를 갱신하고 탐색을 종료합니다.
		if (NextRedPos == HolePosition)
		{
			MinMoveCount = min(MinMoveCount, CurrentMoveCount + 1);
			return;
		}

		// 두 구슬의 최종 위치가 구멍이 아닌 곳에서 겹치는 경우, 위치를 조정합니다.
		if (NextRedPos == NextBluePos)
		{
			// 기울인 방향을 기준으로 원래 더 뒤에 있었던 구슬을 한 칸 뒤로 이동시킵니다.
			switch (Direction)
			{
				case DIRECTION_TOP:    CurrentRedPos.first > CurrentBluePos.first ? NextRedPos.first++ : NextBluePos.first++;       break;
				case DIRECTION_BOTTOM: CurrentRedPos.first < CurrentBluePos.first ? NextRedPos.first-- : NextBluePos.first--;       break;
				case DIRECTION_LEFT:   CurrentRedPos.second > CurrentBluePos.second ? NextRedPos.second++ : NextBluePos.second++;   break;
				case DIRECTION_RIGHT:  CurrentRedPos.second < CurrentBluePos.second ? NextRedPos.second-- : NextBluePos.second--;   break;
			}
		}

		// 현재 위치와 다음 위치가 동일하면 더 이상 탐색할 필요가 없습니다.
		if (NextRedPos == CurrentRedPos && NextBluePos == CurrentBluePos)
		{
			continue;
		}

		// 다음 상태로 재귀 호출을 진행합니다.
		SolvePuzzleRecursive(NextRedPos, NextBluePos, CurrentMoveCount + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> BoardHeight >> BoardWidth;
	GameBoard.resize(BoardHeight, vector<char>(BoardWidth));

	for (int i = 0; i < BoardHeight; i++)
	{
		for (int j = 0; j < BoardWidth; j++)
		{
			cin >> GameBoard[i][j];

			if (GameBoard[i][j] == 'B')
			{
				BlueBeadPosition = {i, j};
				GameBoard[i][j] = '.';
			}
			else if (GameBoard[i][j] == 'R')
			{
				RedBeadPosition = {i, j};
				GameBoard[i][j] = '.'; 
			}
			else if (GameBoard[i][j] == 'O')
			{
				HolePosition = {i, j};
			}
		}
	}
	
	SolvePuzzleRecursive(RedBeadPosition, BlueBeadPosition, 0);
	
	cout << ((MinMoveCount == 11) ? -1 : MinMoveCount);

	return 0;
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int RowCount, ColCount;
vector<vector<int>> Grid;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool HasRemainingCheese()
{
	for (int i = 0; i < RowCount; ++i)
	{
		for (int j = 0; j < ColCount; ++j)
		{
			if (Grid[i][j] == 1)
				return true;
		}
	}
	return false;
}

bool ShouldMeltCell(int X, int Y, const vector<vector<bool>>& Visited)
{
	int TouchingAir = 0;

	for (int Dir = 0; Dir < 4; ++Dir)
	{
		int NX = X + dx[Dir];
		int NY = Y + dy[Dir];

		if (0 <= NX && NX < RowCount &&
		        0 <= NY && NY < ColCount &&
		        Grid[NX][NY] == 0)
		{
			if (Visited[NX][NY])
				++TouchingAir;
		}
	}

	return TouchingAir >= 2;
}

void ProcessMelting()
{
	vector<pair<int, int>> MeltingCells;

	vector<vector<bool>> Visited(RowCount, vector<bool>(ColCount, false));
	queue<pair<int, int>> q;

	q.push({0, 0});
	Visited[0][0] = true;

	while (!q.empty())
	{
		auto [X, Y] = q.front();
		q.pop();

		for (int Dir = 0; Dir < 4; ++Dir)
		{
			int NX = X + dx[Dir];
			int NY = Y + dy[Dir];

			if (0 <= NX && NX < RowCount &&
			        0 <= NY && NY < ColCount &&
			        !Visited[NX][NY] &&
			        Grid[NX][NY] == 0)
			{
				Visited[NX][NY] = true;
				q.push({NX, NY});
			}
		}
	}

	for (int i = 0; i < RowCount; ++i)
	{
		for (int j = 0; j < ColCount; ++j)
		{
			if (Grid[i][j] == 1 && ShouldMeltCell(i, j, Visited))
			{
				MeltingCells.push_back({i, j});
			}
		}
	}

	for (auto& Cell : MeltingCells)
	{
		Grid[Cell.first][Cell.second] = 0;
	}
}

int main()
{
	cin >> RowCount >> ColCount;

	Grid.assign(RowCount, vector<int>(ColCount, 0));

	for (int i = 0; i < RowCount; ++i)
	{
		for (int j = 0; j < ColCount; ++j)
		{
			cin >> Grid[i][j];
		}
	}

	int Time = 0;

	while (HasRemainingCheese())
	{
		ProcessMelting();
		++Time;
	}

	cout << Time;

	return 0;
}

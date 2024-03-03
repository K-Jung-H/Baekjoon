#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int M, N, H, day;

struct Pos
{
	int x;
	int y;
	int h;
};
vector<vector<vector<int>>> tomato;
vector<vector<vector<bool>>> visited;

vector<Pos> Riped_tomato;
queue<Pos> Ripe_Q;

int dx[] = { 1, 0, -1, 0, 0, 0 };
int dy[] = { 0, 1, 0, -1, 0, 0 };
int dh[] = { 0, 0, 0, 0, -1, 1 };



bool check_boxsize(int x, int y, int h)
{
	return (x >= 0 && x < M && y >= 0 && y < N && h >= 0 && h < H && !visited[h][y][x] && tomato[h][y][x] != -1);
}

bool check_isolated(const vector<vector<vector<int>>> T)
{
	for (const vector<vector<int>> TB : T)
		for (const vector<int> v : TB)
			for (const int n : v)
				if (n == 0)
					return true;
	return false;
}

void BFS(vector<Pos> start)
{
	day = 0;
	for (const Pos pos: start)
	{
		Ripe_Q.push(pos);
		visited[pos.h][pos.y][pos.x] = true;
		tomato[pos.h][pos.y][pos.x] = 1;
	}

	while (!Ripe_Q.empty())
	{
		int size_Q = Ripe_Q.size();
		for (int q = 0; q < size_Q; q++)
		{
			int current_x = Ripe_Q.front().x;
			int current_y = Ripe_Q.front().y;
			int current_h = Ripe_Q.front().h;
			Ripe_Q.pop();
			visited[current_h][current_y][current_x] = true;
			tomato[current_h][current_y][current_x] = 1;

			for (int i = 0; i < 6; i++)
			{
				int next_x = current_x + dx[i];
				int next_y = current_y + dy[i];
				int next_h = current_h + dh[i];
				if (check_boxsize(next_x, next_y, next_h))
				{
					Ripe_Q.push({ next_x, next_y, next_h });
					visited[next_h][next_y][next_x] = true;
					tomato[next_h][next_y][next_x] = 1;
				}
			}
		}
		day++;
		//see_tomato(tomato);
	}
}
int main(void)
{
	cin >> M >> N >> H;
	tomato.resize(H, vector<vector<int>>(N, vector<int>(M, 0)));
	visited.resize(H, vector<vector<bool>>(N, vector<bool>(M, false)));
	Riped_tomato.clear();
	for (int w = 0; w < H; w++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int k = 0; k < M; k++)
			{
				cin >> tomato[w][i][k];
				if (tomato[w][i][k] == 1)
				{
					Riped_tomato.push_back({ k, i, w });
				}
			}
		}
	}

	
	BFS(Riped_tomato);
	if (check_isolated(tomato))
		cout << -1;
	else
		cout << day - 1;
}

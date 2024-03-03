#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int M, N, day;
vector<vector<int>> tomato;
vector<vector<bool>> visited;

vector<pair<int, int>> Riped_tomato;
queue<pair<int, int>> Ripe_Q;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void see_tomato(const vector<vector<int>> T)
{
	cout << "\n==============================\n";
	for (vector<int> v : T)
	{
		for (int n : v)
			cout << n << " ";
		cout << "\n";
	}
}

bool check_boxsize(int x, int y)
{
	return (x >= 0 && x < M && y >= 0 && y < N && !visited[y][x] && tomato[y][x] != -1);
}

bool check_isolated(const vector<vector<int>> T)
{
	cout << "\n==============================\n";
	for (const vector<int> v : T)
	{
		for (const int n : v)
			if (n == 0)
			{
				return true;
			}
	}
	return false;
}

void BFS(vector<pair<int,int>> start)
{
	day = 0;
	for (const pair<int,int> pos: start)
	{
		Ripe_Q.push({ pos.first, pos.second });
		visited[pos.second][pos.first] = true;
		tomato[pos.second][pos.first] = 1;
	}

	while (!Ripe_Q.empty())
	{
		int size_Q = Ripe_Q.size();
		for (int q = 0; q < size_Q; q++)
		{
			int current_x = Ripe_Q.front().first;
			int current_y = Ripe_Q.front().second;
			Ripe_Q.pop();
			visited[current_y][current_x] = true;
			tomato[current_y][current_x] = 1;

			for (int i = 0; i < 4; i++)
			{
				int next_x = current_x + dx[i];
				int next_y = current_y + dy[i];
				if (check_boxsize(next_x, next_y))
				{
					Ripe_Q.push({ next_x, next_y });
					visited[next_y][next_x] = true;
					tomato[next_y][next_x] = 1;
				}
			}
		}
		day++;
		see_tomato(tomato);
	}
}
int main(void)
{
	cin >> M >> N;
	tomato.resize(N, vector<int>(M, 0));
	visited.resize(N, vector<bool>(M, false));
	Riped_tomato.clear();
	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < M; k++)
		{
			cin >> tomato[i][k];
			if (tomato[i][k] == 1)
			{
				Riped_tomato.push_back({ k, i });
			}
		}
	}
	
	BFS(Riped_tomato);
	if (check_isolated)
	{
		cout << -1;
	}
	else
	{
		cout << day - 1;
	}
}






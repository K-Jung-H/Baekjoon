#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct State
{
    int x, y, broken_walls, distance;
};

int N, M;
vector<vector<int>> board;
vector<vector<bool>> visited_no_wall;  // 벽을 부수지 않은 상태에서의 방문 여부
vector<vector<bool>> visited_with_wall;  // 벽을 부순 상태에서의 방문 여부

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool isValid(int x, int y)
{
    return x >= 0 && x < M && y >= 0 && y < N;
}

int BFS()
{
    queue<State> q;
    q.push({ 0, 0, 0, 1 });
    visited_no_wall[0][0] = true;

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        int x = current.x;
        int y = current.y;
        int broken_walls = current.broken_walls;
        int distance = current.distance;

        if (x == M - 1 && y == N - 1)
            return distance;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isValid(nx, ny))
            {
                vector<vector<bool>>& visited = (broken_walls == 0) ? visited_no_wall : visited_with_wall;

                if (board[ny][nx] == 0 && !visited[ny][nx])
                {
                    q.push({ nx, ny, broken_walls, distance + 1 });
                    visited[ny][nx] = true;
                }
                else if (board[ny][nx] == 1 && broken_walls == 0 && !visited_with_wall[ny][nx])
                {
                    q.push({ nx, ny, 1, distance + 1 });
                    visited_with_wall[ny][nx] = true;
                }
            }
        }
    }

    return -1;
}

int main()
{
    cin >> N >> M;

    board.resize(N, vector<int>(M, 0));
    visited_no_wall.resize(N, vector<bool>(M, false));
    visited_with_wall.resize(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < M; j++)
            board[i][j] = row[j] - '0';
    }

    cout << BFS() << endl;

    return 0;
}

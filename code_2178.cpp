#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int, bool>>> maze;
vector<vector<int>> moveDistance; 

int N, M;
string temp;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void BFS(int startX, int startY)
{
    queue<pair<int, int>> to_move;
    to_move.push({ startX, startY });
    maze[startX][startY].second = true;
    moveDistance[startX][startY] = 1;

    while (!to_move.empty())
    {
        int currentX = to_move.front().first;
        int currentY = to_move.front().second;
        to_move.pop();

        if (currentX == N - 1 && currentY == M - 1) 
            break;

        for (int i = 0; i < 4; i++)
        {
            int nextX = currentX + dx[i];
            int nextY = currentY + dy[i];

            if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M &&
                maze[nextX][nextY].first == 1 && !maze[nextX][nextY].second)
            {
                to_move.push({ nextX, nextY });
                maze[nextX][nextY].second = true;
                moveDistance[nextX][nextY] = moveDistance[currentX][currentY] + 1;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;
    maze.resize(N);
    moveDistance.resize(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        for (char a : temp)
        {
            maze[i].push_back({ a - '0', false });
        }
    }

    BFS(0, 0);
    cout << moveDistance[N - 1][M - 1] << endl;

    return 0;
}


//for (int i = 0; i < N; i++)
//{
//    for (int j = 0; j < M; j++)
//    {
//        cout << moveDistance[i][j] << "  ";
//    }
//    cout << "\n";
//}
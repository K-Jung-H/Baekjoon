#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int case_num, board_size, current_x, current_y, end_x, end_y, move_num;


int move_x[] = { +1, +2, +2, +1, -1, -2, -2, -1 };
int move_y[] = { -2, -1, +1, +2, +2, +1, -1, -2 };


bool out_check(int x, int y) 
{
    return (x >= 0 && x < board_size && y >= 0 && y < board_size);
}

int BFS()
{
    move_num = 0;
    queue<pair<int, int>> Q;
    vector<vector<int>> visited(board_size, vector<int>(board_size, false));
    Q.push({ current_x, current_y });

    while (!Q.empty())
    {
        int size = Q.size();
        for (int i = 0; i < size; i++)
        {
            current_x = Q.front().first;
            current_y = Q.front().second;
            Q.pop();

            if (current_x == end_x && current_y == end_y)
                return move_num;
            visited[current_y][current_x] = true;

            for (int k = 0; k < 8; k++)
            {
                int next_xpos = move_x[k] + current_x;
                int next_ypos = move_y[k] + current_y;
                if (out_check(next_xpos, next_ypos))
                    if (!visited[next_ypos][next_xpos])
                    {
                        visited[next_ypos][next_xpos] = true;
                        Q.push({ next_xpos, next_ypos });
                    }
            }
        }
        move_num++;
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> case_num;
    for (int i = 0; i < case_num; i++)
    {
        cin >> board_size;
        cin >> current_x >> current_y;
        cin >> end_x >> end_y;
        cout << BFS() << '\n';
    }
    
    return 0;
}

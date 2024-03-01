#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> farm;
vector<vector<bool>>visited;
vector<int>answer;
int N ,Wid, Hei, M, x, y, worm_num;

void DFS(int x, int y)
{
    if (x >= Wid || x < 0 || y >= Hei || y < 0)
        return;
    else if (farm[y][x] == 0 || visited[y][x])
        return;
    else
    {
        visited[y][x] = true;
        farm[y][x] = worm_num;
        DFS(x, y - 1);
        DFS(x, y + 1);
        DFS(x - 1, y);
        DFS(x + 1, y);
        return;
    }
}

int main() 
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    for (int problem = 0; problem < N; problem++)
    {
        cin >> Wid >> Hei >> M;
        farm.clear();  visited.clear();
        farm.resize(Hei, vector<int>(Wid, 0));
        visited.resize(Hei, vector<bool>(Wid, false));
        worm_num = 1;
        for (int i = 0; i < M; i++)
        {
            cin >> x >> y; 
            farm[y][x] = 1;
        }

        for (int i = 0; i < Hei; i++)
            for (int k = 0; k < Wid; k++)
                if (visited[i][k] == false && farm[i][k] != 0)
                {
                    DFS(k, i);
                    worm_num += 1;
                }
        cout << worm_num - 1 << "\n";
    }
    return 0;
}

//for (int i = 0; i < Hei; i++)
//{
//    for (int k = 0; k < Wid; k++)
//    {
//        cout << farm[i][k] << " ";
//    }
//    cout << "\n";
//}
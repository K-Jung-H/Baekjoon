#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> village;
vector<vector<bool>>visited;
vector<int>answer;
int N;
int town_num{ 1 };

void DFS(int x, int y, int num)
{
    if (x >= N || x < 0 || y >= N || y < 0)
        return;
    else if (village[y][x] == 0 || visited[y][x])
        return;
    else
    {
        visited[y][x] = true;
        if (answer.size() != num)
            answer.push_back(1);
        else
            answer[num - 1] += 1;

        village[y][x] = num;
        DFS(x, y - 1, num);
        DFS(x, y + 1, num);
        DFS(x - 1, y, num);
        DFS(x + 1, y, num);
        
        return;
    }
}


int main() 
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    string temp;
    cin >> N;

    village.resize(N);
    visited.resize(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        for (char a : temp)
            village[i].push_back((int)(a - '0'));
    }

    for (int i = 0; i < N; i++)
        for (int k = 0; k < N; k++)
        {
            if (visited[i][k] == false && village[i][k] != 0)
            {
                DFS(k, i, town_num);
                town_num += 1;
            }
        }

    sort(answer.begin(), answer.end());
    cout << answer.size()<<"\n";
    for (int n : answer)
        cout << n << "\n";

    return 0;
}



    //cout << "x:[" << k << "]" << ", y:[" << i << "], town_num: " << town_num << '\n';
    //cout << "\n=====================\n";

    //for (int i = 0; i < N; i++)
    //{
    //    for (int k = 0; k < N; k++)
    //    {
    //        cout << village[i][k]<<" ";
    //    }
    //    cout << '\n';
    //}
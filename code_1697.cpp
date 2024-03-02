#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K;
queue<int> Q;
vector<bool> visited;

int BFS()
{
    int cnt = 0, current = N;
    visited.resize(100000, false);
    Q.push(N);
    while (!Q.empty())
    {
        int size = Q.size();
        for (int i = 0; i < size; i++)
        {
            current = Q.front();
            visited[current] = true;
            Q.pop();

            if (current == K)
                return cnt;

            if (current -1 >= 0 && !visited[current-1])
                Q.push(current - 1);
            if (current + 1 <= 100000 && !visited[current + 1])
                Q.push(current + 1);
            if (current * 2 <= 100000 && !visited[current * 2])
                Q.push(current * 2);
        }
        cnt++;
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> K;
    cout << BFS() << '\n';
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool vis[1005][1005];
int N, M;
bool isTrue = false;
vector<pair<int, int>> par = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool isValid(int ci, int cj)
{
    if (ci < 0 || ci >= N || cj < 0 || cj >= M)
    {
        return false;
    }
    return true;
}
void dfs(int sr, int sc)
{

    if (grid[sr][sc] == 'B')
    {
        isTrue = true;
        return;
    }
    vis[sr][sc] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = sr + par[i].first;
        int cj = sc + par[i].second;
        if (isValid(ci, cj) && !vis[ci][cj] && (grid[ci][cj] == '.' || grid[ci][cj] == 'B'))
        {
            dfs(ci, cj);
        }
    }
}

int main()
{
    int sr, sc;
    char ch;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> ch;
            grid[i][j] = ch;
            if (ch == 'A')
            {
                sr = i;
                sc = j;
            }
        }
    }

    memset(vis, false, sizeof(vis));

    dfs(sr, sc);
    if (isTrue)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
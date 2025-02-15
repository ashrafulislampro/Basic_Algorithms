#include <bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool vis[1005][1005];
int row, col, di, dj;
bool isTrue = false;

vector<pair<int, int>> par = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
bool isValid(int sr, int sc)
{
    if (sr < 0 || sr >= row || sc < 0 || sc >= col)
    {
        return false;
    }
    return true;
}

void dfs(int sr, int sc)
{
    if (sr == di && sc == dj)
    {
        isTrue = true;
        return;
    }
    vis[sr][sc] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = sr + par[i].first;
        int cj = sc + par[i].second;

        if (isValid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.')
        {
            dfs(ci, cj);
        }
    }
}

int main()
{

    cin >> row >> col;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> grid[i][j];
        }
    }

    memset(vis, false, sizeof(vis));

    int si, sj;
    cin >> si >> sj >> di >> dj;
    dfs(si, sj);

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
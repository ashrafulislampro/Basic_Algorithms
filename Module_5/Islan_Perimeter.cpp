#include <bits/stdc++.h>
using namespace std;
int grid[101][101];
bool vis[101][101];
int row, col;
int perimeter = 0;
vector<pair<int, int>> par = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isValid(int sr, int sc)
{
    if (sr < 0 || sr >= row || sc < 0 || sc >= col)
        return false;
    return true;
}
void dfs(int sr, int sc)
{
    vis[sr][sc] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = sr + par[i].first;
        int cj = sc + par[i].second;
        if (!isValid(ci, cj))
        {
            perimeter++;
        }
        else if (isValid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == 0)
        {
            perimeter++;
        }
        else if (isValid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == 1)
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

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == 1 && !vis[i][j])
            {
                dfs(i, j);
            }
        }
    }
    cout << perimeter << endl;
    return 0;
}
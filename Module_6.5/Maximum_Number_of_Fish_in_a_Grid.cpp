#include <bits/stdc++.h>
using namespace std;
int grid[1005][1005];
bool vis[1005][1005];
int row, col, cnt;
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
    vis[sr][sc] = true;
    cnt += grid[sr][sc];
    for (int i = 0; i < 4; i++)
    {
        int ci = sr + par[i].first;
        int cj = sc + par[i].second;

        if (isValid(ci, cj) && !vis[ci][cj] && grid[ci][cj] > 0)
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
    int catch_fists = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (!vis[i][j] && grid[i][j] > 0)
            {
                cnt = 0;
                dfs(i, j);
            }
            if (cnt > catch_fists)
            {
                catch_fists = cnt;
            }
        }
    }
    cout << catch_fists << endl;

    return 0;
}
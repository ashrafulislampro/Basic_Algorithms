#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int row, col, cnt;
    bool vis[505][505];
    vector<pair<int, int>> par = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool isValid(int sr, int sc)
    {
        return sr >= 0 && sr < row && sc >= 0 && sc < col;
    }
    bool isBoundary;
    void dfs(vector<vector<int>> &grid, int sr, int sc)
    {
        if (!isValid(sr, sc) || vis[sr][sc] || grid[sr][sc] == 0)
        {
            return;
        }
        if (sr == 0 || sr == row - 1 || sc == 0 || sc == col - 1)
        {
            isBoundary = true;
        }
        vis[sr][sc] = true;
        cnt++;
        for (int i = 0; i < 4; i++)
        {
            int ci = sr + par[i].first;
            int cj = sc + par[i].second;
            dfs(grid, ci, cj);
        }
    }

    int numEnclaves(vector<vector<int>> &grid)
    {
        row = grid.size();
        col = grid[0].size();

        memset(vis, false, sizeof(vis));

        int count = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (!vis[i][j] && grid[i][j] != 0)
                {
                    cnt = 0;
                    isBoundary = false;
                    dfs(grid, i, j);

                    if (!isBoundary)
                        count += cnt;
                }
            }
        }

        return count;
    }
};
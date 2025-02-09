#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int row, col;
    bool vis[55][55];
    vector<pair<int, int>> par = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int max_island = 0;
    int cnt = 0;
    bool isValid(int si, int sc)
    {
        if (si < 0 || si >= row || sc < 0 || sc >= col)
        {
            return false;
        }
        return true;
    }

    void dfs(int sr, int sc, vector<vector<int>> &grid)
    {

        vis[sr][sc] = true;
        cnt++;
        for (int i = 0; i < 4; i++)
        {
            int ci = sr + par[i].first;
            int cj = sc + par[i].second;

            if (isValid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == 1)
            {
                dfs(ci, cj, grid);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        row = grid.size();
        col = grid[0].size();
        memset(vis, false, sizeof(vis));
        for (int i = 0; i < row; i++)
        {

            for (int j = 0; j < col; j++)
            {

                if (!vis[i][j] && grid[i][j] == 1)
                {
                    cnt = 0;
                    dfs(i, j, grid);
                    if (cnt > max_island)
                    {
                        max_island = cnt;
                    }
                }
            }
        }

        return max_island;
    }
};
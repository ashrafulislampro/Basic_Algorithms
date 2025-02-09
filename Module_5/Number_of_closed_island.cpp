#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int row, col;
    bool vis[305][305];
    bool flag;
    vector<pair<int, int>> par = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

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

        for (int i = 0; i < 4; i++)
        {
            int ci = sr + par[i].first;
            int cj = sc + par[i].second;
            if (!isValid(ci, cj))
            {
                flag = false;
            }
            if (isValid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == 0)
            {
                dfs(ci, cj, grid);
            }
        }
    }
    int closedIsland(vector<vector<int>> &grid)
    {
        row = grid.size();
        col = grid[0].size();
        int cnt = 0;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (!vis[i][j] && grid[i][j] == 0)
                {
                    flag = true;
                    dfs(i, j, grid);
                    if (flag)
                        cnt++;
                }
            }
        }
        return cnt;
    }
};
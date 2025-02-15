#include <bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool vis[1005][1005];
pair<int, int> parent[1005][1005];

vector<pair<int, int>> mov = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int row, col, item = 0;
bool isValid(int sr, int sc)
{
    if (sr < 0 || sr >= row || sc < 0 || sc >= col)
    {
        return false;
    }
    return true;
}
void bfs(int sr, int sc)
{
    queue<pair<int, int>> q;
    q.push({sr, sc});
    vis[sr][sc] = true;
    while (!q.empty())
    {
        auto par = q.front();
        q.pop();

        int src_i = par.first;
        int src_j = par.second;
        for (int i = 0; i < 4; i++)
        {
            int ci = src_i + mov[i].first;
            int cj = src_j + mov[i].second;

            if (isValid(ci, cj) && !vis[ci][cj] && (grid[ci][cj] == '.' || grid[ci][cj] == 'R' || grid[ci][cj] == 'D'))
            {

                q.push({ci, cj});
                vis[ci][cj] = true;
                parent[ci][cj] = {src_i, src_j};
            }
        }
    }
}
int main()
{
    int si = 0, sj = 0, di = 0, dj = 0;
    cin >> row >> col;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> grid[i][j];
            parent[i][j] = {-1, -1};
            if (grid[i][j] == 'R')
            {
                si = i;
                sj = j;
            }
            if (grid[i][j] == 'D')
            {
                di = i;
                dj = j;
            }
        }
    }
    memset(vis, false, sizeof(vis));
    // memset(parent, -1, sizeof(parent));
    bfs(si, sj);

    int x = di, y = dj;

    while (1)
    {
        auto par = parent[x][y];
        x = par.first;
        y = par.second;

        if ((x == -1 && y == -1) || grid[x][y] == 'R')
        {
            break;
        }
        grid[x][y] = 'X';
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << grid[i][j];
        }

        cout << endl;
    }

    return 0;
}
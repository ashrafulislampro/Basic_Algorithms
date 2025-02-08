#include <bits/stdc++.h>
using namespace std;
int row, col;
char grid[105][105];
bool vis[105][105];
int level[105][105];

vector<pair<int, int>> child = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isValid(int ci, int cj)
{

    if (ci < 0 || ci >= row || cj < 0 || cj >= col)
    {

        return false;
    }

    return true;
}
void bfs(int si, int sj)
{

    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    level[si][sj] = 0;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();

        int par_i = par.first;
        int par_j = par.second;

        for (int i = 0; i < 4; i++)
        {
            int ci = par_i + child[i].first;
            int cj = par_j + child[i].second;
            if (!vis[ci][cj] && isValid(ci, cj) && grid[ci][cj] == '.')
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1;
            }
        }
    }
}

int main()
{
    row, col;
    cin >> row >> col;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> grid[i][j];
        }
    }

    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));

    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;
    bfs(si, sj);
    cout << level[di][dj] << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
char grid[35][35];
bool vis[35][35];
int level[35][35];

vector< pair<int, int> > mov;
int n;

bool isValid(int sr, int sc)
{
    return sr >= 0 && sr < n && sc >= 0 && sc < n;
}
void bfs(int sr, int sc)
{
    queue< pair<int, int> > q;
    q.push({sr, sc});
    vis[sr][sc] = true;
    level[sr][sc] = 0;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();

        int src_i = par.first;
        int src_j = par.second;

        for (int i = 0; i < 4; i++)
        {
            int chd_i = src_i + mov[i].first;
            int chd_j = src_j + mov[i].second;

            if (isValid(chd_i, chd_j) && !vis[chd_i][chd_j] && (grid[chd_i][chd_j] == 'S' || grid[chd_i][chd_j] == 'P' || grid[chd_i][chd_j] == 'E'))
            {
                q.push({chd_i, chd_j});
                vis[chd_i][chd_j] = true;
                level[chd_i][chd_j] = level[src_i][src_j] + 1;
            }
        }
    }
}
int main()
{

    while (cin >> n)
    {
        mov.push_back({1, 0});
        mov.push_back({-1, 0});
        mov.push_back({0, 1});
        mov.push_back({0, -1});
        int si = 0, sj = 0, di = 0, dj = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];

                if (grid[i][j] == 'S')
                {
                    si = i;
                    sj = j;
                }
                if (grid[i][j] == 'E')
                {
                    di = i;
                    dj = j;
                }
            }
        }

        memset(vis, false, sizeof(vis));
        memset(level, -1, sizeof(level));
        bfs(si, sj);

        cout << level[di][dj] << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int grid[105][105];
bool vis[105][105];
int level[105][105];
int row, col;
vector<pair<int, int>> mov = {{2, 1}, {2, -1}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {-1, -2}, {1, -2}};
bool isValid(int sr, int sc){
    if(sr < 0 || sr >= row || sc < 0 || sc >= col){
        return false;
    }
    return true;
}
void bfs(int sr, int sc){
    queue<pair<int, int>> q;
    q.push({sr, sc});
    vis[sr][sc] = true;
    level[sr][sc] = 0;
    while(!q.empty()){
        auto par = q.front();
        q.pop();

        int src_i = par.first;
        int src_j = par.second;
        for(int i = 0; i < 8; i++){
            int ch_i = src_i + mov[i].first;
            int ch_j = src_j + mov[i].second;

            if(isValid(ch_i, ch_j) && !vis[ch_i][ch_j]){
                q.push({ch_i, ch_j});
                vis[ch_i][ch_j] = true;
                level[ch_i][ch_j] = level[src_i][src_j] + 1;
            }
        }

    }
}





int main()
{
    int t, ki, kj, qi, qj;
    cin >> t;
    while (t--)
    {
        cin >> row >> col >> ki >> kj >> qi >> qj;
        memset(vis, false, sizeof(vis));
        memset(level, -1, sizeof(level));

        bfs(ki, kj);
        cout<<level[qi][qj]<<endl;

    }
    return 0;
}
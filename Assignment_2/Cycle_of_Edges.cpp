#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[100005];
int parent[100005];
bool vis[100005];
int cycle_cnt;

void dfs(int src)
{
    vis[src] = true;
    for (int child : adj_list[src])
    {
        if (vis[child] && parent[src] != child)
        {
            cycle_cnt++;
        }
        if (!vis[child])
        {
            parent[child] = src;
            dfs(child);
        }
    }
};
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));

    cycle_cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }

    cout << cycle_cnt / 2 << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[200005];
bool vis[200005];
void dfs(int src)
{
    vis[src] = true;

    for (int child : adj_list[src])
    {
        if (!vis[child])
        {
            dfs(child);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    vector<int> roads;
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            roads.push_back(i);
            dfs(i);
        }
    }

    cout << roads.size() - 1 << endl;
    for (int i = 0; i < roads.size() - 1; i++)
    {
        cout << roads[i] << " " << roads[i + 1] << endl;
    }

    return 0;
}
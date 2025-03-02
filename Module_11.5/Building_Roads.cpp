#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[100005];
bool vis[100005];
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
    vector<int> roads;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            roads.push_back(i);
            dfs(i);
        }
    }
    int len = roads.size();
    cout << len - 1 << endl;
    for (int i = 0; i < len - 1; i++)
    {
        cout << roads[i] << " " << roads[i + 1] << endl;
    }
    return 0;
}

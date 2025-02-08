#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool vis[1005];
int item = 0;
void dfs(int src)
{
    item++;
    vis[src] = true;
    for (int child : adj_list[src])
    {
        if (!vis[child])
            dfs(child);
    }
}
int main()
{
    int v, e;
    cin >> v >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    int src;
    cin >> src;
    dfs(src);
    cout << item << endl;
    return 0;
}

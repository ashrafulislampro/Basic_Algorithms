#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool vis[1005];
int node = 0;
void dfs(int src)
{
    node++;
    vis[src] = true;
    for (int child : adj_list[src])
    {
        if(child != -1 && !vis[child])
            dfs(child);
    }
};

int main()
{
    int v, e;
    cin >> v >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        if (b == -1)
        {
            adj_list[a].push_back(b);
        }
        else
        {
            adj_list[a].push_back(b);
            adj_list[b].push_back(a);
        }
    }

    memset(vis, false, sizeof(vis));

    vector<int> total_node;

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            node = 0;
            dfs(i);
            total_node.push_back(node);
        }
    }
    
    sort(total_node.begin(), total_node.end());

    for (int val : total_node)
    {
        cout << val << " ";
    }

    return 0;
}
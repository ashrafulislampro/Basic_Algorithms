#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool vis[1005];
void dfs(int src)
{

    vis[src] = true;
    for (int child : adj_list[src])
    {

        if (child != -1 && !vis[child])
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
    int count = 0;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i);

            count++;
        }
    }

    cout << count << endl;

    return 0;
}
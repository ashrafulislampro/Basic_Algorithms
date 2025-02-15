#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[100005];
bool vis[100005];
int level[100005];
int parent[100005];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    q.push(2);  // path manipulate
    vis[src] = true;
    level[src] = 0;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (int ch : adj_list[par])
        {
            if (!vis[ch])
            {

                q.push(ch);
                vis[ch] = true;
                level[ch] = level[par] + 1;
                parent[ch] = par;
            }
        }
    }
};

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

    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));

    int src, dst;
    cin >> src >> dst;
    bfs(src);

    vector<int> path;
    int node = dst;
    while (node != -1)
    {
        path.push_back(node);
        node = parent[node];
    }
    reverse(path.begin(), path.end());

    if (!vis[dst])
    {

        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    cout << path.size() << endl;
    for (int x : path)
    {
        cout << x << " ";
    }

    return 0;
}
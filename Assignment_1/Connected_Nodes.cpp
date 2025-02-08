#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1000001];
bool vis[1000001];
vector<int> total_node;

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

    int q, node;
    cin >> q;

    while (q--)
    {
        cin >> node;
        vector<int> nodes;
        for (int child : adj_list[node])
        {
            nodes.push_back(child);
        }
        sort(nodes.begin(), nodes.end(), greater<int>());
        int len = nodes.size();
        if (len > 0)
        {
            for (int x : nodes)
            {
                cout << x << " ";
            }
            cout << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
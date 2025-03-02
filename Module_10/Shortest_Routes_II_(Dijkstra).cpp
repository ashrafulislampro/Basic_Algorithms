#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adj_list[505];
int dis[505];
void dijkstra(int src, int dst)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, src});
    dis[src] = 0;
    while (!pq.empty())
    {
        auto par = pq.top();
        pq.pop();

        int par_node = par.second;
        int par_dis = par.first;

        for (auto child : adj_list[par_node])
        {
            int child_node = child.first;
            int child_dis = child.second;
            if (par_dis + child_dis < dis[child_node])
            {
                dis[child_node] = par_dis + child_dis;
                pq.push({dis[child_node], child_node});
            }
        }
    }

    
    if (dis[dst] != INT_MAX)
    {
        cout << dis[dst] << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}
int main()
{
    int v, e, q;
    cin >> v >> e >> q;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});
    }
    int a, b;
    while (q--)
    {
        for (int i = 0; i <= v; i++)
        {
            dis[i] = INT_MAX;
        }
        cin >> a >> b;
        dis[a] = 0;
        dijkstra(a, b);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<int, ll>> adj_list[100005];
ll dis[100005];
ll parent[100005];

void dijkstra(int src)
{
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    pq.push({0, src});
    dis[src] = 0;
    parent[src] = -1;

    while (!pq.empty())
    {
        auto par = pq.top();
        pq.pop();

        int par_node = par.second;
        ll par_dis = par.first;

        for (auto child : adj_list[par_node])
        {
            int child_node = child.first;
            int child_dis = child.second;

            if (par_dis + child_dis < dis[child_node])
            {
                dis[child_node] = par_dis + child_dis;
                parent[child_node] = par_node;
                pq.push({dis[child_node], child_node});
            }
        }
    }
};
void pathPrint(int dst)
{
    vector<int> path;
    for (int v = dst; v != -1; v = parent[v])
    {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    for (int ch : path)
    {
        cout << ch << " ";
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = LLONG_MAX;
        parent[i] = -1;
    }
    dijkstra(1);

    if (dis[n] == LLONG_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        pathPrint(n);
    }
    return 0;
}
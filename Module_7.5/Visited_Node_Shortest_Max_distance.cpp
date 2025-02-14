#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dis[105];
    bool vis[105];
    vector<pair<int, int>> adj_list[105];
    void Dijkstra(int src)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        dis[src] = 0;
        vis[src] = true;
        while (!pq.empty())
        {
            auto par = pq.top();
            pq.pop();
            int par_dis = par.first;
            int par_node = par.second;
            for (auto child : adj_list[par_node])
            {
                int child_node = child.first;
                int child_dis = child.second;
                vis[child_node] = true;
                if (par_dis + child_dis < dis[child_node])
                {

                    dis[child_node] = par_dis + child_dis;

                    pq.push({dis[child_node], child_node});
                }
            }
        }
    };
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        for (auto child : times)
        {
            int a = child[0];
            int b = child[1];
            int c = child[2];
            adj_list[a].push_back({b, c});
        }

        for (int i = 1; i <= n; i++)
        {
            dis[i] = INT_MAX;
        }
        memset(vis, false, sizeof(vis));
        Dijkstra(k);
        int max_v = -1;
        for (int i = 1; i <= n; i++)
        {
            if (dis[i] > max_v && dis[i] != 0 && dis[i] != INT_MAX)
            {
                max_v = dis[i];
            };
        }
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                max_v = -1;
            }
        }
        return max_v;
    }
};
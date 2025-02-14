//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User Function Template
class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    int dis[1005];

    void Dijkstra(int src, vector<vector<pair<int, int>>> adj)
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

            for (auto child : adj[par_node])
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
    }
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src)
    {
        // Code here
        for (int i = 0; i < 1005; i++)
        {
            dis[i] = INT_MAX;
        }
        Dijkstra(src, adj);
        vector<int> res;
        int len = adj.size(); // find the all the vertices
        for (int i = 0; i < len; i++)
        {
            res.push_back(dis[i]);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to detect cycle in an undirected graph.
    bool vis[100005];
    int parent[100005];
    bool cycle;
    void dfs(int src, vector<vector<int>> &adj)
    {
        vis[src] = true;
        for (int child : adj[src])
        {
            if (vis[child] && parent[src] != child)
            {
                cycle = true;
            }
            if (!vis[child])
            {
                parent[child] = src;
                dfs(child, adj);
            }
        }
    }
    bool isCycle(vector<vector<int>> &adj)
    {
        // Code here
        memset(vis, false, sizeof(vis));
        memset(parent, -1, sizeof(parent));
        cycle = false;
        for (int i = 0; i < adj.size(); i++)
        {
            if (!vis[i])
            {
                dfs(i, adj);
            }
        }
        return (cycle ? 1 : 0);
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
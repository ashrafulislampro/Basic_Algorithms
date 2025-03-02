#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[100005];
bool vis[100005];
int cnt;
void dfs(int src)
{
    cnt++;
    vis[src] = true;
    for (int child : adj_list[src])
    {
        if (!vis[child])
        {

            dfs(child);
        }
    }
}
int main()
{
    int n, e, a, b;
    cin >> n >> e;

    int count = 0, comp = 0;
    vector<pair<int, int>> linePar;
    while (e--)
    {
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
        memset(vis, false, sizeof(vis));
        comp = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                cnt = 0;
                dfs(i);
                comp++;
                if (cnt > count)
                {
                    count = cnt;
                }
            }
        }
        linePar.push_back({comp, count});
    }

    for (auto ch : linePar)
    {
        cout << ch.first << " " << ch.second << endl;
    }
    return 0;
}

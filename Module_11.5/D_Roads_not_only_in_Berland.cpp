#include <bits/stdc++.h>
using namespace std;
int par[1005];
int grp_size[1005];
int find_led(int node)
{
    if (par[node] == -1)
    {
        return node;
    }
    int leader = find_led(par[node]);
    par[node] = leader;
    return leader;
}
void dsu_union(int node1, int node2)
{
    int leader1 = find_led(node1);
    int leader2 = find_led(node2);

    if (grp_size[leader1] >= grp_size[leader2])
    {
        par[leader2] = leader1;
        grp_size[leader1] += grp_size[leader2];
    }
    else
    {
        par[leader1] = leader2;
        grp_size[leader2] += grp_size[leader1];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        par[i] = -1;
        grp_size[i] = 1;
    }

    vector<pair<int, int>> rmv;
    vector<pair<int, int>> crt;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        int leader1 = find_led(a);
        int leader2 = find_led(b);
        if (leader1 == leader2)
        {
            rmv.push_back({a, b});
        }
        else
        {
            dsu_union(a, b);
        }
    }

    for (int i = 2; i <= n; i++)
    {
        int leader1 = find_led(1);
        int leader2 = find_led(i);
        if (leader1 != leader2)
        {
            crt.push_back({1, i});
            dsu_union(1, i);
        }
    }
    cout<<rmv.size()<<endl;
    for (int i = 0; i < rmv.size(); i++)
    {
        cout << rmv[i].first << " " << rmv[i].second << " " << crt[i].first << " " << crt[i].second << endl;
    }
    return 0;
}
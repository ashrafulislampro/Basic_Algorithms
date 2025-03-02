#include <bits/stdc++.h>
using namespace std;
int parent[100005];
int grp_size[100005];
int cmp, mx;
int find(int node)
{
    if (parent[node] == -1)
    {
        return node;
    }
    int leader = find(parent[node]);
    parent[node] = leader;
    return leader;
}

void set_union(int node1, int node2)
{
    int leader1 = find(node1);
    int leader2 = find(node2);
    if (leader1 == leader2)
    {
        return;
    }
    if (grp_size[leader1] >= grp_size[leader2])
    {
        parent[leader2] = leader1;
        grp_size[leader1] += grp_size[leader2];
        mx = max(mx, grp_size[leader1]);
    }
    else
    {
        parent[leader1] = leader2;
        grp_size[leader2] += grp_size[leader1];
        mx = max(mx, grp_size[leader2]);
    }
    cmp--;
}

int main()
{
    int n, e;
    cin >> n >> e;
    cmp = n;
    mx = 1;

    // memset(parent, -1, sizeof(parent));
    // memset(grp_size, 1, sizeof(grp_size));
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        grp_size[i] = 1;
    }

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        set_union(a, b);
        cout << cmp << " " << mx << endl;
    }

    return 0;
}
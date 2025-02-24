#include <bits/stdc++.h>
using namespace std;
class Edges
{
public:
    int a, b, c;
    Edges(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};
vector<Edges> edges_list;
int dis[505];
int v, e, q;

void bellman_ford(int src, int dst)
{
    for (int i = 0; i < v - 1; i++)
    {
        for (auto ed : edges_list)
        {
            int a, b, c;
            a = ed.a;
            b = ed.b;
            c = ed.c;
            if (dis[a] != INT_MAX && dis[a] + c < dis[b])
            {
                dis[b] = dis[a] + c;
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
};
int main()
{

    cin >> v >> e >> q;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges_list.push_back(Edges(a, b, c));
        edges_list.push_back(Edges(b, a, c));
    }

    int a, b;
    while (q--)
    {

        cin >> a >> b;
        for (int i = 1; i <= v; i++)
        {
            dis[i] = INT_MAX;
        }
        dis[a] = 0;
        bellman_ford(a, b);
    }

    return 0;
}
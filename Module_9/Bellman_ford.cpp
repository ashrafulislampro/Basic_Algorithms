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
int dis[1005];
vector<Edges> edges_list;
int v, e;
void bellman_ford()
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
    bool cycle = false;
    for (auto ed : edges_list)
    {
        int a, b, c;
        a = ed.a;
        b = ed.b;
        c = ed.c;
        if (dis[a] != INT_MAX && dis[a] + c < dis[b])
        {
            cycle = true;
            break;
        }
    }

    if (cycle)
    {
        cout << "Negative weighted cycle detect" << endl;
    }
    else
    {
        for (int i = 0; i < v; i++)
        {
            cout << i << " -> " << dis[i] << endl;
        }
    }
}
int main()
{

    cin >> v >> e;

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges_list.push_back(Edges(a, b, c));
        // edges_list.push_back(Edges(b, a, c)); // undirected
    }
    for (int i = 0; i < v; i++)
    {
        dis[i] = INT_MAX;
    }
    dis[0] = 0;
    bellman_ford();

    return 0;
}

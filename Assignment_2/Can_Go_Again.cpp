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
long long dis[1005];
bool cycle;
int n, e;

void bellman_ford()
{
    for (int i = 1; i <= n - 1; i++)
    {
        for (auto ed : edges_list)
        {
            int a, b, c;
            a = ed.a;
            b = ed.b;
            c = ed.c;

            if (dis[a] != LLONG_MAX && dis[a] + c < dis[b])
            {
                dis[b] = dis[a] + c;
            }
        }
    }
    cycle = false;
    for (auto ed : edges_list)
    {
        int a, b, c;
        a = ed.a;
        b = ed.b;
        c = ed.c;

        if (dis[a] != LLONG_MAX && dis[a] + c < dis[b])
        {
            cycle = true;
            break;
        }
    }

    
};
int main()
{

    cin >> n >> e;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges_list.push_back(Edges(a, b, c));
    }

    for (int i = 1; i <= n; i++)
    {
        dis[i] = LLONG_MAX;
    }
    int src, q, dst;
    cin >> src >> q;
    dis[src] = 0;
    cycle = false;
    bellman_ford();

    if (cycle)
    {
        cout << "Negative Cycle Detected";
    }
    else
    {
        while (q--)
        {
            cin >> dst;
            if (dis[dst] == LLONG_MAX)
            {
                cout << "Not Possible" << endl;
            }
            else
            {
                cout << dis[dst] << endl;
            }
        }
    }
    return 0;
}
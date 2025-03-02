#include <bits/stdc++.h>
using namespace std;

long long adj_mat[105][105];
int n, e;
void floyd_warshall()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (adj_mat[i][k] == LLONG_MAX || adj_mat[k][j] == LLONG_MAX)
                {
                    continue;
                }
                if (adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j])
                {
                    adj_mat[i][j] = min(adj_mat[i][j], adj_mat[i][k] + adj_mat[k][j]);
                }
            }
        }
    }
};
int main()
{
    cin >> n >> e;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                adj_mat[i][j] = 0;
            }
            else
            {
                adj_mat[i][j] = LLONG_MAX;
            }
        }
    }

    while (e--)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        adj_mat[a][b] = min(adj_mat[a][b], c);
    }

    floyd_warshall();
    long long q, a, b;
    cin >> q;
    while (q--)
    {
        cin >> a >> b;
        if (adj_mat[a][b] == LLONG_MAX)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << adj_mat[a][b] << endl;
        }
    }
    return 0;
}
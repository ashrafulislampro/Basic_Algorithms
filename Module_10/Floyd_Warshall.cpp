#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v, e;
    cin >> v >> e;
    int adj_matrix[v][v];
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (i == j)
            {
                adj_matrix[i][j] = 0;
            }
            else
            {
                adj_matrix[i][j] = INT_MAX;
            }
        }
    }

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_matrix[a][b] = c;
        // adj_matrix[b][a] = c;  // undirected
    }

    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (adj_matrix[i][k] != INT_MAX && adj_matrix[k][j] != INT_MAX && adj_matrix[i][k] + adj_matrix[k][j] < adj_matrix[i][j])
                {
                    adj_matrix[i][j] = adj_matrix[i][k] + adj_matrix[k][j];
                }
            }
        }
    }

    bool cycle = false;
    for (int i = 0; i < v; i++)
    {
        if (adj_matrix[i][i] < 0)
        {
            cycle = true;
        }
    }
    if (cycle)
    {
        cout << "Negative Weighted cycle is detected" << endl;
    }
    else
    {

        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (adj_matrix[i][j] == INT_MAX)
                {
                    cout << "INF ";
                }
                else
                {
                    cout << adj_matrix[i][j] << " ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}
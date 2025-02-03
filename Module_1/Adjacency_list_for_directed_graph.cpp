#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    // int arr[n];
    vector<int> adj_list[n]; // array of vector;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj_list[a].push_back(b);
    }

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " -> ";
        for (int x : adj_list[i])
        {
            cout << x + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}
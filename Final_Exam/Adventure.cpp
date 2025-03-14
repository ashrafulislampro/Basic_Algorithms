#include <bits/stdc++.h>
using namespace std;
int values[1005], weight[1005];
int dp[1005][1005];

int knapsack(int n, int mx_w)
{
    if (n < 0 || mx_w <= 0)
    {
        return 0;
    }
    if (dp[n][mx_w] != -1)
    {
        return dp[n][mx_w];
    }

    if (weight[n] <= mx_w)
    {
        int opt1 = values[n] + knapsack(n - 1, mx_w - weight[n]);
        int opt2 = knapsack(n - 1, mx_w);
        dp[n][mx_w] = max(opt1, opt2);
        return dp[n][mx_w];
    }
    else
    {
        dp[n][mx_w] = knapsack(n - 1, mx_w);
        return dp[n][mx_w];
    }
}
int main()
{
    int t, N, mx_w;
    cin >> t;
    while (t--)
    {

        cin >> N >> mx_w;
        for (int i = 0; i < N; i++)
        {
            cin >> weight[i];
        }
        for (int i = 0; i < N; i++)
        {
            cin >> values[i];
        }
        for (int i = 0; i <= N; i++)
        {
            for (int j = 0; j <= mx_w; j++)
            {
                dp[i][j] = -1;
            }
        }
        cout << knapsack(N - 1, mx_w) << endl;
    }
    return 0;
}
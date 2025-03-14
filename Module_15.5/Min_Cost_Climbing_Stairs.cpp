#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[1005];
    int rec(vector<int> &cost, int n)
    {
        if (n <= 0)
        {
            return 0;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        int opt1 = rec(cost, n - 1) + cost[n];
        int opt2 = rec(cost, n - 2) + cost[n - 1];
        dp[n] = min(opt1, opt2);
        // cout<<"opt1 "<<opt1<<" opt2 "<<opt2<< " " <<dp[n]<<endl;
        return dp[n];
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        memset(dp, -1, sizeof(dp));
        int n = cost.size();

        return rec(cost, n - 1);
    }
};
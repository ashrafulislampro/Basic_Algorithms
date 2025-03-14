#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[40];
    int tribo(int n)
    {
        if (n <= 1)
        {
            return n;
        }
        if (n == 2)
        {
            return 1;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        dp[n] = tribo(n - 1) + tribo(n - 2) + tribo(n - 3);
        return dp[n];
    }
    int tribonacci(int n)
    {
        memset(dp, -1, sizeof(dp));
        return tribo(n);
    }
};
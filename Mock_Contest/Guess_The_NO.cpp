#include <bits/stdc++.h>
using namespace std;
long long t;
vector<long long> dp(t + 10, false);

bool rec(long long n)
{
    if (n == t)
    {
        return true;
    }
    if (n > t)
    {
        return false;
    }
    if (dp[n])
    {
        return dp[n];
    }
    dp[n] = rec(n + 3) || rec(n + 4);
    return dp[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> t;

    if (rec(0))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}

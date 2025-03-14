#include <bits/stdc++.h>
using namespace std;
// long long dp[100005];
unordered_map<long long, bool> dp;
long long input;
bool rec(long long n)
{
    if (n == input)
        return true;
    if (n > input)
        return false;
    if (dp.find(n) != dp.end())
        return dp[n];

    dp[n] = rec(n + 3) || rec(n * 2);
    return dp[n];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        cin >> input;

        dp.clear(); 

        if (rec(1) || input == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}

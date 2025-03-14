#include <bits/stdc++.h>
using namespace std;

long long rec(string S, string t)
{
    vector<long long> dp(4, 0);
    for (char c : S)
    {
        if (c == t[2])
            dp[3] += dp[2];
        if (c == t[1])
            dp[2] += dp[1];
        if (c == t[0])
            dp[1]++;
    }
    return dp[3];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        string S, t;
        cin >> S >> t;
        cout << rec(S, t) << '\n';
    }
    return 0;
}

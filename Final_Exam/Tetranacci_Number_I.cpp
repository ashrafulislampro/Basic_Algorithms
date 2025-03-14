#include <bits/stdc++.h>
using namespace std;
int dp[35];
int tetranacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    if (n == 2 || n == 3)
    {
        return n - 1;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n] = tetranacci(n - 1) + tetranacci(n - 2) + tetranacci(n - 3) + tetranacci(n - 4);
    return dp[n];
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    cout << tetranacci(n) << endl;
    return 0;
}
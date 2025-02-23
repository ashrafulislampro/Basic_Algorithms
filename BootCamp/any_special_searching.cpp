#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, num;
    cin >> n;
    long long prefix_sum[n + 5];
    prefix_sum[0] = {0};
    for (int i = 1; i <= n; i++)
    {
        cin >> num;
        prefix_sum[i] = prefix_sum[i - 1] + num;
    }
    int q;
    cin >> q;

    while (q--)
    {
        cin >> num;
        bool isTrue = true;
        for (int i = 1; i <= n; i++)
        {

            if (prefix_sum[i] >= num)
            {
                cout << i << "\n";
                isTrue = false;
                break;
            };
        }
        if (isTrue)
            cout << -1 << "\n";
    }

    return 0;
}
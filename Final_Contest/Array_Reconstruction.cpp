#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        vector<long long> arr(n, 0);

        for (int i = 0; i < n - 2; i++)
        {
            cin >> arr[i];
            if(i > 0){
                arr[i] += arr[i - 1];
            }
        }
        long long sum;
        cin >> sum;
        cout << (sum - arr[n - 3]) + 1 << endl;
    }

    return 0;
}
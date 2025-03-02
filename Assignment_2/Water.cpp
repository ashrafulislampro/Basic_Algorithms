#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, num, f_height, s_height;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> arr(n);
        vector<int> tmp(n);
        for (int i = 0; i < n; i++)
        {
            cin >> num;
            arr[i] = num;
            tmp[i] = num;
        }
        sort(tmp.begin(), tmp.end());

        int f_idx, s_idx;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == tmp[n - 1])
            {
                f_idx = i;
            }
            else if (arr[i] == tmp[n - 2])
            {
                s_idx = i;
            }
        }

        cout << min(f_idx, s_idx) << " " << max(f_idx, s_idx) << endl;
    }

    return 0;
}
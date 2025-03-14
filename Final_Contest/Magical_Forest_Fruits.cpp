#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q, L, R;
    cin >> N >> Q;
    vector<long long> arr(N + 5, 0);

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        arr[i] = arr[i] + arr[i - 1];
    }

    while (Q--)
    {
        cin >> L >> R;
        cout << arr[R] - arr[L - 1] << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        string str, result;
        cin >> str;

        for (int i = 1; i < str.size(); i++)
            if (isdigit(str[i]) && str[i] != '0')
                result.append(str[i] - '0', str[i - 1]);

        cout << result << endl;
    }

    return 0;
}

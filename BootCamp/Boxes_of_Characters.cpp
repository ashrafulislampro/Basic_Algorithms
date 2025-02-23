#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    int t, cons, vowl, dig;
    cin >> t;
    while (t--)
    {
        cons = 0, vowl = 0, dig = 0;
        cin >> str;
        for (int i = 0; i < str.size(); i++)
        {
            if (isdigit(str[i]))
            {
                dig++;
            }
            else if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
            {
                vowl++;
            }
            else if (isalpha(str[i]))
            {
                cons++;
            }
        }

        cons = ceil(cons / 3.0);
        vowl = ceil(vowl / 2.0);
        cout << max(cons, max(vowl, dig)) << endl;
    }
    return 0;
}
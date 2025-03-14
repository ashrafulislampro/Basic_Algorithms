#include <bits/stdc++.h>
using namespace std;
void rec(int num)
{
    if (num <= 0)
    {
        return;
    }
    int rem = num % 10;
    rec(num / 10);
    cout << rem << " ";
}
int main()
{
    int n, num;
    cin >> n;
    while (n--)
    {
        cin >> num;
        if (num > 0)
        {
            rec(num);
        }
        else
        {
            cout << 0;
        }
        cout << endl;
    }

    return 0;
}